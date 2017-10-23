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
#include "fe25519_x64.h"

static void mul_256x256_integer_x64(uint64_t *const c, uint64_t *const a, uint64_t *const b)
{
#ifdef __BMI2__
#ifdef __ADX__
	__asm__ __volatile__(
		"   movq      (%1), %%rdx  # A[0]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[0]*B[0]   \n\t"    "  xorl   %%r10d, %%r10d    \n\t"                                      "   movq	%%r8,  (%0)      \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[0]*B[1]   \n\t"    "  adox	 %%r9, %%r10     \n\t"                                      "   movq   %%r10, 8(%0)      \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[0]*B[2]   \n\t"    "  adox	%%r11, %%r12     \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[0]*B[3]   \n\t"    "  adox	%%r13, %%r14     \n\t"                                                                          "   movq    $0, %%rax  \n\t"
																 "  adox	%%rdx, %%rax     \n\t"

		"   movq     8(%1), %%rdx  # A[1]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[1]*B[0]   \n\t"    "  xorl   %%r10d, %%r10d    \n\t"  "   adcx	8(%0),  %%r8   \n\t"    "   movq	 %%r8,  8(%0)    \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[1]*B[1]   \n\t"    "  adox 	 %%r9, %%r10     \n\t"  "   adcx	%%r12, %%r10   \n\t"    "   movq	%%r10, 16(%0)    \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[1]*B[2]   \n\t"    "  adox	%%r11, %%r12     \n\t"  "   adcx	%%r14, %%r12   \n\t"                                        "   movq    $0, %%r8   \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[1]*B[3]   \n\t"    "  adox	%%r13, %%r14     \n\t"  "   adcx	%%rax, %%r14   \n\t"                                        "   movq    $0, %%rax  \n\t"
																 "  adox 	%%rdx, %%rax     \n\t"  "   adcx	 %%r8, %%rax   \n\t"

		"   movq    16(%1), %%rdx  # A[2]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[2]*B[0]   \n\t"    "  xorl   %%r10d, %%r10d    \n\t"  "   adcx   16(%0),  %%r8   \n\t"    "   movq	 %%r8, 16(%0)    \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[2]*B[1]   \n\t"    "  adox	 %%r9, %%r10     \n\t"  "   adcx	%%r12, %%r10   \n\t"    "   movq	%%r10, 24(%0)    \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[2]*B[2]   \n\t"    "  adox	%%r11, %%r12     \n\t"  "   adcx	%%r14, %%r12   \n\t"                                        "   movq    $0, %%r8   \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[2]*B[3]   \n\t"    "  adox	%%r13, %%r14     \n\t"  "   adcx	%%rax, %%r14   \n\t"                                        "   movq    $0, %%rax  \n\t"
																 "  adox	%%rdx, %%rax     \n\t"  "   adcx	 %%r8, %%rax   \n\t"

		"   movq	24(%1), %%rdx  # A[3]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[3]*B[0]   \n\t"    "  xorl   %%r10d, %%r10d    \n\t"  "   adcx   24(%0),  %%r8   \n\t"    "   movq	 %%r8, 24(%0)    \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[3]*B[1]   \n\t"    "  adox	 %%r9, %%r10     \n\t"  "   adcx	%%r12, %%r10   \n\t"    "   movq	%%r10, 32(%0)    \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[3]*B[2]   \n\t"    "  adox	%%r11, %%r12     \n\t"  "   adcx	%%r14, %%r12   \n\t"    "   movq	%%r12, 40(%0)    \n\t"  "   movq    $0, %%r8   \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[3]*B[3]   \n\t"    "  adox	%%r13, %%r14     \n\t"  "   adcx	%%rax, %%r14   \n\t"    "   movq	%%r14, 48(%0)    \n\t"  "   movq    $0, %%rax  \n\t"
																 "  adox	%%rdx, %%rax     \n\t"  "   adcx	 %%r8, %%rax   \n\t"    "   movq	%%rax, 56(%0)    \n\t"
	:
	: "r"  (c), "r" (a), "r"  (b)
	: "memory", "cc", "%rax", "%rdx",
	"%r8",  "%r9", "%r10", "%r11",
	"%r12", "%r13", "%r14"
	);
#else
	__asm__ __volatile__(
		"   movq     (%1), %%rdx  # A[0]                \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[0]*B[0]   \n\t"                                       "   movq	 %%r8,  (%0)  \n\t"
		"   mulx	 8(%2), %%r10, %%rax  # A[0]*B[1]   \n\t"    "   addq	%%r10,  %%r9     \n\t"  "   movq	 %%r9, 8(%0)  \n\t"
		"   mulx	16(%2), %%r12, %%rbx  # A[0]*B[2]   \n\t"    "   adcq	%%r12, %%rax     \n\t"
		"   mulx	24(%2), %%r14, %%rcx  # A[0]*B[3]   \n\t"    "   adcq	%%r14, %%rbx     \n\t"
		"   adcq	   $0, %%rcx                        \n\t"

		"   movq    8(%1), %%rdx  # A[1]                \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[1]*B[0]   \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[1]*B[1]   \n\t"    "   addq	%%r10, %%r9      \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[1]*B[2]   \n\t"    "   adcq	%%r12, %%r11     \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[1]*B[3]   \n\t"    "   adcq	%%r14, %%r13     \n\t"
		"   adcq	   $0, %%rdx                        \n\t"

		"   addq	 %%r8,  8(%0)                       \n\t"
		"   adcq	%%rax,  %%r9                        \n\t"    "    movq	 %%r9, 16(%0)    \n\t"      "   movq	 $0, %%rax    \n\t"
		"   adcq	%%r11, %%rbx                        \n\t"
		"   adcq	%%r13, %%rcx                        \n\t"
		"   adcq	%%rdx, %%rax                        \n\t"

		"   movq   16(%1), %%rdx  # A[2]                \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[2]*B[0]   \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[2]*B[1]   \n\t"    "    addq	%%r10,  %%r9     \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[2]*B[2]   \n\t"    "    adcq	%%r12, %%r11     \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[2]*B[3]   \n\t"    "    adcq	%%r14, %%r13     \n\t"
		"   adcq	   $0, %%rdx                        \n\t"

		"   addq	 %%r8, 16(%0)                       \n\t"
		"   adcq	%%rbx,  %%r9                        \n\t"    "    movq	 %%r9, 24(%0)    \n\t"      "   movq	 $0, %%rbx    \n\t"
		"   adcq	%%r11, %%rcx                        \n\t"
		"   adcq	%%r13, %%rax                        \n\t"
		"   adcq	%%rdx, %%rbx                        \n\t"

		"   movq	24(%1), %%rdx  # A[3]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[3]*B[0]   \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[3]*B[1]   \n\t"    "    addq	%%r10,  %%r9     \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[3]*B[2]   \n\t"    "    adcq	%%r12, %%r11     \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[3]*B[3]   \n\t"    "    adcq	%%r14, %%r13     \n\t"
		"   adcq     $0, %%rdx                          \n\t"

		"   addq    %%r8, 24(%0)                        \n\t"
		"   adcq	%%rcx,  %%r9                        \n\t"    "    movq	%%r9,  32(%0)    \n\t"   "   movq	 $0, %%rcx    \n\t"
		"   adcq	%%r11, %%rax                        \n\t"    "    movq	%%rax, 40(%0)    \n\t"
		"   adcq	%%r13, %%rbx                        \n\t"    "    movq	%%rbx, 48(%0)    \n\t"
		"   adcq	%%rdx, %%rcx                        \n\t"    "    movq	%%rcx, 56(%0)    \n\t"
	:
	: "r"  (c), "r" (a), "r"  (b)
	: "memory", "cc", "%rax", "%rbx", "%rcx", "%rdx", "%r8",
	"%r9", "%r10", "%r11", "%r12", "%r13", "%r14"
	);
#endif
#else    /* Without BMI2 */
	/**
	* TODO: Multiplications using MULQ instruction.
	**/
#endif
}

