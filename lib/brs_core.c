#include <brs_core.h>

int main() {
    brs_CreateWindow();
    int g_width = 1440;
    int g_height = 900;
    SDL_GL_GetDrawableSize(window, &g_width, &g_height);



	//	create Surface
	SDL_Surface *surface = IMG_Load("../Resources/hello2.png");
	if(!surface) {
		printf("Erro creating surface!\n");
		SDL_DestroyRenderer(camera);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(camera, surface);
	SDL_FreeSurface(surface);
	//	handle error
	if(!tex) {
		printf("Error creating texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(camera);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	//	struct to hold the position and size of the sprite
    SDL_Rect clip;
	SDL_Rect dest;
	SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    dest.w = dest.h = 500;
    dest.x = 500;
    dest.y = 500;
    clip.x = 500;
    clip.y = 500;
    clip.w = 500;
    clip.h = 500;

    // dest.x = (g_width - dest.w) / 2; // Center of horiz

	SDL_RenderClear(camera);
    SDL_RenderCopy(camera, tex, &clip, &dest);
	// SDL_RenderCopy(camera, tex, NULL, &dest);
	SDL_RenderPresent(camera);
    brs_Delay(1000);

	// while(dest.y <= 0) {
	// 	//	clear the window
	// 	SDL_RenderClear(camera);
	// 	dest.y += vector;
	// 	SDL_RenderCopy(camera, tex, &dest, NULL);
	// 	SDL_RenderPresent(camera);
	// 	vector+=a;
	// 	// a+=10;
	// 	// y_pos -= 5;
    //     for(int i = 0; i < 1000/60; i++){
    //         SDL_PumpEvents();
    //         SDL_Delay(1);
    //     }
    // }


	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(camera);
	SDL_DestroyWindow(window);
	SDL_Quit();

    return 0;
}
