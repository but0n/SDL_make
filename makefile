CC=gcc
EXE=setup.app
all: core.c
	$(CC) -F/Library/Frameworks -framework SDL2 -Wall -o $(EXE) core.c
.PHONY: clean
clean:
	rm $(EXE)
