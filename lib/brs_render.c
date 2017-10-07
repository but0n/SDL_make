#include <brs_core.h>

static brs_render_conf_t        brs_render_conf_st;

static unsigned char            brs_CreateWindow(void *conf);
static unsigned char            brs_CloseWindow(void *conf);

brs_module_t brs_module_render_st = {
    (void *)&brs_render_conf_st,
    brs_CreateWindow,
    brs_CloseWindow
};

static unsigned char brs_CreateWindow(void *conf) {
    brs_render_conf_tp arg = conf;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't initialize SDL: %s",
            SDL_GetError()
        );
    }

    if(SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_ALLOW_HIGHDPI, &(arg->window), &(arg->camera))) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't create window and renderer: %s",
            SDL_GetError()
        );
    }
    return 0;
}

static unsigned char brs_CloseWindow(void *conf) {
    brs_render_conf_tp arg = conf;
    SDL_DestroyRenderer(arg->camera);
    SDL_DestroyWindow(arg->window);
    SDL_Quit();
    return 0;
}

// Custom delay function
void brs_Delay(unsigned int ms) {
    for(unsigned int i = 0; i < ms; i++){
        SDL_PumpEvents();
        SDL_Delay(1); // void SDL_Delay(Uint32 ms)
    }
}

int brs_CreatObj(const char *path, brs_obj_t *ctx) {
    SDL_Surface *surface = IMG_Load(path);
    if(!surface) {
        return 1;
    }

    ctx->texture = SDL_CreateTextureFromSurface(brs_render_conf_st.camera, surface);
    SDL_FreeSurface(surface);
    if(!ctx->texture) {
        return 1;
    }

    SDL_QueryTexture(ctx->texture, NULL, NULL, &(ctx->transform.w), &(ctx->transform.h));
    ctx->transform.x = ctx->position.x - ctx->pivot_offset.x;
    ctx->transform.y = ctx->position.y - ctx->pivot_offset.y;
    SDL_RenderClear(brs_render_conf_st.camera);
    SDL_RenderCopy(brs_render_conf_st.camera, ctx->texture, NULL, &(ctx->transform));

    return 0;
}




