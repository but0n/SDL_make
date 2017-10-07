#ifndef _BRS_RENDER_H_
#define _BRS_RENDER_H_

// Frameworks
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h> /* for fprintf() */
#include <stdlib.h> /* for atexit() */

typedef struct {
    SDL_Window     *window;
    SDL_Renderer   *camera;
}brs_render_conf_t, *brs_render_conf_tp;

typedef struct brs_obj_s brs_obj_t;

struct brs_pos_s {
    int x;
    int y;
};

struct brs_obj_s {
    SDL_Rect            transform;
    struct brs_pos_s    position;
    struct brs_pos_s    pivot_offset;
    SDL_Surface        *surface;
    SDL_Texture        *texture;
    void               *cont;
};


extern brs_module_t brs_module_render_st;

extern void brs_Delay(unsigned int ms);
extern int brs_CreatObj(const char *path, brs_obj_t *ctx);

#endif