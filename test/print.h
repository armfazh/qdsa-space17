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
#ifndef PRINT_H
#define PRINT_H

#include "../fe25519.h"
#include "../ladder.h"

void print_bytes(uint8_t * A,int num_bytes);
void fe25519_print(const argfe25519 A);
void group_scalar_print(group_scalar *x);
void ecp_print(ecp* p);
void print_key(unsigned char *pk);

#endif
