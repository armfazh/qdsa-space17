/*
 * Author: Joost Renes
 * Version: 2017-05-24
 * Public Domain
 */
/**
 * Contribution:
 * A new,faster right-to-left method for calculating
 * fixed-point multiplications on Montgomery curves.
 *
 * Author:
 * Copyright (c) 2017 Armando Faz <armfazh@ic.unicamp.br>.
 * Institute of Computing.
 * University of Campinas, Brazil.
 *
 **/
#include "fe25519.h"
#include "ladder.h"

void group_cmove(group_scalar *x, const group_scalar *y, int b)
{
    int i;
    crypto_uint32 db = -b;
    crypto_uint32 t;

    for(i=0;i<=31;i++)
    {
        t = x->v[i] ^ y->v[i];
        t &= db;
        x->v[i] ^= t;
    }
}

void ecswap(ecp *x, ecp *y, int b)
{
    fe25519_cswap(&x->X,&y->X,b);
    fe25519_cswap(&x->Z,&y->Z,b);
}

void xDBLADD(ecp *xp, ecp *xq, const argfe25519 xd)
{
    /*
     * Simultaneous xDBL and xADD operation on
     * the Montgomery curve.
     *
     * Input: 
     *      xp: proj. x-coordinate on Montgomery curve
     *      xq: proj. x-coordinate on Montgomery curve
     *      xd: affine x-coordinate of difference xp-xq
     *
     * Output: 
     *      xp: proj. x-coordinate of 2*xp
     *      xq: proj. x-coordinate of xp+xq
     */

    fe25519 b0,b1;

    fe25519_add(&b0, &xp->X, &xp->Z);
    fe25519_sub(&b1, &xp->X, &xp->Z);
    fe25519_add(&xp->X, &xq->X, &xq->Z);
    fe25519_sub(&xp->Z, &xq->X, &xq->Z);
    fe25519_mul(&xq->X, &xp->Z, &b0);
    fe25519_mul(&xp->Z, &xp->X, &b1);
    fe25519_add(&xp->X, &xp->Z, &xq->X);
    fe25519_sub(&xq->Z, &xq->X, &xp->Z);
    fe25519_square(&xq->X, &xp->X);
    fe25519_square(&xp->X, &xq->Z);
    fe25519_mul(&xq->Z, &xp->X, xd);
    fe25519_square(&xp->X, &b0);
    fe25519_square(&b0, &b1);
    fe25519_sub(&xp->Z, &xp->X, &b0);
    fe25519_mul(&xp->X, &b0, &xp->X);
    fe25519_mul121666(&b1, &xp->Z);
    fe25519_add(&b1, &b1, &b0);
    fe25519_mul(&xp->Z, &b1, &xp->Z);
}

void xDADD_star(ecp *xp, ecp *xdif, const argfe25519 mu_q)
{
    fe25519 A,B,C,sub,add;

    fe25519_sub(&B,&xp->X,&xp->Z);
    fe25519_add(&A,&xp->X,&xp->Z);
    fe25519_mul(&C,mu_q,&B);
    fe25519_sub(&sub,&A,&C);
    fe25519_add(&add,&A,&C);
    fe25519_square(&A,&add);
    fe25519_square(&B,&sub);
    fe25519_mul(&xp->X,&xdif->Z,&A);
    fe25519_mul(&xp->Z,&xdif->X,&B);
}

void ladder(ecp *r, ecp *xp, const argfe25519 xpw, const group_scalar *n)
{
    /*
     * Montgomery ladder computing n*xp via repeated
     * differential additions and constant-time
     * conditional swaps.
     *
     * Input: 
     *      xp: proj. x-coordinate on Montgomery curve
     *      xpw: affine x-coordinate of xp
     *      n: Scalar (max 255-bit)
     *
     * Output: 
     *      xr: proj. x-coordinate of n*xq
     *      xp: proj. x-coordinate of (n+1)*xp
     */

    int i,swap; int bit = 0; int prevbit = 0;

    fe25519_setone(&r->X);
    fe25519_setzero(&r->Z);
    for(i=254; i>=0; i--)
    {
        bit = ( n->v[i>>3] >> ( i & 7 ) ) & 1;
        swap = bit ^ prevbit;
        prevbit = bit;

        ecswap(r, xp, swap);
        xDBLADD(r, xp, xpw);
    }
    ecswap(r, xp, bit);
}

#if defined(__NO_R2L__)
/**
 * This is a wrapper to use the classic Montgomery
 * Ladder Algorithm to compute a fixed-point multiplication.
 * @param r
 * @param n
 */
void ladder_base(ecp *r, const group_scalar *n)
{
    ecp base;
    fe25519 basex;

    fe25519_setbyte(&base.X,9);
    fe25519_setone(&base.Z);
    fe25519_copy(&basex, &base.X);

    ladder(r, &base, &basex, n);
}
#elif defined(__R2L__)

/**
 * Look-up table storing multiples of the generator point of Curve25519.
 */
#include "table_8k.h"
/**
 * This is the new Right-to-Left Algorithm to compute
 * fixed point multiplication.
 * @param r
 * @param n
 */