static void sqr_256x256_integer_x64(uint64_t *const c, uint64_t *const a)
{
#ifdef __BMI2__
	__asm__ __volatile__(
		"   movq	 (%1), %%rdx         # A[0]         \n\t"
		"   mulx	%%rdx,  %%r8, %%r9   # A[0]^2       \n\t"
		"   movq	8(%1), %%rdx         # A[1]         \n\t"
		"   mulx	%%rdx, %%r10, %%r11  # A[1]^2       \n\t"
		"   movq	 %%r8,   (%0)                       \n\t"
		"   movq	 %%r9,  8(%0)                       \n\t"
		"   movq	%%r10, 16(%0)                       \n\t"
		"   movq	%%r11, 24(%0)                       \n\t"

		"   movq	16(%1), %%rdx        # A[2]         \n\t"
		"   mulx	%%rdx,  %%r8, %%r9   # A[2]^2       \n\t"
		"   movq	24(%1), %%rdx        # A[3]         \n\t"
		"   mulx	%%rdx, %%r10, %%r11  # A[3]^2       \n\t"
		"   movq	 %%r8, 32(%0)                       \n\t"
		"   movq	 %%r9, 40(%0)                       \n\t"
		"   movq	%%r10, 48(%0)                       \n\t"
		"   movq	%%r11, 56(%0)                       \n\t"

		"   movq	 8(%1), %%rdx         # A[1]        \n\t"
		"   mulx	  (%1), %%r8, %%r9    # A[0]*A[1]   \n\t"
		"   mulx	16(%1), %%r10, %%r11  # A[2]*A[1]   \n\t"
		"   mulx	24(%1), %%rcx, %%r14  # A[3]*A[1]   \n\t"

		"   movq	16(%1), %%rdx         # A[2]        \n\t"
		"   mulx	24(%1), %%r12, %%r13  # A[3]*A[2]   \n\t"
		"   mulx	  (%1), %%rax, %%rdx  # A[0]*A[2]   \n\t"

		" 	addq	%%rax, %%r9       \n\t"
		" 	adcq	%%rdx, %%r10      \n\t"
		" 	adcq	%%rcx, %%r11      \n\t"
		" 	adcq	%%r14, %%r12      \n\t"
		" 	adcq	   $0, %%r13      \n\t"
		" 	movq	   $0, %%r14      \n\t"
		" 	adcq	   $0, %%r14      \n\t"

		" 	movq	  (%1), %%rdx        # A[0]         \n\t"
		" 	mulx	24(%1), %%rax, %%rdx # A[0]*A[3]    \n\t"

		" 	addq	%%rax, %%r10      \n\t"
		" 	adcq	%%rdx, %%r11      \n\t"
		" 	adcq	   $0, %%r12      \n\t"
		" 	adcq	   $0, %%r13      \n\t"
		" 	adcq	   $0, %%r14      \n\t"

		" 	shldq	$1, %%r13, %%r14  \n\t"
		" 	shldq	$1, %%r12, %%r13  \n\t"
		" 	shldq	$1, %%r11, %%r12  \n\t"
		" 	shldq	$1, %%r10, %%r11  \n\t"
		" 	shldq	$1,  %%r9, %%r10  \n\t"
		" 	shldq	$1,  %%r8,  %%r9  \n\t"
		" 	shlq	$1,  %%r8         \n\t"

		" 	addq	 8(%0),  %%r8     \n\t"  " 	movq	 %%r8,  8(%0)  \n\t"
		" 	adcq	16(%0),  %%r9     \n\t"  " 	movq	 %%r9, 16(%0)  \n\t"
		" 	adcq	24(%0), %%r10     \n\t"  " 	movq	%%r10, 24(%0)  \n\t"
		" 	adcq	32(%0), %%r11     \n\t"  " 	movq	%%r11, 32(%0)  \n\t"
		" 	adcq	40(%0), %%r12     \n\t"  " 	movq	%%r12, 40(%0)  \n\t"
		" 	adcq	48(%0), %%r13     \n\t"  " 	movq	%%r13, 48(%0)  \n\t"
		" 	adcq	56(%0), %%r14     \n\t"  " 	movq	%%r14, 56(%0)  \n\t"
	:
	: "r"  (c), "r" (a)
	:  "memory", "cc", "%rax", "%rcx", "%rdx",
	"%r8",  "%r9", "%r10", "%r11",
	"%r12", "%r13", "%r14"
	);
#else    /* Without BMI2 */
	/**
	* TODO: Multiplications using MULQ instruction.
	**/
#endif
}

