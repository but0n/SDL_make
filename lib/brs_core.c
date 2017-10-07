#include <brs_core.h>

int main() {
    brs_InitModules();

    // int g_width = 1440;
    // int g_height = 900;
    // SDL_GL_GetDrawableSize(((brs_render_conf_t *)brs_module_pool[0]->conf)->window, &g_width, &g_height);
    SDL_RenderClear(((brs_render_conf_t *)brs_module_pool[0]->conf)->camera);


    brs_sprite_t sprite;
    sprite.image_path = "../Resources/hello.png";
    sprite.position.x = 0;
    sprite.position.y = 0;
    sprite.pivot_offset.x = 0;
    sprite.pivot_offset.y = 0;
    brs_CreatSprite(&sprite);

    brs_sprite_t sprite2;
    sprite2.image_path = "../Resources/mos.jpg";
    sprite2.position.x = 500;
    sprite2.position.y = 0;
    sprite2.pivot_offset.x = 0;
    sprite2.pivot_offset.y = 0;
    brs_CreatSprite(&sprite2);


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
	SDL_DestroyTexture(sprite2.texture);
    brs_KillModules();

    return 0;
}
