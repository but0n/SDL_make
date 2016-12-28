TARGET=SDL_Test
CC=gcc-5
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

all:install
	@echo "$< Build Over----------->"
	@echo "Running...."

$(TARGET):*.c
	$(CC) $(CFLAGS) -o $@ $<

install:$(TARGET)
	@echo "$@ing------------------->"
	mkdir -p $(APPPATH)/Contents/{MacOS,Resources}
	cp $< $(APPPATH)/Contents/MacOS
	@echo "Loading Frameworks------>"
	cp -R /Library/Frameworks/SDL2.framework $(APPPATH)/Contents/MacOS/
	cp -R /Library/Frameworks/SDL2_image.framework $(APPPATH)/Contents/MacOS/
	cp Info.plist $(APPPATH)/Contents/

.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -rf $(BUILDPATH)/*
