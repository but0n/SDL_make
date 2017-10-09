#ifndef _BRS_RENDER_H_
#define _BRS_RENDER_H_

// Frameworks
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h> /* for fprintf() */
#include <stdlib.h> /* for atexit() */

typedef struct {
    SDL_Window         *window;
    SDL_Renderer       *camera;
}brs_render_conf_t, *brs_render_conf_tp;


typedef struct {
    int x;
    int y;
}brs_pos_t;

typedef struct {
    SDL_Rect            transform;      // Render Position
    brs_pos_t           position;       // Rigidbody Position
    brs_pos_t           pivot_offset;   // Pivot Offset
    SDL_Texture        *texture;
    char               *image_path;
    char                z_index;        // Different layer with different scroll speed, based on this index value
    char                fps;            // Frame Per Second
    void               *cont;
}brs_sprite_t;

#define BRS_SPRITE_AMOUNT   50

typedef struct {
    brs_sprite_t       *sprites_pool[BRS_SPRITE_AMOUNT];
    int                 top;
    brs_pos_t           camera_pos;
}brs_scene_t;

#define BRS_SCENE_AMOUNT    3
typedef struct {
    brs_scene_t        *scene[BRS_SCENE_AMOUNT];
    int                 top;
}brs_scene_pool_t;

#define CREAT_SCENE(name)

extern brs_module_t     brs_module_render_st;

extern void brs_Delay(unsigned int ms);
extern int brs_CreatSprite(brs_sprite_t *ctx);
extern void brs_AddScene(brs_scene_t *ctx);

#endif