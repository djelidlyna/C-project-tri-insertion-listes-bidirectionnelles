#include <stdio.h>
#include<malloc.h>
//declaration

 typedef struct Liste Liste;
 typedef Liste * ListP;
   struct Liste {
  int info;
     ListP  suiv;
     ListP pre;
   } ;

ListP creerElement(int valeur) { 
    ListP nouvelElement = (ListP) malloc(sizeof(Liste));
    nouvelElement->info = valeur;
    nouvelElement->suiv = NULL;
    nouvelElement->pre = NULL;
    return nouvelElement;

void afficherliste(ListP L){ //du premier vers le dernier
    ListP p;
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
