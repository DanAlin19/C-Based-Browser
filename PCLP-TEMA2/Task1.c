ca#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int main() {
    site *v;
    v = calloc(3 , sizeof *v);
    int dim;
    dim = marime(v);
    citire(v,0);
    for(int i = 0; i < dim; i++) {
        printf("%s %d %s\n",v[i].link,v[i].nr_accesari,v[i].titlu);
    }
    for(int k = 0;k < dim; k++) {
        free(v[k].paragraf);
        v[k].paragraf = NULL;
        free(v[k].site_code);
        v[k].site_code = NULL;
    }
    free(v);
}