static void red_Element_1w_x64(uint64_t *const c, uint64_t *const a)
{
#ifdef __BMI2__
#ifdef __ADX__
	__asm__ __volatile__(
		"   movl	$38, %%edx     # 2*c = 38 = 2^256  \n\t"
		"   mulx	32(%1),  %%r8, %%r10 # c*C[4]      \n\t"   "  xorl  %%ebx, %%ebx  \n\t"  "  adox      (%1),  %%r8  \n\t"
		"   mulx	40(%1),  %%r9, %%r11 # c*C[5]      \n\t"   "  adcx	%%r10,  %%r9  \n\t"  "  adox     8(%1),  %%r9  \n\t"
		"   mulx	48(%1), %%r10, %%rax # c*C[6]      \n\t"   "  adcx	%%r11, %%r10  \n\t"  "  adox    16(%1), %%r10  \n\t"    "  movq  %%r10, 16(%0) \n\t"
		"   mulx	56(%1), %%r11, %%rcx # c*C[7]      \n\t"   "  adcx	%%rax, %%r11  \n\t"  "  adox    24(%1), %%r11  \n\t"    "  movq  %%r11, 24(%0) \n\t"
		                                                       "  adcx	%%rbx, %%rcx  \n\t"  "  adox     %%rbx, %%rcx  \n\t"
		"   xorl    %%ebx, %%ebx                       \n\t"
		"   mulx	%%rcx, %%rax, %%rcx                \n\t"   "  adcx  %%rax,  %%r8  \n\t"  "  movq     %%r8,   (%0)  \n\t"
		                                                       "  adcx  %%rcx,  %%r9  \n\t"  "  movq     %%r9,  8(%0)  \n\t"
	:
	: "r"  (c), "r" (a)
	: "memory", "cc", "%rax", "%rbx", "%rcx", "%rdx", "%r8", "%r9", "%r10", "%r11"
	);
#else
	__asm__ __volatile__(
	"   movl	$38, %%edx     # 2*c = 38 = 2^256      \n\t"
			"   mulx	32(%1), %%r8,  %%r9  # c*C[4]  \n\t"
			"   mulx	40(%1), %%r10, %%r11 # c*C[5]  \n\t"   "  addq	%%r9, %%r10   \n\t"
			"   mulx	48(%1), %%r12, %%r13 # c*C[6]  \n\t"   "  adcq	%%r11, %%r12  \n\t"
			"   mulx	56(%1), %%rax, %%rcx # c*C[7]  \n\t"   "  adcq	%%r13, %%rax  \n\t"
			"  adcq	   $0, %%rcx  \n\t"

			"  addq      (%1),  %%r8  \n\t"
			"  adcq     8(%1), %%r10  \n\t"
			"  adcq    16(%1), %%r12  \n\t"     "   movq	%%r12, 16(%0)  \n\t"
			"  adcq    24(%1), %%rax  \n\t"     "   movq	%%rax, 24(%0)  \n\t"
			"  adcq        $0, %%rcx  \n\t"

			"  mulx	%%rcx, %%rax, %%rcx   \n\t"
			"  addq     %%rax, %%r8       \n\t" "   movq    %%r8,    (%0)  \n\t"
			"  adcq     %%rcx, %%r10      \n\t" "   movq    %%r10,  8(%0)  \n\t"
	:
	: "r"  (c), "r" (a)
	: "memory", "cc", "%rax", "%rbx", "%rcx", "%rdx", "%r8", "%r9", "%r10", "%r11", "%r12", "%r13"
	);
#endif
#else    /* Without BMI2 */
	/**
	* TODO: Multiplications using MULQ instruction.
	**/
#endif
}

