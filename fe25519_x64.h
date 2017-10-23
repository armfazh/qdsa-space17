/**
 * Copyright (c) 2017 Armando Faz <armfazh@ic.unicamp.br>.
 * Institute of Computing.
 * University of Campinas, Brazil.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 **/
#ifndef _ELEMENT_1W_X64_H_
#define _ELEMENT_1W_X64_H_

#include <stdint.h>

#define ALIGN_BYTES 32
#ifdef __INTEL_COMPILER
#define ALIGN __declspec(align(ALIGN_BYTES))
#else
#define ALIGN __attribute__ ((aligned (ALIGN_BYTES)))
#endif

#define SIZE_ELEMENT_BYTES 32
#define NUM_WORDS_CURVE25519_X64 4
typedef ALIGN uint64_t fe25519[NUM_WORDS_CURVE25519_X64];
typedef ALIGN uint64_t fe25519_Buffer_x64[2*NUM_WORDS_CURVE25519_X64];
typedef uint64_t (*argfe25519)[4];

void fe25519_random(argfe25519 A);

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

#endif /* _ELEMENT_1W_X64_H_ */
