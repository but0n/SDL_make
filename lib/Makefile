TARGET=../main
TC=
CC=@echo "CC $@";$(TC)gcc
AR=@echo "AR $@";$(TC)ar

LIBDIR=-I.
COMMONFLAGS=-Wall -std=c99

COMMONFLAGS+=-F/Library/Frameworks
COMMONFLAGS+=-framework SDL2
COMMONFLAGS+=-framework SDL2_image

LIDLIBS+=-lm

CFLAGS=$(COMMONFLAGS) $(LIBDIR)

TARG = $(subst .c,.o,$(wildcard *.c))

lib:app.a
	$(CC) $(CFLAGS) -o $(TARGET) $^

app.a:$(TARG)
	@$(AR) cr $@ $^


.PHONY: clean
clean:
	rm -rf $(TARG) *.a $(TARGET)