void fe25519_cswap(argfe25519 x, argfe25519 y, int b)
{
	int i;
	uint64_t db = -b;
	uint64_t t;

	for(i=0;i<NUM_WORDS_CURVE25519_X64;i++)
	{
		t = (*x)[i] ^ (*y)[i];
		t &= db;
		(*x)[i] ^= t;
		(*y)[i] ^= t;
	}
}

void fe25519_unpack(argfe25519 r, const unsigned char x[32])
{
	int i;
	for(i=0;i<NUM_WORDS_CURVE25519_X64;i++)
		(*r)[i] = ((uint64_t*)x)[i];
}

void fe25519_pack(unsigned char r[32], const argfe25519 x)
{
	int i;
	for(i=0;i<NUM_WORDS_CURVE25519_X64;i++)
		((uint64_t*)r)[i] = (*x)[i];

}
void fe25519_copy(argfe25519 r, const argfe25519 x)
{
	int i;
	for(i=0;i<NUM_WORDS_CURVE25519_X64;i++)
		(*r)[i] = (*x)[i];
}

int fe25519_iszero(const argfe25519 x)
{
	int i=0,zeros=1,prime=1;
	const fe25519 p = {
		0xffffffffffffffed,
		0xffffffffffffffff,
		0xffffffffffffffff,
		0x7fffffffffffffff
	};
	fe25519_freeze(x);
	for(i=0;i<NUM_WORDS_CURVE25519_X64;i++)
	{
		zeros &= ((*x)[i]==0);
		prime &= ((*x)[i]==p[i]);
	}
	return zeros^prime;
}

