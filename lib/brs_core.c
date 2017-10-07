#include <brs_core.h>

int main() {
    brs_InitModules();

    int g_width = 1440;
    int g_height = 900;
    SDL_GL_GetDrawableSize(((brs_render_conf_t *)brs_module_pool[0]->conf)->window, &g_width, &g_height);


    struct brs_obj_s sprite;
    sprite.position.x = 100;
    sprite.position.y = 100;
    sprite.pivot_offset.x = 0;
    sprite.pivot_offset.y = 0;
    brs_CreatObj("../Resources/hello.png", &sprite);
    
	SDL_RenderPresent(((brs_render_conf_t *)brs_module_pool[0]->conf)->camera);
    brs_Delay(1000);

	// while(dest.y <= 0) {
	// 	//	clear the brs_render_conf_st.window
	// 	SDL_RenderClear(brs_render_conf_st.camera);
	// 	dest.y += vector;
	// 	SDL_RenderCopy(brs_render_conf_st.camera, tex, &dest, NULL);
	// 	SDL_RenderPresent(brs_render_conf_st.camera);
	// 	vector+=a;
	// 	// a+=10;
	// 	// y_pos -= 5;
    //     for(int i = 0; i < 1000/60; i++){
    //         SDL_PumpEvents();
    //         SDL_Delay(1);
    //     }
    // }


	SDL_DestroyTexture(sprite.texture);
    brs_KillModules();

    return 0;
}
