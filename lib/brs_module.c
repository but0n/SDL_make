#include <brs_core.h>

brs_module_t       *brs_module_pool[] = {
    &brs_module_render_st,
    NULL
};

void brs_InitModules() {
    brs_module_t      **this = &brs_module_pool[0];
    for(; *this != NULL; this++) {
        (*this)->Init((*this)->conf);
    }
}

void brs_KillModules() {
    int                 amount = sizeof(brs_module_pool) / sizeof(brs_module_pool[0]) - 1;
    brs_module_t      **this;
    for(; amount > 0;) {
        this = &brs_module_pool[--amount];
        if(*this != NULL)
            (*this)->Exit((*this)->conf);
    }
}


