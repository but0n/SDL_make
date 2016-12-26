TARGET=sdlTest
CC=gcc-5
LIBDIR=-I.
COMMONFLAGS=-Wall -std=c99
COMMONFLAGS+=-F/Library/Frameworks
COMMONFLAGS+=-framework SDL2
COMMONFLAGS+=-framework SDL2_image

LIDLIBS+=-lm

CFLAGS=$(COMMONFLAGS) $(LIBDIR)

BUILDPATH=build/
OBJS=$(BUILDPATH)core


all:$(TARGET)
	@echo "$< Build Over----------->"
	./$<
$(TARGET):*.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -f $(BUILDPATH)*