void ladder_base(ecp *r, const group_scalar *n)
{
    /*
     * Right-to-Left Montgomery ladder computing n*xp via repeated
     * differential additions and constant-time
     * conditional swaps.
     *
     * Input:
     *      xp: proj. x-coordinate on Montgomery curve
     *      xpw: affine x-coordinate of xp
     *      n: Scalar (max 255-bit)
     *
     * Output:
     *      xr: proj. x-coordinate of n*xq
     *      xp: proj. x-coordinate of (n+1)*xp
     */
    int i,swap; int bit = 0; int prevbit = 0;
    ecp q0,q1;
    fe25519 nine;fe25519 mu;
    group_scalar k,kp;


    fe25519_setbyte(&nine,9);
    fe25519_copy(&q0.X,&nine);
    fe25519_copy(&q1.X,&nine);
    fe25519_setone(&q0.Z);
    fe25519_setone(&q1.Z);

    for(i=0;i<32;i++)
        k.v[i] = n->v[i];
    for(i=0;i<8;i++)
    	reduce_add_sub(&k);
    group_scalar_negate(&kp,&k);

    bit = k.v[0] & 0x1;
    group_cmove(&kp,&k,bit);
    prevbit = bit;

    for(i=1; i<255; i++)
    {
        bit = ( kp.v[i>>3] >> ( i & 7 ) ) & 1;
        swap = bit ^ prevbit;
        prevbit = bit;
        ecswap(&q0, &q1, swap);
	fe25519_unpack(&mu,(unsigned char *)&Table_Ladder_8k[4*i]);
	xDADD_star(&q0,&q1,&mu);
    }
    ecswap(&q0, &q1, bit);
    fe25519_copy(&r->X,&q1.X);
    fe25519_copy(&r->Z,&q1.Z);
}
#else
#error "Define __NO_R2L__ or  __R2L__ variable."
#endif

void bValues(argfe25519 bZZ, argfe25519 bXZ, argfe25519 bXX,
        const ecp *xp, const ecp *xq)
{
    /*
     * Three biquadratic forms B_XX, B_XZ and B_ZZ
     * in the coordinates of xp and xq  
     *
     * Input: 
     *      xp: proj. x-coordinate on Montgomery curve
     *      xq: proj. x-coordinate on Montgomery curve
     *
     * Output: 
     *      bZZ: Element B_ZZ of fe25519
     *      bXZ: Element B_XZ of fe25519
     *      bXX: Element B_XX of fe25519
     */

    fe25519 b0,b1,b2;

    fe25519_mul(&b0, (const argfe25519)&xp->X, (const argfe25519)&xq->X);
    fe25519_mul(&b1, (const argfe25519)&xp->Z, (const argfe25519)&xq->Z);
    fe25519_sub(bZZ, &b0, &b1);
    fe25519_square(bZZ, bZZ);
    fe25519_add(&b0, &b0, &b1);

    fe25519_mul(&b1, (const argfe25519)&xp->X, (const argfe25519)&xq->Z);
    fe25519_mul(&b2, (const argfe25519)&xq->X, (const argfe25519)&xp->Z);
    fe25519_sub(bXX, &b1, &b2);
    fe25519_square(bXX, bXX);

    fe25519_add(bXZ, &b1, &b2);
    fe25519_mul(bXZ, bXZ, &b0);
    fe25519_mul(&b0, &b1, &b2);
    fe25519_add(&b0, &b0, &b0);
    fe25519_add(&b0, &b0, &b0);
    fe25519_add(&b1, &b0, &b0);
    fe25519_mul121666(&b1, &b1);
    fe25519_sub(&b0, &b1, &b0);
    fe25519_add(bXZ, bXZ, &b0);
    fe25519_add(bXZ, bXZ, bXZ);
}

int check(argfe25519 bZZ, argfe25519 bXZ, argfe25519 bXX,
        const argfe25519 rx)
{
    /*
     * Verify whether B_XXrx^2 - B_XZrx + B_ZZ = 0
     *
     * Input: 
     *      bZZ: Biquadratic form B_ZZ
     *      bXZ: Biquadratic form B_XZ
     *      bXX: Biquadratic form B_XX
     *      rx: affine x-coordinate on Montgomery curve
     *
     * Output: 
     *      1 if B_XXrx^2 - B_XZrx + B_ZZ = 0,
     *      0 otherwise
     */

    fe25519 b0, b1;

    fe25519_square(&b0, rx);
    fe25519_mul(&b0, &b0, bXX);
    fe25519_mul(&b1, rx, bXZ);
    fe25519_sub(&b0, &b0, &b1);
    fe25519_add(&b0, &b0, bZZ);

    return fe25519_iszero(&b0);
}

void compress(argfe25519 r, const ecp *xp)
{
    /*
     * Compress from projective representation (X : Z)
     * to affine x = X*Z^{p-2}, where p = 2^255-19
     *
     * Input: 
     *      xp: proj. x-coordinate (X : Z)
     *
     * Output: 
     *      r: affine x-coordinate x = X*Z^{p-2}
     */

    fe25519_invert(r, (const argfe25519)&xp->Z);  
    fe25519_mul(r, (const argfe25519)&xp->X, r);
    fe25519_freeze(r);
}

void decompress(ecp *xp, const argfe25519 r)
{
    /*
     * Decompress from affine representation x
     * to projective (x : 1)
     *
     * Input: 
     *      r: affine x-coordinate x
     *
     * Output: 
     *      xp: proj. x-coordinate (x : 1)
     */

    fe25519_copy(&xp->X, r);
    fe25519_setone(&xp->Z);
}
