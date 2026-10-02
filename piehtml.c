/* piehtml.c */
#include "piehtml.h"

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
    Tuple t;
    String *s;
    int8 c;

    s = mkstring($8 "Hello world");
    t = get(s);

    if (!t.c){
        printf("Error\n");
        return -1;
    }

    c = t.c;

    printf("c = '%c'\nnew = '%s'\n",c,t.s->cur);
    return 0;
}
