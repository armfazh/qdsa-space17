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
#include "print.h"
#include <stdio.h>

void print_bytes(uint8_t * A,int num_bytes)
{
	int i;

	printf("0x");
	for(i=num_bytes-1;i>=0;i--)
	{
		printf("%02x", A[i]);
	}
	printf("\n");
}

#if defined __FP_REF__
void fe25519_print(const argfe25519 A)
{
	int i=0;
	printf("0x");
	for(i=31;i>=0;i--)
	{
		printf("%02x", A->v[i]);
	}
	printf("\n");
}
#elif defined (__FP_X64__)
void fe25519_print(const argfe25519 A)
{
	print_bytes((uint8_t*)(*A),SIZE_ELEMENT_BYTES);
}
#else
#error "Define __FP_X64__ or  __FP_REF__ variable."
#endif

void group_scalar_print(group_scalar *x)
{
	int i;
	unsigned char buf[32];
	group_scalar_pack(buf,x);
	printf("0x");
	for(i=31;i>=0;i--)
	{
		printf("%02x",buf[i]);
	}
	printf("\n");
}

void ecp_print(ecp* p)
{
	int i=0;
	unsigned char buf[32];
	fe25519 invZ,x;

	fe25519_invert(&invZ,&p->Z);
	fe25519_mul(&x,&p->X,&invZ);
	fe25519_pack(buf,&x);
	for(i=0;i<32;i++) { printf("%02X,", buf[i]); } printf("\n");
}

void print_key(unsigned char *pk)
{
	print_bytes(pk,32);
}
