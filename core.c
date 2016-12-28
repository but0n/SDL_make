#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h> /* for fprintf() */
#include <stdlib.h> /* for atexit() */

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

int vector = 1;


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
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
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
		SDL_RENDERER_ACCELERATED
	);
	if (!rend) {
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	//	create Surface
	// SDL_Surface *surface = IMG_Load("resources/mos.jpg");
	SDL_Surface *surface = IMG_Load("../Resources/hello.png");
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

	//	struct to hold the position and size of the sprite
	SDL_Rect dest;
	SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

	dest.x = (WINDOW_WIDTH - dest.w) / 2;
	dest.y = -WINDOW_HEIGHT;
	int *vp = &vector;
	while(dest.y <= WINDOW_HEIGHT) {
		//	clear the window
		SDL_RenderClear(rend);
		dest.y += *vp;
		// (*vp) = *(vp) + 1;
		SDL_RenderCopy(rend, tex, NULL, &dest);
		SDL_RenderPresent(rend);

		// y_pos -= 5;
		SDL_Delay(1000/60);
	}
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(window);
	SDL_Quit();

    return 0;
}
