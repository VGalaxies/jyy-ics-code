.PHONY: run clean test

CFLAGS = -Wall -Werror -std=c11 -O2
CC = gcc
LD = gcc

yemu: yemu.o idex.o
	$(LD) $(LDFLAGS) -o yemu yemu.o idex.o

yemu.o: yemu.c yemu.h
	$(CC) $(CFLAGS) -c -o yemu.o yemu.c

idex.o: idex.c yemu.h
	$(CC) $(CFLAGS) -c -o idex.o idex.c

run: yemu
	@./yemu

clean:
	rm -f test yemu *.o

test: yemu
	$(CC) $(CFLAGS) -o test idex.o test.c && ./test
