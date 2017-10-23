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
#include "../sign.h"
#include "../dh.h"
#include "print.h"
#include "clocks.h"
#include "random.h"

#define mes_len 1
#define loop_min 0
#define loop_len 1000

static void bench_fp(void)
{
#if defined(__FP_REF__)
	int BENCH=1000;
#elif defined(__FP_X64__)
	int BENCH=3000;
#else
#error "Define __FP_X64__ or  __FP_REF__ variable."
#endif

    fe25519 a,b,c;

    fe25519_random(&a);
    fe25519_random(&b);
    fe25519_random(&c);

    printf("=== GF(2^255-19) ===\n");
    CLOCKS("add",fe25519_add(&c,&a,&b));
    CLOCKS("sub",fe25519_sub(&c,&a,&b));
    CLOCKS("mul",fe25519_mul(&c,&c,&b));
    CLOCKS("m24",fe25519_mul121666(&c,&a));
    CLOCKS("sqr",fe25519_square(&c,&a));

    BENCH /= 10;
    CLOCKS("inv",fe25519_invert(&c,&a));
    CLOCKS("srt",fe25519_sqrt(&c,&a));
}

static void bench_qdsa()
{
#if defined(__FP_REF__)
	const int BENCH=50;
#elif defined(__FP_X64__)
	const int BENCH=250;
#else
#error "Define __FP_X64__ or  __FP_REF__ variable."
#endif

    unsigned char sk[64];
    unsigned long long mlen = mes_len;
    unsigned char m[mlen];
    unsigned char pk[32];
    unsigned char sm[64+mlen];
    unsigned long long smlen;
    int ch=0;

    printf("==== qDSA Scheme ===\n");
    CLOCKS_RANDOM(
		random_key(pk),
        "Keygen",
		keypair(pk, sk)
    );

    CLOCKS_RANDOM(
        random_key(pk);
        random_bytes(m,mlen),
		"Sign",
        sign(sm, &smlen, m, mlen, pk, sk)
    );

    CLOCKS_RANDOM(
        random_key(pk);
        random_bytes(m,mlen);
        sign(sm, &smlen, m, mlen, pk, sk),
        "Verify",
        ch = verify(m, mlen, sm, smlen, pk)
	);

    oper_second(
        random_key(pk),
        "keygen",
        keypair(pk, sk)
    );
    oper_second(
        random_key(pk);
        random_bytes(m,mlen),
        "Sign",
        sign(sm, &smlen, m, mlen, pk, sk)
    );
    oper_second(
            random_key(pk);
            random_bytes(m,mlen);
            sign(sm, &smlen, m, mlen, pk, sk),
            "Verify",
            ch += verify(m, mlen, sm, smlen, pk)
    );
}

static void bench()
{
    printf(" = Start of Benchmark = \n");
	bench_fp();
	bench_qdsa();
    printf(" = End of Benchmark = \n");
}

static int test(void)
{
    /* signatures API */

    int j;
    unsigned char sk[64]; 
    unsigned long long mlen = mes_len;
    unsigned char m[mlen]; 
    unsigned char pk[32];
    unsigned char sm[64+mlen];
    unsigned long long smlen;
    int ch;

    printf(" = Start of Testing = \n");

#if 1
    int count = 0;
    printf("Checking %d signatures...\n", loop_len);
    for(j=loop_min;j<=loop_min+loop_len-1;j++)
    {
        random_key(sk);
        random_bytes(m,mlen);
        /* printf("sk:  "); print_key(sk); */
        keypair(pk, sk);
        /* printf("pk:  "); print_key(pk); */
        /* printf("msg: "); print_bytes(m,mlen); */
        sign(sm, &smlen, m, mlen, pk, sk);
        /* printf("sig: "); print_bytes(sm,smlen); */
        ch = verify(m, mlen, sm, smlen, pk);
        count += ch;
        /* printf("ver: %d\n", ch); */
        if ( ch != 1 ) 
        {
            printf("\n%lld\n", mlen);
            printf("sk:  "); print_key(sk);
            printf("pk:  "); print_key(pk);
            printf("msg: "); print_bytes(m,mlen);
            printf("sig: "); print_bytes(sm,smlen);
            printf("ver: %d\n", ch);
            break;
        }
    }
    printf("Passed: %d/%d\n",count,loop_len);
    printf("Finished\n");

    /* end signatures API */
#endif

    /* DH */

#if 0
    unsigned long long i=0;
    unsigned char dh_sk[32];
    unsigned char dh_pk[32];
    unsigned char dh_ss[32];
    for(i=0;i<32;i++)
    {
        dh_sk[i] = 0;
        dh_pk[i] = 0;
    }

    dh_keygen(dh_pk, dh_sk);

    printf("\n");
    for(i=0;i<32;i++) { printf("%02X ", dh_pk[i]); }
    printf("\n");

    for(i=0;i<32;i++) { dh_sk[i] = 0; }
    dh_sk[0] = 2;
    dh_exchange(dh_ss, dh_pk, dh_sk);

    printf("\n");
    for(i=0;i<32;i++) { printf("%02X ", dh_ss[i]); }
    printf("\n");
#endif

    /* end DH */

    printf(" = End of Testing = \n");
    return 0;
}

static void sample(void)
{
    unsigned char sk[64];
    unsigned long long mlen = mes_len;
    unsigned char m[mlen];
    unsigned char pk[32];
    unsigned char sm[64 + mlen];
    unsigned long long smlen;
    int ch;

    printf(" = Start of Example = \n");
    random_bytes(sk, 64);
    random_bytes(m, mlen);

    printf("sk:  ");
    print_key(sk);
    keypair(pk, sk);
    printf("pk:  ");
    print_key(pk);

    printf("msj: ");
    print_bytes(m, mlen);
    sign(sm, &smlen, m, mlen, pk, sk);
    printf("sig:  ");
    print_bytes(sm, smlen);
    ch = verify(m, mlen, sm, smlen, pk);
    printf("ver: %d\n", ch);

    printf(" = End of Example = \n");
}

int main(void)
{
	sample();
	test();
	bench();
	return 0;
}
