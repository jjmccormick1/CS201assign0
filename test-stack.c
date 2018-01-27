    #include <stdio.h>
   #include <stdlib.h>
   #include "sll.h"
   #include "integer.h"

   static void showItems(SLL *items)
       {
       printf("The items are ");
       displaySTACK(items,stdout);
       printf(".\n");
       printf("The items (debugged) are ");
       displaySTACKdebug(items,stdout);
       printf(".\n");
       }

   int main(void)
       {
       SLL *items = newSLL(&displayINTEGER,&freeINTEGER);
       showItems(items);
       push(items,newINTEGER(3));                   //insert at front    
       push(items,newINTEGER(2));      //insert at bac
       push(items,newINTEGER(1));                   //insert at middle
       showItems(items);
       printf("The value ");
       INTEGER *i = removeSLL(items,0);                   //remove from front
       displayINTEGER(i,stdout);
       printf(" was removed.\n");
       freeINTEGER(i);
       showItems(items);
       int x = getINTEGER((INTEGER *) peekSTACK(items));    //get the first item
       printf("The first item is %d.\n",x);
       printf("Adding and removing a lot");
       
       for( int i = 0; i< 5000; i++)
       {
         push(items,newINTEGER(i));   
       }
       for( int i = 0; i< 5000; i++)
       {
         pop(items,newINTEGER(i));   
       }
       printf("Freeing the list.\n");
       freeSTACK(items);
       return 0;
       }
