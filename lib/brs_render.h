#ifndef _BRS_RENDER_H_
#define _BRS_RENDER_H_

// Frameworks
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h> /* for fprintf() */
#include <stdlib.h> /* for atexit() */

extern SDL_Window      *window;
extern SDL_Renderer    *camera;

extern int brs_CreateWindow();
extern void brs_Delay(unsigned int ms);

#endif