#include "scalar.h"

static const crypto_uint32 m[32] = {0xED, 0xD3, 0xF5, 0x5C, 0x1A, 0x63, 0x12, 0x58, 0xD6, 0x9C, 0xF7, 0xA2, 0xDE, 0xF9, 0xDE, 0x14, 
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10};

static const crypto_uint32 mu[33] = {0x1B, 0x13, 0x2C, 0x0A, 0xA3, 0xE5, 0x9C, 0xED, 0xA7, 0x29, 0x63, 0x08, 0x5D, 0x21, 0x06, 0x21, 
                                     0xEB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F};

static crypto_uint32 lt(crypto_uint32 a,crypto_uint32 b) /* 16-bit inputs */
{
  unsigned int x = a;
  x -= (unsigned int) b; /* 0..65535: no; 4294901761..4294967295: yes */
  x >>= 31; /* 0: no; 1: yes */
  return x;
}

/* Reduce coefficients of r before calling reduce_add_sub */
static void reduce_add_sub(group_scalar *r)
{
  crypto_uint32 pb = 0;
  crypto_uint32 b;
  crypto_uint32 mask;
  int i;
  unsigned char t[32];

  for(i=0;i<32;i++) 
  {
    pb += m[i];
    b = lt(r->v[i],pb);
    t[i] = r->v[i]-pb+(b<<8);
    pb = b;
  }
  mask = b - 1;
  for(i=0;i<32;i++) 
    r->v[i] ^= mask & (r->v[i] ^ t[i]);
}

/* Reduce coefficients of x before calling barrett_reduce */
static void barrett_reduce(group_scalar *r, const crypto_uint32 x[64])
{
  /* See HAC, Alg. 14.42 */
  int i,j;
  crypto_uint32 q2[66];
  crypto_uint32 *q3 = q2 + 33;
  crypto_uint32 r1[33];
  crypto_uint32 r2[33];
  crypto_uint32 carry;
  crypto_uint32 pb = 0;
  crypto_uint32 b;

  for (i = 0;i < 66;++i) q2[i] = 0;
  for (i = 0;i < 33;++i) r2[i] = 0;

  for(i=0;i<33;i++)
    for(j=0;j<33;j++)
      if(i+j >= 31) q2[i+j] += mu[i]*x[j+31];
  carry = q2[31] >> 8;
  q2[32] += carry;
  carry = q2[32] >> 8;
  q2[33] += carry;

  for(i=0;i<33;i++)r1[i] = x[i];
  for(i=0;i<32;i++)
    for(j=0;j<33;j++)
      if(i+j < 33) r2[i+j] += m[i]*q3[j];

  for(i=0;i<32;i++)
  {
    carry = r2[i] >> 8;
    r2[i+1] += carry;
    r2[i] &= 0xff;
  }

  for(i=0;i<32;i++) 
  {
    pb += r2[i];
    b = lt(r1[i],pb);
    r->v[i] = r1[i]-pb+(b<<8);
    pb = b;
  }

  /* XXX: Can it really happen that r<0?, See HAC, Alg 14.42, Step 3 
   * If so: Handle  it here!
   */

  reduce_add_sub(r);
  reduce_add_sub(r);
}

int  group_scalar_get32(group_scalar *r, const unsigned char x[32])
{
  int i;
  for(i=0;i<32;i++)
    r->v[i] = x[i];
  return 0;
}

int  group_scalar_get64(group_scalar *r, const unsigned char x[64])
{
  int i;
    crypto_uint32 t[64];
  for(i=0;i<64;i++) t[i] = x[i];
    barrett_reduce(r, t);
  return 0;
}

void group_scalar_pack(unsigned char r[GROUP_SCALAR_PACKEDBYTES], const group_scalar *x)
{
  int i;
  for(i=0;i<32;i++)
    r[i] = x->v[i];
}

static void group_scalar_add(group_scalar *r, const group_scalar *x, const group_scalar *y)
{
  int i, carry;
  for(i=0;i<32;i++) r->v[i] = x->v[i] + y->v[i];
  for(i=0;i<31;i++)
  {
    carry = r->v[i] >> 8;
    r->v[i+1] += carry;
    r->v[i] &= 0xff;
  }
  reduce_add_sub(r);
}

void group_scalar_sub(group_scalar *r, const group_scalar *x, const group_scalar *y)
{
  crypto_uint32 b = 0;
  crypto_uint32 t;
  int i;
  group_scalar d;

  for(i=0;i<32;i++)
  {
    t = m[i] - y->v[i] - b;
    d.v[i] = t & 255;
    b = (t >> 8) & 1;
  }
  group_scalar_add(r,x,&d);
}

void group_scalar_mul(group_scalar *r, const group_scalar *x, const group_scalar *y)
{
  int i,j,carry;
  crypto_uint32 t[64];
  for(i=0;i<64;i++)t[i] = 0;

  for(i=0;i<32;i++)
    for(j=0;j<32;j++)
      t[i+j] += x->v[i] * y->v[j];

  /* Reduce coefficients */
  for(i=0;i<63;i++)
  {
    carry = t[i] >> 8;
    t[i+1] += carry;
    t[i] &= 0xff;
  }

  barrett_reduce(r, t);
}

static void group_scalar_setzero(group_scalar *r)
{
  int i;
  for(i=0;i<32;i++)
    r->v[i] = 0;
}

static void group_scalar_negate(group_scalar *r, const group_scalar *x)
{
  group_scalar t;
  group_scalar_setzero(&t);
  group_scalar_sub(r,&t,x);
}

void group_scalar_set_pos(group_scalar *r)
{
    if ( r->v[0] & 1 ) { group_scalar_negate(r, r); }
}
