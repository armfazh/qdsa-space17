/*
 * Author: Joost Renes
 * Version: 2017-05-24
 * Public Domain
 */
#ifndef LADDER_H
#define LADDER_H

#include "scalar.h"
#include "fe25519.h"

typedef struct 
{
    fe25519 X;
    fe25519 Z;
}
ecp;

void xDADD_star(ecp *xp, ecp *xdif, const argfe25519 mu_q);
void group_cmove(group_scalar *x, const group_scalar *y, int b);
void ecswap(ecp *x, ecp *y, int b);
void xDBLADD(ecp *xp, ecp *xq, const argfe25519 xd);
void ladder(ecp *r, ecp *xp, const argfe25519 xpw, const group_scalar *n);
void ladder_base(ecp *r, const group_scalar *n);
void bValues(argfe25519 bZZ, argfe25519 bXZ, argfe25519 bXX,
        const ecp *xp, const ecp *xq);
int check(argfe25519 bZZ, argfe25519 bXZ, argfe25519 bXX,
        const argfe25519 rx);
void compress(argfe25519 r, const ecp *xp);
void decompress(ecp *xp, const argfe25519 r);

#endif /* LADDER_H */
