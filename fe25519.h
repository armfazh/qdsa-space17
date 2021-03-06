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
#ifndef CREF_FE25519_H
#define CREF_FE25519_H

#include <inttypes.h>

typedef uint32_t crypto_uint32;
typedef uint64_t crypto_uint64;

#if defined(__FP_REF__)
#include "fe25519_ref.h"
#elif defined(__FP_X64__)
#include "fe25519_x64.h"
#else
#error "Define __FP_X64__ or  __FP_REF__ variable."
#endif

#endif /* CREF_FE25519_H */
