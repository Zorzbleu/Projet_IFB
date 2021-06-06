

#include "fonctions initialisation bataille.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tire.h"




void debug_coo(boat * boat){
    printf("%d,%d,%d,%d,%c,%*c\n", boat->CooX+1,boat->CooY+1,boat->length,boat->orientation,boat->id,boat->id,boat->id_dead);
}


void fire_missile(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile){
    if(liste_missile->nb_missile_default == 0) {
        printf("Vous n'avez plus de ce missile !!!!\n");
    } else {
        if (hitscan(X, Y, boat_grid, user_grid, liste) == -1)
            printf("Miss !\n");
        liste_missile->nb_missile_default--;
    }
}




void clear_text(int lines) {
    if (lines == 0) {
        for (int i = 0; i < 50 ; ++i) {
            printf("\n");
        }
    } else {
        for (int i = 0; i < lines; ++i) {
            printf("\n");
        }
    }
}

void error_message(char variable) {
    printf("Erreur : variable '%c' non valable", variable);
}

/////////////








