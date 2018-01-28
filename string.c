 //Jeremy McCormick
 // string.c for
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "string.h"

struct string
    {
    char * value;
    };

STRING * newSTRING(char * x)
    {
    STRING *p = malloc(sizeof(STRING));
    assert(p != 0);
    p->value = x;
    return p;
    }

 
STRING * getINTEGER(INTEGER *v)
    {
    return v->value;
    }

STRING * setSTRING(STRING * v,char * x)
    {
    char *  old = v->value;
    v->value = x;
    return old;
    }

void displaySTRING(void *v,FILE *fp)
    {
    fprintf(fp,"%s",getSTRING(STRING * v));
    }

int compareSTRING(void *v,void *w)
    {
    return strcmp(getSTRING(v), getINTEGER(w));
    }

void
freeSTRING(void *v)
    {
    free(STRING * v);
    }
