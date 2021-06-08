//
// Created by Admin on 27/05/2021.
//

#include "initialisation_interface.h"
#include <stdio.h>


void initialization_grille(Grid * grid) {
    int x, y;
    for (x = 0; x < grid->largeur; x++) {
        for (y = 0; y < grid->hauteur; y++) {
            grid->grid[x][y] = '_';
        }
    }
}

void show_grid(Grid * grid) {
    int x, y;
    for(x=0 ; x < grid->largeur; x++) {
        printf("  %d", x+1);
    }
    printf("\n");
    for (y = 0; y < grid->hauteur; y++) {
        printf("%c ", 'A'+ y);
        for (x = 0; x < grid->largeur; x++) {
            printf("%c  ", grid->grid[x][y]);
        }
        printf("\n");
    }

}

void regler_dimention (Grid * boat, Grid * grid){
    boat->hauteur = 10;
    boat->largeur = 10;
    grid->hauteur = 10;
    grid->largeur = 10;
}

void initialization_caracteristiques_bateaux(boat liste_bateaux[5]) {
    liste_bateaux[0].length = 2;
    liste_bateaux[1].length = 3;

    for (int i = 2; i < 5; ++i) {
        liste_bateaux[i].length = i+1;
    }

    for (int i = 0; i < 5; ++i) {

        liste_bateaux[i].id = 'a' +i;
        liste_bateaux[i].id_dead = 'A' +i;
        liste_bateaux[i].pv = liste_bateaux[i].pv;
    }
}