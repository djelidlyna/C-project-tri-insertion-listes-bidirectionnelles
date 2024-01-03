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
// fonction pour creer un element 
ListP creerElement(int valeur) { 
    ListP nouvelElement = (ListP) malloc(sizeof(Liste));
    nouvelElement->info = valeur;
    nouvelElement->suiv = NULL;
    nouvelElement->pre = NULL;
    return nouvelElement;
}
 //fonction qui affiche la liste 
void afficherliste(ListP* L){ //du premier vers le dernier
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
// Function pour ajouter un element a la fin de la liste 
void insererfin(ListP* tete, int valeur) {
    ListP nouv = creerElement(valeur);

    if (*tete == NULL) {
        *tete= nouv;
        return;
    }

    ListP p = *tete;
    while (p->suiv != NULL) {
        p = p->suiv;
    }

    p->suiv= nouv;
    nouv->pre = p;
}


//fonction Tri qui trie la liste par ordre croissant 
void Tri(ListP* L) {
    ListP P = *L;
    ListP Q = NULL;

    if (P== NULL) {
        return;
    }

    int X;

    while (P != NULL) {
        Q= P->suiv;

        while (Q != NULL) {
            if (P->info > Q->info) {
                X = P->info;
                P->info = Q->info;
                Q->info = X;
            }
            Q= Q->suiv;
        }
        P = P->suiv;
    }
}
 //une fonction supElem qui supprime un élément de la liste
 void supElem(ListP *L, int position) {
    ListP P = *L;
    for (int i = 0; i < position - 1; i++) {
        P = P->suiv;
    }

    ListP Q = P->suiv;
    P->suiv = Q->suiv;
    Q->suiv->pre = P;

    free(Q);
}
 int main(){
ListP tete= NULL;

    int choix, v,pos;
    do {
        printf("\n*********Menu:********");
        printf("\n1. ajouter un element  ");
        printf("\n2. supprimer  la liste");
        printf("\n3. trier la liste");
        printf("\n4. sortir");
        printf("\n\nEntrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("\nEntrer la valeur de l 'element á ajouter: ");
                scanf("%d", &v);
                insererfin(&tete, v);
                printf("\n element ajouté avec succes . la liste actuelle est: ");
                afficherliste(tete);
                break;
             case 2:
              printf("donner la position de l element a supprimer");
              scanf("%d",&pos);
         supElem(&tete,pos);
         printf("\n element supprimer avec succes . la liste actuelle est: ");
                afficherliste(tete);
         break;
             case 3:
                Tri(&tete);
                printf("\n liste triée avec sucees. la liste actuelle est: ");
                afficherliste(tete);
                break;
            case 4:
                break;
            default:
                printf("\nchoix invalide.");
        }
    } while (choix != 4);

    return 0;
}
  
