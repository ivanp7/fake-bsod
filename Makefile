CC=gcc
CFLAGS=-I/usr/include -L/usr/lib -lstdc++ -lncurses

fake-bsod: bsod.cpp output.h
	$(CC) -o $@ $< $(CFLAGS)

