#include <stdio.h>
   #include <stdlib.h>
   #include "dll.h"
   #include "integer.h"

   static void showItems(DLL *items)
       {
       printf("The items are ");
       displayDLL(items,stdout);
       printf(".\n");
       printf("The items (debugged) are ");
       displaySLLdebug(items,stdout);
       printf(".\n");
       }

   int main(int argc,char **argv)
       {
        DLL *items = newDLL(displayINTEGER,freeINTEGER);
       showItems(items);
       insertDLL(items,0,newINTEGER(3));                   //insert at front
       insertDLL(items,sizeSLL(items),newINTEGER(2));      //insert at back
       insertDLL(items,1,newINTEGER(1));                   //insert at middle
       showItems(items);
       printf("The value ");
       INTEGER *i = removeDLL(items,0);                   //remove from front
       displayINTEGER(i,stdout);
       printf(" was removed.\n");
       freeINTEGER(i);
       showItems(items);
       int x = getINTEGER((INTEGER *) getDLL(items,0));    //get the first item
       printf("The first item is %d.\n",x);
       printf("Freeing the list.\n");
       freeDLL(items);
       return 0;
       }
