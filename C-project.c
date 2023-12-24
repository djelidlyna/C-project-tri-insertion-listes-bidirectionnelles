#include <stdio.h>
#include<malloc.h>
//declaration

 typedef struct Liste Liste;
 typedef Liste * Listo;
   struct Liste {
  int info;
     Listo  suiv;
     Listo pre;
   } ;