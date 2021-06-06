//
// Created by Admin on 27/05/2021.
//

#include "tire.h"
#include <stdio.h>


int hitscan(int X, int Y, Grid *boat_grid, Grid *user_grid, boat  liste[]) {
    int i;
    if (boat_grid->grid[X][Y] == '_') {
        user_grid->grid[X][Y] = 'X';
        boat_grid->grid[X][Y] = 'X';
        return (-1);
    } else {
        if (boat_grid->grid[X][Y] == 'X') { printf("Tu as déjà tiré à cet endroit !"); }
        else {

            for (i = 0; i < 5; i++) {
                if (boat_grid->grid[X][Y] == liste[i].id) {
                    printf("Le bateau %c est touche en %c%d!\n", i + 'A', Y + 'A', X + 1);
                    liste[i].pv--;
                    if (liste[i].pv == 0)
                        printf("Le bateau coule !\n");
                    user_grid->grid[X][Y] = 'O';
                    boat_grid->grid[X][Y] = 'A' + i;
                    return (i);
                } else {
                    if (boat_grid->grid[X][Y] == liste[i].id_dead) {
                        printf("Tu as deja touche le bateau %c en %c%d!\n", i + 'A', Y + 'A', X + 1);
                        user_grid->grid[X][Y] = 'O';
                        return (-2);
                    }
                }


            }
        }
        return (-1);
    }
}
