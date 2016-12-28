TARGET=SDL_Test
CC=gcc
LIBDIR=-I.
COMMONFLAGS=-Wall -std=c99
COMMONFLAGS+=-F/Library/Frameworks
COMMONFLAGS+=-framework SDL2
COMMONFLAGS+=-framework SDL2_image

LIDLIBS+=-lm

CFLAGS=$(COMMONFLAGS) $(LIBDIR)

BUILDPATH=build
OBJS=$(BUILDPATH)core

APPPATH=$(BUILDPATH)/$(TARGET).app
#	Custom TTY
CUTLINE=------------------------------------------------------------->
TTY_NONE=\033[m
TTY_RED=\033[1;31m
TTY_GREEN=\033[1;32m
TTY_PURPLE=\033[1;35m

all:install
	@echo "$< Build Over $(CUTLINE) $(TTY_PURPLE)"
	@echo "Running...."
	open $(APPPATH)
	@echo "$(TTY_NONE)"

$(TARGET):*.c
	@echo "Compiling $< $(CUTLINE) $(TTY_RED)"
	$(CC) $(CFLAGS) -o $@ $<
	@echo "$(TTY_NONE)"

install:$(TARGET) $(APPPATH)/Contents/MacOS/SDL2.framework
	@echo "$@ing $(CUTLINE)"
	cp $< $(APPPATH)/Contents/MacOS

$(APPPATH)/Contents/MacOS/SDL2.framework:
	@echo "Loading Frameworks $(CUTLINE) $(TTY_GREEN)"
	mkdir -p $(APPPATH)/Contents/{MacOS,Resources}
	cp -R /Library/Frameworks/SDL2.framework $(APPPATH)/Contents/MacOS/
	cp -R /Library/Frameworks/SDL2_image.framework $(APPPATH)/Contents/MacOS/
	cp Info.plist $(APPPATH)/Contents/
	cp -R Resources $(APPPATH)/Contents/
	@echo "$(TTY_NONE)"



.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -rf $(BUILDPATH)/*
