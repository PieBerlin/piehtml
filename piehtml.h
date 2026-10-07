/*piehtml.h*/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <pieutils.h>
#include <stdlib.h>
#include "tokens.h"

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



// for typecasting
#define $8 (int8*)
#define $c (char *)
#define $16 (int16)
#define $32 (int32)
#define $64 (int64)
#define $i (int)


#define sdestroy(s) free(s)

typedef struct s_tuple{
    String *s;
    int8 c;
}Tuple;


/* constructor function */
String *mkstring(int8*);


/* helper functions */
int16 stringlen(int8*);
void stringcopy(int8*,int8*,int16);
String *scopy(String*);

Tuple get(String*);
int main(int, char **);
