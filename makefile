CC=gcc
LIBDIR=-I.
COMMONFLAGS=-Wall -std=c99
COMMONFLAGS+=-F/Library/Frameworks
COMMONFLAGS+=-framework SDL2

LIDLIBS+=-lm

CFLAGS=$(COMMONFLAGS) $(LIBDIR)

BUILDPATH=build/
OBJS=$(BUILDPATH)core

EXE=setup.app
all:
	$(CC) $(CFLAGS) -o $(OBJS) *.c
	./$(OBJS)
.PHONY: clean
clean:
	rm $(BUILDPATH)*
