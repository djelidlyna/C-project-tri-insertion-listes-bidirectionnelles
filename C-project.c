#include <stdio.h>
#include<malloc.h>
//declaration

 typedef struct Liste Liste;
 typedef Liste * List;
   struct Liste {
  int info;
     List  suiv;
     List pre;
   } ;