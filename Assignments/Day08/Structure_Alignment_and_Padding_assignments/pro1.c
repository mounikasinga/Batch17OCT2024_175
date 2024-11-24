#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MODULE_LENGTH   10
#define FAILURE   1
#define SUCCESS   0
#define MAX_MODULE_NAME		20
#define FREE(x) \
    if (x)    \
    {        \
        free(x);    \
        x = NULL;    \
    }
typedef struct config
{
    char *module;
    int portcount;
} CONFIG;
int setconfig(CONFIG *cfg, int portcnt, char *mname)
{
    int ret = FAILURE;

    cfg->module = (char*)malloc(sizeof(char) * (strlen(mname) + 1));
    if (cfg->module)
    {
        strcpy(cfg->module, mname);
        cfg->portcount = portcnt;

        printf("\nsetconfig:  module:%s, portcount:%d", cfg->module, cfg->portcount);
        ret = SUCCESS;
    }
    return ret;
}
void dump_hex(char *buf, size_t sz)
{
    size_t i = 0;
    char *ptr = buf;

    printf("\nDump_hex:\n ");
    for (i = 0; i < sz; i++)
    {
        printf("%x ", *(ptr + i));
    }
    printf("\nEnd of Data, sz:%d, i:%d", (int)sz, (int)i);
}
int get_portcount(void *cfg)
{
    CONFIG *cfgp = (CONFIG*)cfg;
    int portcnt = cfgp->portcount;

    printf("\nget_portcount:port:%d", portcnt);

    return portcnt;
}
char *get_module(void *cfg)
{
    CONFIG *cfgp = (CONFIG*)cfg;
    char *module = cfgp->module;

    if (module)
    {
        printf("\nget_module:%s", module);
    }
    return module;
}
void displ(void *cfg)
{
    int portcnt = get_portcount(cfg);
    char *mod = get_module(cfg);

    printf("\nReading config: %s %d", mod, portcnt);
}
int main()
{
    CONFIG *cfg = NULL;
    int ret = FAILURE;
    cfg = malloc(sizeof(CONFIG));
    if (cfg == NULL)
    {
        printf("\nMemory allocation failed");
        exit(FAILURE);
    }
    memset(cfg, 0, sizeof(CONFIG));
    printf("\nTo Set the config module module:DNS, portcount:20");
    ret = setconfig(cfg, 20, "DNS");
    displ(cfg);
    FREE(cfg->module);
    FREE(cfg);

    return SUCCESS;
}

