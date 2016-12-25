CC=gcc
LIBDIR=
COMMONFLAGS=-Wall -std=c99
COMMONFLAGS+=-F/Library/Frameworks
COMMONFLAGS+=-framework SDL2

LIDLIBS+=-lm

CFLAGS=$(COMMONFLAGS) $(LIBDIR)
CFLAGS+=-o

BUILDPATH=build/
OBJS=$(BUILDPATH)+core

EXE=setup.app
all:
	$(CC) $(CFLAGS) $(OBJS) core.c
	# $(CC) -F/Library/Frameworks -framework SDL2 -Wall -o $(EXE) core.c
.PHONY: clean
clean:
	rm $(EXE)
