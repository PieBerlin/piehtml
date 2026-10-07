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
Token *mktoken(Garbage *g,Tokentype type,int8 *value){
    void *ptr;
    Token *ret;

    ret = (Token*)0;
    switch(type){
        case text: 
            ret = mktext(value);
            break;
        case tagstart: 
            ret = mktagstart(value);
            break;
        case tagend: 
            ret = mktagend(value);
            break;
        case selfclosed: 
            ret = mkselfclosed(value);
            break;
        default:
            fprintf(stderr, "mktoken(): bad input\n");
            exit(-1);

            break;
    }
    if (!ret)
        return (Token*)0;
    ptr = ret->contents.texttoken;
    addgc(g,ptr);

    return ret;
}
Token *mktagstart(int8 *value){
    int16 size;
    Tagstart *p;
    Token *ret;
    
    p = (Tagstart*)malloc(sizeof(struct s_tagstart));
    assert(p);
    size = stringlen(value);
    zero($8 p,sizeof(struct s_tagstart));
    stringcopy(p->value,value,size);

    static Token html = {
        .type = tagstart
    };
    html.contents.start = p;
    ret = &html;
    return ret;
}
Token *mktagend(int8 *value){
    int16 size;
    Tagend *p;
    Token *ret;

    
    p = (Tagend*)malloc(sizeof(struct s_tagend));
    assert(p);
    size = stringlen(value);
    zero($8 p,sizeof(struct s_tagend));
    stringcopy(p->value,value,size);

    static Token html = {
        .type = tagend
    };
    html.contents.end = p;
    ret = &html;
    return ret;
}
Token *mkselfclosed(int8 *value){
    int16 size;
    Selfclosed *p;
    Token *ret;
    
    p = (Selfclosed*)malloc(sizeof(struct s_selfclosed));
    assert(p);
    size = stringlen(value);
    zero($8 p,sizeof(struct s_selfclosed));
    stringcopy(p->value,value,size);

    static Token html = {
        .type = selfclosed
    };
    html.contents.self = p;
    ret = &html;
    return ret;
}
Token *mktext(int8 *value){
    int16 msize,size;
    Text *p;
    Token *ret;
    
    size = stringlen(value);
    msize = sizeof(struct s_texttoken) + size;
    p = (Text*)malloc(msize);
    assert(p);
    zero($8 p,msize);
    stringcopy(p->value,value,size);

    static Token html = {
        .type = text
    };
    html.contents.texttoken =p;
    ret = &html;
    return ret;
}



