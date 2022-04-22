#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int main() {
    site *v;
    v = (struct site*)malloc(3 * sizeof *v);
    int dim;
    char a[100];
    dim = marime(v);
    citire(v,0);
    while(gets(a) != '\n') {
        // for(int i = 0; i < dim; i++)
        //     if(strstr(a,v[i].titlu) != 0)
                printf("%s\n",a);
    }
}
