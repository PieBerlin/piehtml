/* tokens.h */ 
#ifndef TOKENS_H
#define TOKENS_H

// Immutable datatype(variable)
typedef struct s_string {
    int16 length;
    int8 *cur;
    int8 data[];
}String;

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

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

typedef enum e_tokentype {
    text = 1,
    tagstart = 2,
    tagend = 3 ,
    selfclosed = 4
}Tokentype;

typedef String Text;

typedef struct s_token{
    Tokentype type;
    union {
        Text texttoken;
        Tagstart start;
        Tagend end;
        Selfclosed self;
    }contents;
}Token;

typedef struct s_tokens {
    int16 length;
    Token *ts;
}Tokens;

#endif // !TOKENS_H
