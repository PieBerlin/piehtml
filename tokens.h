/* tokens.h */ 
#ifndef TOKENS_H
#define TOKENS_H

#include "piehtml.h"
#include "garbage.h"


typedef enum e_tag{
    html = 1 ,
    body = 2,
    b = 3 ,/* bold */
    br = 4 /* break */
}Tag;

typedef struct s_tagstart{
    Tag type;
    // we'll add attributes later
    // Attributes attrs;
    int8 value[];  
}Tagstart;


typedef struct s_tagend{
    Tag type;
    int8 value[];
}Tagend;


typedef struct s_selfclosed{
    Tag type;
    int8 value[];
}Selfclosed;

typedef struct s_texttoken{
    Tag type;
    int8 value[];
}Text;

typedef enum e_tokentype {
    text = 1,
    tagstart = 2,
    tagend = 3 ,
    selfclosed = 4
}Tokentype;


typedef struct s_token{
    Tokentype type;
    union {
        Text *texttoken;
        Tagstart *start;
        Tagend *end;
        Selfclosed *self;
    }contents;
}Token;

typedef struct s_tokens {
    int16 length;
    Token *ts;
}Tokens;

int8 *showtoken(Token);
int8 *showtokens(Tokens);

#define destroytoken(t)     free(t)

#define destroytokens(x) do{ \
    int16 _n; \
    for (_n = 0; _n < (x).length; _n++) \
        destroytoken((Text *)(x).ts[_n].contents.texttoken);   \
    free((x).ts);                   \
}while (false);


/* constructors */
Token *mktoken(Garbage*,Tokentype,int8*);
Token *mktext(int8*);
Token *mktagstart(int8*);
Token *mkselfclosed(int8*);
Token *mktagend(int8*);

#endif // !TOKENS_H



