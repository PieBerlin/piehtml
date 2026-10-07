/* helpers.c */
#include "piehtml.h"


int16 stringlen(int8 *str){
    int16 n;
    int8 *p;
    assert(str);

    for (p=str,n=0;*p;n++,p++);
    return n;
}


void stringcopy(int8 *dst,int8 *src , int16 size){
    int16 n;
    int8 *d,*s;

    assert(src && dst && size);

    for (d=dst,s=src, n=size;n;d++,s++,n--)
        *d = *s;

    return;
}


String *scopy(String *s){
    String *p;
    int16 size;
    assert(s && s->length);

    size = sizeof(struct s_string) + s->length;

    p = (String*) malloc($i size);
    assert(p);

    zero($8 p,size);

    p->length = s->length;
    stringcopy(p->data,s->cur,s->length);
    p->cur = p->data;

    return p;

}




