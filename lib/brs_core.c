#include <brs_core.h>

int main() {
    // Initialize
    brs_InitModules();
    SDL_RenderClear(((brs_render_conf_t *)brs_module_pool[0]->conf)->camera);

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
    
    // Register sprites
    brs_AddSprite(&tmp, 0);
    brs_AddSprite(&tmp2, 0);
    brs_RenderScene(0);
    SDL_RenderPresent(((brs_render_conf_t *)brs_module_pool[0]->conf)->camera);

    brs_Delay(2000);
    SDL_DestroyTexture(tmp.texture);
    SDL_DestroyTexture(tmp2.texture);


    brs_KillModules();
    return 0;
}