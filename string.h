#ifndef __STRING_INCLUDED__
#define __STRING_INCLUDED__

typedef struct string STRING;

extern STRING * newSTRING(char * x);
extern STRING * getINTEGER(INTEGER *v);
extern STRING * setSTRING(STRING * v,char * x);
extern void displaySTRING(void *v,FILE *fp);
extern int compareSTRING(void *v,void *w);
extern void freeSTRING(void *v);

