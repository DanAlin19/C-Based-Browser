#include "prob3.h"

void init(map *m, int cap) {

    m -> elem = (entry**)malloc(cap * sizeof(entry*));
    m -> cap = cap;
    m -> n_elem = 0;
}

void add(map *m, entry *e) {

    if(m -> n_elem == m -> cap) {
        m -> cap *= 2;
        m -> elem = (entry**) realloc(m -> elem, m -> cap * sizeof(entry*));
    }

    m -> elem[m -> n_elem] = e;
    m -> n_elem++;
}

void printEntry1 (const entry *) {

    printf("[%s] = %s\n", char(*) ent -> key, char(*) ent -> value);
}