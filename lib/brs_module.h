#ifndef _BRS_MODULE_S_
#define _BRS_MODULE_S_


struct brs_module_s {
    void               *conf;
    unsigned char     (*Init)(void *conf);
    unsigned char     (*Exit)(void *conf);
};

extern brs_module_t        *brs_module_pool[];

extern void brs_InitModules();
extern void brs_KillModules();

#endif
