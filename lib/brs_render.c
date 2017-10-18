#include <brs_core.h>

static brs_render_conf_t        brs_render_conf_st;
static brs_scene_pool_t         brs_scene_pool_st;

static unsigned char            brs_CreateWindow(void *conf);
static unsigned char            brs_CloseWindow(void *conf);
static void                     brs_Init_scene_pool(SDL_Renderer *cam);
static void                     brs_DestroyTexture();

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
    brs_Init_scene_pool(arg->camera);
    return 0;
}

static unsigned char brs_CloseWindow(void *conf) {
    brs_render_conf_tp arg = conf;
    brs_DestroyTexture();
    SDL_DestroyRenderer(arg->camera);
    SDL_DestroyWindow(arg->window);
    SDL_Quit();
    return 0;
}

static void brs_DestroyTexture() {
    for(unsigned int i = 0; i < BRS_SCENE_AMOUNT; i++) {
        brs_scene_t    *ctx = &brs_scene_pool_st.scene[i];
        for(int e = 0; e <= ctx->top; e++) {
            SDL_DestroyTexture(ctx->sprites_pool[e]->texture);
        }
    }
}


// Custom delay function
void brs_Delay(unsigned int ms) {
    for(unsigned int i = 0; i < ms; i++){
        SDL_PumpEvents();
        SDL_Delay(1); // void SDL_Delay(Uint32 ms)
    }
}

int brs_CreatSprite(brs_sprite_t *ctx) {
    if(ctx->image_path != NULL) {
        SDL_Surface *surface = IMG_Load(ctx->image_path);
        if(!surface) {
            return 1;
        }

        ctx->texture = SDL_CreateTextureFromSurface(brs_scene_pool_st.camera, surface);
        SDL_FreeSurface(surface);
        if(!ctx->texture) {
            return 1;
        }
        // TODO if ctx->clip == NULL then ...
        SDL_QueryTexture(ctx->texture, NULL, NULL, &(ctx->transform.w), &(ctx->transform.h));
    }

    return 0;
}

static brs_scene_pool_t     brs_scene_pool_st;

// Initialize struct prototypes
static void brs_Init_scene_pool(SDL_Renderer *cam) {
    if(cam == NULL)
        return;
    // Set the pointer to Render
    brs_scene_pool_st.camera = cam;
    // Set stack pointer of each scene (sprites pool)
    for(unsigned int i = 0; i < BRS_SCENE_AMOUNT; i++) {
        brs_scene_pool_st.scene[i].top = -1; // Empty pool
    }
}

void brs_AddSprite(brs_sprite_t *ctx, unsigned char index) {
    if(ctx != NULL && index < BRS_SCENE_AMOUNT) {
        if(ctx->image_path != NULL) {
            // Generate texture
            brs_CreatSprite(ctx);
        }
        // Add current sprite to sprites pool
        brs_scene_t    *scene = &brs_scene_pool_st.scene[index];
        // Check if sprite overflow
        if(scene->top < BRS_SPRITE_AMOUNT-1) {
            scene->sprites_pool[++(scene->top)] = ctx;
        }
    }
}

void brs_RenderScene(unsigned char index) {
    if(index < BRS_SCENE_AMOUNT) {
        SDL_RenderClear(brs_scene_pool_st.camera); // Clean buff

        brs_scene_t    *scene = &brs_scene_pool_st.scene[index];

        for(unsigned int i = 0; i <= scene->top; i++) {
            brs_sprite_t *ctx = scene->sprites_pool[i];
            ctx->transform.x = ctx->position.x - ctx->pivot_offset.x - (ctx->z_index+1)*scene->camera_pos.x;
            ctx->transform.y = ctx->position.y - ctx->pivot_offset.y - (ctx->z_index+1)*scene->camera_pos.y;
            SDL_RenderCopy(brs_scene_pool_st.camera, ctx->texture, NULL, &(ctx->transform));
        }
        SDL_RenderPresent(brs_scene_pool_st.camera);
    }
}

brs_pos_t *brs_CameraPosition(unsigned char index) {
    return &brs_scene_pool_st.scene[index].camera_pos;
}



