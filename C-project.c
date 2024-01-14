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
//FONCTION pour insérer un élément dans la liste
 void insertElementAtPosition(ListP* tete, int v, int position) {
    ListP nouv = (ListP)malloc(sizeof(Liste));
    nouv->info = v;
    nouv->pre = NULL;
    nouv->suiv = NULL;

    if (position <= 1) {
        // Inserer a la tete
        nouv->suiv = *tete;
        if (*tete != NULL) {
            (*tete)->pre= nouv;
        }
        *tete = nouv;
    } else {
        // trouver la position
        ListP cur = *tete;
        int count = 1;

        while (cur != NULL && count < position) {
            cur = cur->suiv;
            count++;
        }

        // Inserer apres le noeud trouvee (ou a la fin si la position n est pas donnee)
        if (cur != NULL) {
            nouv->pre = cur->pre;
            nouv->suiv = cur;
            if (cur->pre != NULL) {
                cur->pre->suiv = nouv;
            } else {
                // si la position est a la tete mise a jour tete
                *tete = nouv;
            }
            cur->pre= nouv;
        } else {
            ListP l = *tete;
            while (l->suiv != NULL) {
                l = l->suiv;
            }
            l->suiv = nouv;
            nouv->pre = l;
        }
    }
}
 
 int main(){

    return 0;
}
  
