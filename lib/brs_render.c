#include <brs_core.h>

SDL_Window      *window;
SDL_Renderer    *camera;

int brs_CreateWindow() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't initialize SDL: %s",
            SDL_GetError()
        );
    }

    if(SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_ALLOW_HIGHDPI, &window, &camera)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't create window and renderer: %s",
            SDL_GetError()
        );
    }
}
// Custom delay function
void brs_Delay(unsigned int ms) {
    for(unsigned int i = 0; i < ms; i++){
        SDL_PumpEvents();
        SDL_Delay(1); // void SDL_Delay(Uint32 ms)
    }
}




