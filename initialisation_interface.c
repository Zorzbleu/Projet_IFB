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

void dimension_tableau(Grid *grid, int hauteur, int largeur){
    grid->hauteur = hauteur;
    grid->largeur = largeur;
}


void initialization_boats_characteristics(boat *liste_bateaux, int nb_bateaux){
    liste_bateaux[0].length = 2;
    liste_bateaux[1].length = 3;
    for (int i = 2; i < nb_bateaux; ++i) {
        liste_bateaux[i].length = i + 1;
    }

    for (int i = 0; i < nb_bateaux ;++i) {
        liste_bateaux[i].id = 'a' + i;
        liste_bateaux[i].id_dead = 'A' + i;
        liste_bateaux[i].pv = liste_bateaux[i].length;
    }


}

void initialization_default(Grid *boat_grid, Grid *user_grid, boat *liste_bateaux, int nb_bateaux){
    dimension_tableau(boat_grid, 10, 10);
    dimension_tableau(user_grid, 10, 10);
    initialization_grille(user_grid);
    initialization_grille(boat_grid);
    initialization_boats_characteristics(liste_bateaux, nb_bateaux);
}