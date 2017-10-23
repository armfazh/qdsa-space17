#ifndef GROUP_SCALAR_H
#define GROUP_SCALAR_H

#define GROUP_SCALAR_PACKEDBYTES 32
#include "fe25519.h"

typedef struct 
{
  uint16_t v[32]; 
}
group_scalar;

int group_scalar_get32(group_scalar *r, const unsigned char x[32]);
int group_scalar_get64(group_scalar *r, const unsigned char x[64]);
void group_scalar_pack(unsigned char s[GROUP_SCALAR_PACKEDBYTES], const group_scalar *r);

void group_scalar_sub(group_scalar *r, const group_scalar *x, const group_scalar *y);
void group_scalar_mul(group_scalar *r, const group_scalar *x, const group_scalar *y);
void group_scalar_set_pos(group_scalar *r);

#endif
