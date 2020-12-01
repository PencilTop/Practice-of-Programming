#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameral Nameral;
struct Nameral {
    char    *name;
    int      value;
};

struct NVtab {
    int     nval;
    int     max;
    Nameral *nameral;
} nvtab;

enum { NVINIT = 1, NVGROW = 2 };

int addname(Nameral);
int delname(char*);

int addname(Nameral newname) {
    Nameral *nvp;
    if (nvtab.nameral == NULL) {
        nvtab.nameral = (Nameral *) malloc(NVINIT * sizeof(Nameral));
        if (nvtab.nameral == NULL) 
            return -1;
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) {
        nvp = (Nameral *) realloc(nvtab.nameral, (NVGROW * nvtab.max) * sizeof(Nameral));
        if (nvp == NULL)
            return -1;
        nvtab.max *= NVGROW;
        nvtab.nameral = nvp;
    }
    nvtab.nameral[nvtab.nval] = newname;
    return nvtab.nval++;
}

int delname(char *name) {
    for (int i = 0; i < nvtab.nval; i++) {
        if (strcmp(nvtab.nameral[i].name, name) == 0) {
            memmove(nvtab.nameral + i, nvtab.nameral + i + 1), (nvtab.nval - (i + 1) * sizeof(Nameral));
            nvtab.nval--;
            return 1;
        }
    }
    return 0;
}