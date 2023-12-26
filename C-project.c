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
void afficherliste(Listo L){ //du premier vers le dernier
    Listo p;
    p=L;
    printf("l'affichage de la liste du premier element vers le dernier");
    printf("debuuut->");
    while(p!=NULL){
        printf("%d",p->info);
        p=p->suiv;
    }
    printf("Null");
}
 int main(){

  return 0;
 }
