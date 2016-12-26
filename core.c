#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h> /* for fprintf() */
#include <stdlib.h> /* for atexit() */

int main() {
	SDL_Window *window;

    if (SDL_Init(SDL_INIT_VIDEO)) {
        printf("\nUnable to initialize SDL:  %s\n", SDL_GetError());
        return 1;
    }

	window = SDL_CreateWindow(
		"Hello",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		0
	);

	//	handle screen
	//	Initialize the display in a 640x480 8-bit palettized mode
	//	requesting a software surface
	if (!window) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
	}

	//	create Render
	SDL_Renderer *rend = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	if (!rend) {
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	//	create Surface
	SDL_Surface *surface = IMG_Load("resources/hello.png");
	if(!surface) {
		printf("Erro creating surface!\n");
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	//	handle error
	if(!tex) {
		printf("Error creating texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	//	clear the window
	SDL_RenderClear(rend);

	SDL_RenderCopy(rend, tex, NULL, NULL);
	SDL_RenderPresent(rend);

	SDL_Delay(5000);

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(window);
	SDL_Quit();

	// screen = SDL_SetVideoMode(640, 480, 8);
	// if (screen == NULL) {
	// 	printf("\nCoundn't set 640x480x8 video mode:\t%s", SDL_GetError());
	// 	return 1;
	// }

    return 0;
}