void fe25519_setone(argfe25519 r)
{
	int i;
	for(i=0;i<NUM_WORDS_CURVE25519_X64;i++)
		(*r)[i] = 0;
	(*r)[0] = 1;
}
void fe25519_setbyte(argfe25519 r, unsigned char n)
{
	int i;
	for(i=0;i<NUM_WORDS_CURVE25519_X64;i++)
		(*r)[i] = 0;
	(*r)[0] = n;
}
void fe25519_setzero(argfe25519 r)
{
	int i;
	for(i=0;i<NUM_WORDS_CURVE25519_X64;i++)
		(*r)[i] = 0;
}

void fe25519_mul(argfe25519 r, const argfe25519 x, const argfe25519 y)
{
	fe25519_Buffer_x64 buffer_1w;
	mul_256x256_integer_x64(buffer_1w,*x,*y);\
    red_Element_1w_x64(*r,buffer_1w);
}

void fe25519_square(argfe25519 r, const argfe25519 x)
{
	fe25519_Buffer_x64 buffer_1w;
	sqr_256x256_integer_x64(buffer_1w,*x);\
    red_Element_1w_x64(*r,buffer_1w);
}

void fe25519_add(argfe25519 r, const argfe25519 x, const argfe25519 y)
{
#if __ADX__
	__asm__ __volatile__(
		"movq      (%2),  %%rax   \n\t"
		"movq     8(%2),  %%rcx   \n\t"
		"movq    16(%2),  %%r8    \n\t"
		"movq    24(%2),  %%r9    \n\t"
		"clc                      \n\t"
		"adcx      (%1),  %%rax   \n\t"
		"adcx     8(%1),  %%rcx   \n\t"
		"adcx    16(%1),  %%r8    \n\t"
		"adcx    24(%1),  %%r9    \n\t"
		"movq     %%rcx,  8(%0)   \n\t"
		"movq     %%r8 , 16(%0)   \n\t"
		"movq     %%r9 , 24(%0)   \n\t"
		"setc	 %%cl             \n\t"
		"neg 	 %%rcx            \n\t"
		"andq	 $38, %%rcx       \n\t"
		"addq	 %%rcx, %%rax     \n\t"
		"movq	 %%rax,    (%0)   \n\t"
	:
	: "r" (r), "r" (x), "r"  (y)
	: "memory","cc", "%rax", "%rcx", "%r8", "%r9"
	);
#else
	__asm__ __volatile__(
		"movq      (%2),  %%rax   \n\t"
		"movq     8(%2),  %%rcx   \n\t"
		"movq    16(%2),  %%r8    \n\t"
		"movq    24(%2),  %%r9    \n\t"
		"add       (%1),  %%rax   \n\t"
		"adc      8(%1),  %%rcx   \n\t"
		"adc     16(%1),  %%r8    \n\t"
		"adc     24(%1),  %%r9    \n\t"
		"movq     %%rcx,  8(%0)   \n\t"
		"movq     %%r8 , 16(%0)   \n\t"
		"movq     %%r9 , 24(%0)   \n\t"
		"setc	 %%cl             \n\t"
		"neg 	 %%rcx            \n\t"
		"andq	 $38, %%rcx       \n\t"
		"addq	 %%rcx, %%rax     \n\t"
		"movq	 %%rax,    (%0)   \n\t"
	:
	: "r" (*r), "r" (*x), "r"  (*y)
	: "memory","cc", "%rax", "%rcx", "%r8", "%r9"
	);
#endif
}

