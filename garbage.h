/*garbage.h */ 
#ifndef GARBAGE_H
#define GARBAGE_H 

#define GCBlockSize         1024

/* Garbage collector structure */
typedef struct s_garbage{
    int16 capacity;
    int16 size;
    void *p[];
}Garbage;


Garbage *mkgarbage(void);

void addgc(Garbage*,void*); /* helper function to add a garbage  collector*/
Garbage *gc(Garbage*);/* Garbage collector function */


#endif
