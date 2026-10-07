/* piehtml.c */
#include "piehtml.h"
#include "tokens.h"
#include "garbage.h"

/*
 * <body>
 *  <b>Text</b>
 * </body>
 *
 * Lexer 
 *
 * Token            Value
 * ----------------------
 *  tagstart        "body"
 *  tagstart        "b"
 *  text            "Text"
 *  tagend          "b"
 *  tagend          "body"
 **/

int main(int argc , char *arg[]){

    Token *t1,*t2,*t3,*t4,*t5,*t6;
    int16 size;
    Token *t;
    Garbage *garb;

    garb = mkgarbage();


    t1 = mktoken(garb,tagstart,$8 "html");
    t2 = mktoken(garb,tagstart,$8 "body");
    t3 = mktoken(garb,text,$8 "hello world");
    t4 = mktoken(garb,selfclosed,$8 "br");
    t5 = mktoken(garb,tagend,$8 "body");
    t6 = mktoken(garb,tagend,$8 "html");

    size = sizeof(Token) * 6;
    t = (Token*)malloc(size);
    assert(t);
    zero($8 t,size);


    t[0] = *t1;
    t[1] = *t2;
    t[2] = *t3;
    t[3] = *t4;
    t[4] = *t5;
    t[5] = *t6;

    Tokens ts = {
        .length = 6,
        .ts = t
    };

    printf("'%s'\n",showtokens(ts));
    gc(garb);


    return 0;
}
