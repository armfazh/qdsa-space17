CFLAGS+= -O3 -Wall -Wextra -march=native

all: qdsa_ref qdsa_r2l_ref qdsa_x64 qdsa_r2l_x64

SRC = scalar.c ladder.c dh.c sign.c hash.c
AUX = test/test.c test/print.c test/clocks.c test/random.c

qdsa_ref: fe25519_ref.c  $(SRC) $(AUX)
	$(CC) $(CFLAGS) $^ -o $@ -D__NO_R2L__ -D__FP_REF__

qdsa_r2l_ref: fe25519_ref.c  $(SRC) $(AUX)
	$(CC) $(CFLAGS) $^ -o $@ -D__R2L__ -D__FP_REF__

qdsa_x64: fe25519_x64.c  $(SRC) $(AUX)
	$(CC) $(CFLAGS) $^ -o $@ -D__NO_R2L__ -D__FP_X64__

qdsa_r2l_x64: fe25519_x64.c  $(SRC) $(AUX)
	$(CC) $(CFLAGS) $^ -o $@ -D__R2L__ -D__FP_X64__

.PHONY: clean

clean:
	-rm -f qdsa_ref qdsa_r2l_ref qdsa_x64 qdsa_r2l_x64 

