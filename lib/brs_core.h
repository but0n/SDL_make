#ifndef _BRS_CORE_H_
#define _BRS_CORE_H_

#include <brs_render.h>


struct position {
    int x;
    int y;
};

struct object {
    int                 id;
    int                 width;
    int                 height;
    struct position     pos;
    struct position     pivot_offset;
    void                *cont;
};

// struct object *obj_pool[];



#endif