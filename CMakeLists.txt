#####
# Copyright (c) 2017 Armando Faz <armfazh@ic.unicamp.br>.
# Institute of Computing.
# University of Campinas, Brazil.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#####
cmake_minimum_required(VERSION 3.4)
project(qdsa-space2017 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall -Wextra -march=native -mtune=native")
set(SOURCE_FILES
		fe25519.h
		ladder.c          ladder.h
		scalar.c          scalar.h
		hash.c            hash.h
		sign.c            sign.h
		dh.c              dh.h
		test/print.c      test/print.h
		test/random.c     test/random.h
		test/clocks.c     test/clocks.h
		test/test.c
)

add_executable(qdsa_ref     fe25519_ref.c fe25519_ref.h            ${SOURCE_FILES})
add_executable(qdsa_r2l_ref fe25519_ref.c fe25519_ref.h table_8k.h ${SOURCE_FILES})
add_executable(qdsa_x64     fe25519_x64.c fe25519_x64.h            ${SOURCE_FILES})
add_executable(qdsa_r2l_x64 fe25519_x64.c fe25519_x64.h table_8k.h ${SOURCE_FILES})

target_compile_definitions(qdsa_ref     PRIVATE -D__NO_R2L__ -D__FP_REF__)
target_compile_definitions(qdsa_r2l_ref PRIVATE -D__R2L__    -D__FP_REF__)
target_compile_definitions(qdsa_x64     PRIVATE -D__NO_R2L__ -D__FP_X64__)
target_compile_definitions(qdsa_r2l_x64 PRIVATE -D__R2L__    -D__FP_X64__)
