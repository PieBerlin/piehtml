#include "piehtml.h"
#include "tokens.h"


int8 *showtoken(Token token){
    int8 *ret;
    static int8 tmp[256];

    assert(token.type);

    ret = tmp;
    zero(tmp,256);

    switch(token.type){

        case text: 
            snprintf($c tmp,255,"%s",token.contents.texttoken->value);
            break;
        case tagstart: 
            snprintf($c tmp,255,"<%s>",token.contents.start->value);
            break;
        case tagend: 
            snprintf($c tmp,255,"</%s>",token.contents.end->value);
            break;
        case selfclosed: 
            snprintf($c tmp,255,"<%s />",token.contents.self->value);
            break;
        default:
            break;
    }
    return ret;
}


int8 *showtokens(Tokens tokens){
    int8 *p, *cur;
    static int8 buf[20480];
    int16 total,n,i;
    Token *t;

    total = 0;
    cur = buf;
    zero(buf,sizeof(buf));

    for (i = tokens.length, t=tokens.ts; i ;i-- , t++){
        p = showtoken(*t);
        if (!t)
            break;
        if (!(*p))
            continue;
        
        n = stringlen(p);
        total += n;
        if (total >= sizeof(buf))
            break;
        stringcopy(cur, p , n);
        cur += n;

    }
    return buf;

}
