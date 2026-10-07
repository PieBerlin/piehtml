/* garbage.c */
#include "piehtml.h"
#include "garbage.h"

Garbage *mkgarbage(){
    Garbage *p;
    int16 size;

    size = sizeof(struct s_garbage) * GCBlockSize;
    p = (Garbage*)malloc($i size);
    assert(p);
    zero($8 p,size);

    *p->p =(void*)0;
    p->capacity = GCBlockSize;
    p->size = 0;

    return p;
}

void addgc(Garbage *g,void *ptr){
    int16 size;
    assert(g && ptr);

    if (g->size >= g->capacity){
        size = sizeof(struct s_garbage) * (g->capacity + GCBlockSize);
        g = (Garbage*)realloc(g,$i size);
        assert(g);
        g->capacity += GCBlockSize; 
    }

    g->p[g->size] = ptr;
    g->size++;
    return;
}

Garbage *gc(Garbage *g){
    int16 n;
    Garbage *p;

    for ( n = g->size - 1;n;n--)
        free(g->p[n]);
    free(g);

    p = mkgarbage();

    return p;
}
