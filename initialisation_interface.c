//
// Created by Admin on 27/05/2021.
//

#include "initialisation_interface.h"
#include <stdio.h>


void initialization_grille(tableau * grid) {
    int x, y;
    for (x = 0; x < grid->largeur; x++) {
        for (y = 0; y < grid->hauteur; y++) {
            grid->grid[x][y] = '_';
        }
    }
}

void show_grid(tableau * grid) {
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

void regler_dimention (tableau * boat, tableau * grid){

    boat->hauteur = 10;
    boat->largeur = 10;
    grid->hauteur = 10;
    grid->largeur = 10;
}