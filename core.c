#include <SDL2/SDL.h>
#include <stdio.h> /* for fprintf() */
#include <stdlib.h> /* for atexit() */

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError()
               );
        return 1;
    }
    atexit(SDL_Quit);

    /* ... */

    return 0;
}
