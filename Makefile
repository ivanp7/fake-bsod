CC=gcc
CFLAGS=-I/usr/include -L/usr/lib -lncurses

fake-bsod: bsod.cpp bsod.h output.h
	$(CC) -o $@ $< $(CFLAGS)

