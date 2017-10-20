#include <brs_core.h>

int main() {
    // Initialize
    brs_InitModules();

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
    tmp2.position.x = 0;
    tmp2.position.y = 1000;
    tmp2.pivot_offset.x = 256;
    tmp2.pivot_offset.y = 256;
    tmp2.z_index = 1;

    brs_sprite_t map = {
        .image_path = "../Resources/test_background.png",
        .z_index = -1
    };
    brs_AddSprite(&map, 0);

    // Register sprites
    brs_AddSprite(&tmp2, 0);

    brs_AddSprite(&tmp, 0);

    int force = 4; // 3 pixel per frame
    for(int i = 0; i < 100; i++) {
        brs_RenderScene(0);
        brs_CameraPosition(0)->x -= i*i/1000*force;
        brs_Delay(100/6);
    }
    for(int i = 100; i > 0; i--) {
        brs_RenderScene(0);
        brs_CameraPosition(0)->x -= i*i/1000*force;
        brs_Delay(100/6);
    }

    brs_KillModules();
    return 0;
}