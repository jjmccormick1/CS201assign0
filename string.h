 
#ifndef __INTEGER_H__
#define __INTEGER_H__

#include <stdio.h>

typedef struct STRING STRING;

STRING *newSTRING(int);
extern int getSTRING(STRING *);
extern int setSTRING(STRING *,int);
extern int compareSTRING(void *,void *);
extern void displaySTRING(void *,FILE *);
extern void freeSTRING(void *);

#endif