void fe25519_sub(argfe25519 r, const argfe25519 x, const argfe25519 y)
{
	__asm__ __volatile__(
		"movq      (%1),  %%rax   \n\t"
		"movq     8(%1),  %%rcx   \n\t"
		"movq    16(%1),  %%r8    \n\t"
		"movq    24(%1),  %%r9    \n\t"
		"subq      (%2),  %%rax   \n\t"
		"sbbq     8(%2),  %%rcx   \n\t"
		"sbbq    16(%2),  %%r8    \n\t"
		"sbbq    24(%2),  %%r9    \n\t"
		"movq     %%rcx,  8(%0)   \n\t"
		"movq     %%r8 , 16(%0)   \n\t"
		"movq     %%r9 , 24(%0)   \n\t"
		"setc	 %%cl             \n\t"
		"neg 	 %%rcx            \n\t"
		"andq	 $38, %%rcx       \n\t"
		"subq	 %%rcx, %%rax     \n\t"
		"movq	 %%rax,    (%0)   \n\t"
	:
	: "r" (*r), "r" (*x), "r"  (*y)
	: "memory","cc", "%rax", "%rcx", "%r8", "%r9"
	);
}

void fe25519_mul121666(argfe25519 r, const argfe25519 x)
{
#ifdef __BMI2__
	/**
	 * a24 = (A+2)/4 = (486662+2)/4 = 121666
	 **/
	const uint64_t a24 = 121666;
	__asm__ __volatile__(
		"movq	%2, %%rdx             \n\t"
		"mulx	 (%1), %%rax, %%r8    \n\t"
		"mulx	8(%1), %%rcx, %%r9    \n\t"
		"movq	%%rax,  (%0)          \n\t"
		"movq	%%rcx, 8(%0)          \n\t"
		"mulx	16(%1), %%rax, %%r10  \n\t"
		"mulx	24(%1), %%rcx, %%r11  \n\t"
		"movq	%%rax, 16(%0)         \n\t"
		"movq	%%rcx, 24(%0)         \n\t"
		"movq   $38, %%rdx            \n\t"
		"mulx	%%r11, %%rax, %%rcx   \n\t"
		"addq	%%rax,   (%0)         \n\t"
		"adcq	%%r8,   8(%0)         \n\t"
		"adcq	%%r9,  16(%0)         \n\t"
		"adcq	%%r10, 24(%0)         \n\t"
	:
	: "r" (*r), "r" (*x), "r" (a24)
	: "cc", "%rax", "%rcx", "%rdx", "%r8", "%r9", "%r10", "%r11"
	);
#else /* Without BMI2 */
	/**
	* TODO: Multiplications using MULQ instruction.
	**/
#endif
}

