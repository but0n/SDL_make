#include <SDL2/SDL.h>
#include <stdio.h> /* for fprintf() */
#include <stdlib.h> /* for atexit() */

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)) {
        printf("\nUnable to initialize SDL:  %s\n", SDL_GetError());
        return 1;
    }
	printf("SDL initialized.\n");
	SDL_Quit();
	printf("Quiting....\n");

    return 0;
}
