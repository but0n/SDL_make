TARGET=sdlTest
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

all:$(TARGET)
	@echo "$< Build Over----------->"
	./$<
$(TARGET):
	$(CC) $(CFLAGS) -o $@ *.c

.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -f $(BUILDPATH)*
