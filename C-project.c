#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include<time.h>

//declaration

 typedef struct Liste Liste;
 typedef Liste * ListP;
   struct Liste {
  int info;
     ListP  suiv;
     ListP pre;
   } ;

// Function ajout element a la liste
void addElement(ListP* tete, int v) {
    ListP nouv = (ListP)malloc(sizeof(Liste));
    nouv->info = v;
    nouv->pre = NULL;
    nouv->suiv = NULL;

    if (*tete == NULL) {
        // si liste vide 
        *tete = nouv;
    } else {
        // trouver dernier element de la liste
        ListP dernier = *tete;
        while (dernier->suiv != NULL) {
            dernier = dernier->suiv;
        }

        // ajouter l element a la liste 
        dernier->suiv = nouv;
        nouv->pre = dernier;
    }
}
 
 
 int main(){

    return 0;
}
  
