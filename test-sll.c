    #include <stdio.h>
   #include <stdlib.h>
   #include "sll.h"
   #include "integer.h"

   static void showItems(SLL *items)
       {
       printf("The items are ");
       displaySLL(items,stdout);
       printf(".\n");
       printf("The items (debugged) are ");
       displaySLLdebug(items,stdout);
       printf(".\n");
       }

   int main(void)
       {
       SLL *items = newSLL(&displayINTEGER,&freeINTEGER);
       showItems(items);
       insertSLL(items,0,newINTEGER(3));                   //insert at front    
       insertSLL(items,sizeSLL(items),newINTEGER(2));      //insert at bac
       insertSLL(items,1,newINTEGER(1));                   //insert at middle
       showItems(items);
       printf("The value ");
       INTEGER *i = removeSLL(items,0);                   //remove from front
       displayINTEGER(i,stdout);
       printf(" was removed.\n");
       freeINTEGER(i);
       showItems(items);
       int x = getINTEGER((INTEGER *) getSLL(items,0));    //get the first item
       printf("The first item is %d.\n",x);
       printf("Adding and removing a lot");
       
       for( int i = 0; i< 5000; i++)
       {
         insertSLL(items,0,newINTEGER(i));   
       }
       for( int i = 0; i< 5000; i++)
       {
         removeSLL(items,0,newINTEGER(i));   
       }
       printf("Freeing the list.\n");
       freeSLL(items);
       return 0;
       }
