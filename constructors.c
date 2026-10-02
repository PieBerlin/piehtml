/* constructors.c */ 

#include "piehtml.h"

String *mkstring(int8 *str){
    String *p;
    int16 n,size;
    
    assert(str);
    n = stringlen(str);;
    assert(n);


    size = sizeof(struct s_string) + n;

    p = (String*) malloc(size);
    assert(p);
    zero($8 p,size);
    p->length = n ;
    stringcopy(p->data,str,n);
    p->cur = p->data;
    return p;
}

Tuple get(String *s){
    String *new;
    int8 c;

    assert(s);
    if (!s->length)
        goto fail;

    c = *s->cur;
    new = scopy(s);
    if (!new)
        goto fail;

    new->cur++;
    new->length--;

    Tuple ret = {
        .s = new,
        .c = c
    };
    sdestroy(s);
    return ret;

fail:
    Tuple err = {0};
    return err;


}