#define fe25519_nsquare(a,times)\
    counter = times;\
    while(counter-- > 0)\
    {\
        fe25519_square(a,a);\
    }\

void fe25519_invert(argfe25519 r, const argfe25519 x)
{
	fe25519 x0, x1, x2;
	uint64_t counter;

#define T0 x0    //;
#define T1 (*r)  //; /* x^(-1) */
#define T2 x1    //;
#define T3 x2    //;
#define T4 (*x)  //; /* x */

	fe25519_copy(&T1,x);
	fe25519_nsquare(&T1,1);
	fe25519_copy(&T2,&T1);
	fe25519_nsquare(&T2,2);
	fe25519_mul(&T0, x, &T2);
	fe25519_mul(&T1, &T1, &T0);
	fe25519_copy(&T2,&T1);
	fe25519_nsquare(&T2,1);
	fe25519_mul(&T0, &T0, &T2);
	fe25519_copy(&T2,&T0);
	fe25519_nsquare(&T2,5);
	fe25519_mul(&T0, &T0, &T2);
	fe25519_copy(&T2,&T0);
	fe25519_nsquare(&T2,10);
	fe25519_mul(&T2, &T2, &T0);
	fe25519_copy(&T3,&T2);
	fe25519_nsquare(&T3,20);
	fe25519_mul(&T3, &T3, &T2);
	fe25519_nsquare(&T3,10);
	fe25519_mul(&T3, &T3, &T0);
	fe25519_copy(&T0,&T3);
	fe25519_nsquare(&T0,50);
	fe25519_mul(&T0, &T0, &T3);
	fe25519_copy(&T2,&T0);
	fe25519_nsquare(&T2,100);
	fe25519_mul(&T2, &T2, &T0);
	fe25519_nsquare(&T2,50);
	fe25519_mul(&T2, &T2, &T3);
	fe25519_nsquare(&T2,5);
	fe25519_mul(&T1, &T1, &T2);
#undef T0
#undef T1
#undef T2
#undef T3
#undef T4
}

void fe25519_freeze(argfe25519 c)
{
	int64_t last = (((int64_t*)(*c))[3])>>63;
	(*c)[3] &= ((uint64_t)1<<63)-1;
	(*c)[0] += 19 & last;
}

void fe25519_sqrt(argfe25519 r, const argfe25519 a)
{
	fe25519 i, v, x, y, t;
	int j;

	fe25519_add(&x,a,a);
	fe25519_square(&v, &x);
	fe25519_mul(&t, &v, &x);

	for (j = 0; j < 248; j++)
	{
		fe25519_square(&v, &t);
		fe25519_mul(&t, &v, &x);
	}

	fe25519_square(&v, &t);
	fe25519_square(&t, &v);
	fe25519_mul(&v, &t, &x);

	fe25519_square(&y, &v);
	fe25519_mul(&i, &x, &y);
	fe25519_setone(&y);
	fe25519_sub(&i,&i,&y);
	fe25519_mul(&x,&v,a);
	fe25519_mul(r,&x,&i);
	fe25519_freeze(r);
}
