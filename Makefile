CC=gcc
CFLAGS  = -g -Wall -Wextra -Werror

all: test/test

c25519 = obj/fe25519.o \
				 obj/scalar.o \
				 obj/ladder.o \
				 obj/dh.o \
				 obj/sign.o \
				 obj/hash.o

test/test: test/test.c test/print.c obj/c25519.a
	$(CC) $(CFLAGS) $^ -o $@

test/print: test/print.c obj/c25519.a
	$(CC) $(CFLAGS) $^ -o $@

obj/c25519.a: $(c25519)
	$(AR) -ar cr $@ $^

obj/%.o: %.[cS]
	mkdir -p obj/
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean

clean:
	-rm -r obj/*
	-rm -r test/test

run:
	test/test
