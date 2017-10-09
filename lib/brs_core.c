#include <brs_core.h>

int main() {
    // Initialize
    brs_InitModules();
    SDL_RenderClear(((brs_render_conf_t *)brs_module_pool[0]->conf)->camera);

    // Creat Scene
    brs_scene_t scene_1 = {
        {NULL},
        -1,
        {
            0,
            0
        }
    };
    // Register current scene
    brs_AddScene(&scene_1);

    // Creat Sprite

    brs_sprite_t tmp;
    tmp.image_path = "../Resources/hello.png";
    // tmp.position = {0,0};
    // tmp.pivot_offset = {0,0};
    tmp.position.x = 0;
    tmp.position.y = 0;
    tmp.pivot_offset.x = 0;
    tmp.pivot_offset.y = 0;

    brs_sprite_t tmp2;
    tmp2.image_path = "../Resources/hello.png";
    // tmp.position = {0,0};
    // tmp.pivot_offset = {0,0};
    tmp2.position.x = 700;
    tmp2.position.y = 700;
    tmp2.pivot_offset.x = 256;
    tmp2.pivot_offset.y = 256;

    brs_CreatSprite(&tmp);
    brs_CreatSprite(&tmp2);
    SDL_RenderPresent(((brs_render_conf_t *)brs_module_pool[0]->conf)->camera);

    brs_Delay(2000);
    SDL_DestroyTexture(tmp.texture);

    brs_KillModules();
    return 0;
}
// int main() {
//     brs_InitModules();
//
//     // int g_width = 1440;
//     // int g_height = 900;
//     // SDL_GL_GetDrawableSize(((brs_render_conf_t *)brs_module_pool[0]->conf)->window, &g_width, &g_height);
//     SDL_RenderClear(((brs_render_conf_t *)brs_module_pool[0]->conf)->camera);
//
//
//     brs_sprite_t sprite;
//     sprite.image_path = "../Resources/hello.png";
//     sprite.position.x = 0;
//     sprite.position.y = 0;
//     sprite.pivot_offset.x = 0;
//     sprite.pivot_offset.y = 0;
//     brs_CreatSprite(&sprite);
//
//     brs_sprite_t sprite2 = {
//         {},
//         {
//             800,
//             0
//         },
//         {},
//         NULL,
//         "../Resources/mos.jpg",
//         0,
//         NULL
//     };
//     brs_CreatSprite(&sprite2);
//
//
// 	SDL_RenderPresent(((brs_render_conf_t *)brs_module_pool[0]->conf)->camera);
//     brs_Delay(1000);
//
// 	// while(dest.y <= 0) {
// 	// 	//	clear the brs_render_conf_st.window
// 	// 	SDL_RenderClear(brs_render_conf_st.camera);
// 	// 	dest.y += vector;
// 	// 	SDL_RenderCopy(brs_render_conf_st.camera, tex, &dest, NULL);
// 	// 	SDL_RenderPresent(brs_render_conf_st.camera);
// 	// 	vector+=a;
// 	// 	// a+=10;
// 	// 	// y_pos -= 5;
//     //     for(int i = 0; i < 1000/60; i++){
//     //         SDL_PumpEvents();
//     //         SDL_Delay(1);
//     //     }
//     // }
//
//
//     SDL_DestroyTexture(sprite.texture);
// 	SDL_DestroyTexture(sprite2.texture);
//     brs_KillModules();
//
//     return 0;
// }

