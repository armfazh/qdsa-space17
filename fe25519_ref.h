/*
 * Author: Joost Renes
 * Version: 2017-05-24
 * Public Domain
 */

#ifndef _FE25519_REF_H_
#define _FE25519_REF_H_

#include <stdint.h>

typedef struct
{
  uint32_t v[32];
}
fe25519;
#define argfe25519 fe25519 *

void fe25519_freeze(argfe25519 r);
void fe25519_unpack(argfe25519 r, const unsigned char x[32]);
void fe25519_pack(unsigned char r[32], const argfe25519 x);
void fe25519_copy(argfe25519 r, const argfe25519 x);

void fe25519_cswap(argfe25519 x, argfe25519 y, int b);
int fe25519_iszero(const argfe25519 x);
void fe25519_setone(argfe25519 r);
void fe25519_setzero(argfe25519 r);
void fe25519_setbyte(argfe25519 r, unsigned char n);

void fe25519_add(argfe25519 r, const argfe25519 x, const argfe25519 y);
void fe25519_sub(argfe25519 r, const argfe25519 x, const argfe25519 y);
void fe25519_mul121666(argfe25519 r, const argfe25519 x);
void fe25519_mul(argfe25519 r, const argfe25519 x, const argfe25519 y);
void fe25519_square(argfe25519 r, const argfe25519 x);
void fe25519_invert(argfe25519 r, const argfe25519 x);
void fe25519_sqrt(argfe25519 r, const argfe25519 a);

#endif /* _FE25519_REF_H_ */
