#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct site {
    char link[50];
    int lungime, nr_accesari, checksum;
    char *site_code;
    char titlu[100];
    char *paragraf;
} site;
void citire(site *v, int i);

int marime(site *v);

void sortare (site a, int n, int (*cmp)(site v1, site v2));
 #endif
