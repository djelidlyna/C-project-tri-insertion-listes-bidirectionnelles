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
//FONCTION pour insérer un élément dans la liste avec une position donnée
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

 // Fonction  tri par insertion 
void insertionSort(ListP* tete) {
    ListP cur;
    ListP sort = NULL;
    cur = *tete;
    clock_t start_time;

    while (cur != NULL) {
        ListP n = cur->suiv;

        if (sort == NULL || sort->info >= cur->info) {
            cur->suiv = sort;
            cur->pre = NULL;
            if (sort != NULL) {
                sort->pre = cur;
            }
            sort = cur;
        } else {
            ListP t = sort;
            while (t->suiv != NULL && t->suiv->info < cur->info) {
                t = t->suiv;
            }

            cur->suiv = t->suiv;
            if (t->suiv != NULL) {
                t->suiv->pre = cur;
            }

            t->suiv = cur;
            cur->pre = t;
        }
        start_time = clock();

        while ((clock() - start_time) < 1 * CLOCKS_PER_SEC) {
            // Effacer l'écran et dessiner les éléments avec le nouveau chaînage
            BeginDrawing();
            ClearBackground(BLACK);

            // Dessiner les éléments de la liste avec le chaînage mis à jour
            ListP drawCurrent = sort;
            int xPos = 200;
            int yPos = GetScreenHeight() / 2;

            while (drawCurrent != NULL) {
                // Dessiner le cercle avec la position ajustée
                DrawCircle(xPos, yPos, 30, WHITE);
                DrawCircleLines(xPos, yPos, 30, WHITE);

                // Dessiner la connexion avec le précédent (si existant) avec la position ajustée
                if (drawCurrent->pre != NULL) {
                    // Ajuster la position des lignes en fonction de l'itération
                    float progress = (float)(clock() - start_time) / (8 * CLOCKS_PER_SEC);
                    int offset = (int)(progress * 120); // Ajuster cet offset pour changer la distance parcourue par les lignes

                    DrawLineEx((Vector2){xPos - 90 + offset, yPos - 10}, (Vector2){xPos - 30 + offset, yPos - 10}, 4, PURPLE);
                    DrawLineEx((Vector2){xPos - 90 + offset, yPos + 10}, (Vector2){xPos - 30 + offset, yPos + 10}, 4, PURPLE);

                    DrawLineEx((Vector2){xPos - 40 + offset, yPos + 20}, (Vector2){xPos - 30 + offset, yPos + 10}, 2, PURPLE);
                    DrawLineEx((Vector2){xPos - 40 + offset, yPos}, (Vector2){xPos - 30 + offset, yPos + 10}, 2, PURPLE);

                    DrawLineEx((Vector2){xPos - 90 + offset, yPos - 10}, (Vector2){xPos - 80 + offset, yPos - 20}, 2, PURPLE);
                    DrawLineEx((Vector2){xPos - 90 + offset, yPos - 10}, (Vector2){xPos - 80 + offset, yPos}, 2, PURPLE);
                }

                // Dessiner la valeur à l'intérieur du cercle
                DrawTextEx(GetFontDefault(), TextFormat("%d", drawCurrent->info), (Vector2){xPos - MeasureText(TextFormat("%d", drawCurrent->info), 20) / 2, yPos - 20}, 20, 2, BLACK);

                // Mettre à jour les positions pour le prochain élément
                xPos += 120;

                drawCurrent = drawCurrent->suiv;
            }

            EndDrawing();
        }

        cur = n;
    }

    *tete = sort;


}

// Fonction  suppression un element a une position donnee
void deleteElementAtPosition(ListP* tete, int position) {
    if (*tete == NULL) {
        return; // la liste est vide
    }

    ListP cur = *tete;

    // trouver le noeud a supprimee
    for (int i = 1; i < position && cur != NULL; i++) {
        cur = cur->suiv;
    }

    if (cur == NULL) {
        return; // la position est grande que la taille 
    }

    if (cur->pre != NULL) {
        cur->pre->suiv = cur->suiv;
    } else {
        // si la position est a la tete de la liste 
        *tete= cur->suiv;
    }

    if (cur->suiv != NULL) {
        cur->suiv->pre= cur->pre;
    }

    free(cur); 
}

// Fonction recherche element 
ListP searchElement(ListP tete, int v) {
    ListP cur = tete;

    while (cur != NULL) {
        if (cur->info == v) {
            return cur; // retourner noeud si la valeur existe 
        }
        cur = cur->suiv;
    }

    return NULL; // si ce n est pas trouvee 
}



// Fonction pour avoir le saisie du clavier 
int getValueInput() {
    char input[16] = {0};
    Rectangle inputBox = { 10, GetScreenHeight() - 40, 200, 30 };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Enter  la valeur pour la chercher dans la liste :", 10, inputBox.y - 30, 20, BLACK);
        DrawRectangleRec(inputBox, RAYWHITE);
        DrawText(input, inputBox.x + 10, inputBox.y + 10, 20, BLACK);

        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(GetMousePosition(), inputBox)) {
                int key = GetKeyPressed();
                if ((key >= KEY_ZERO && key <= KEY_NINE) || (key == KEY_BACKSPACE)) {
                    int length = (int)strlen(input);
                    if (key == KEY_BACKSPACE && length > 0) {
                        input[length - 1] = '\0';
                    } else if (length < sizeof(input) - 1) {
                        input[length] = (char)key;
                        input[length + 1] = '\0';
                    }
                } else if (key == KEY_ENTER) {
                    break;
                }
            }
        }
    }

    return atoi(input);
}

 int main(){

    return 0;
}
  
