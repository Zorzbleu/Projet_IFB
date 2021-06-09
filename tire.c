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
        if (boat_grid->grid[X][Y] == 'X') { printf("Tu as deja tire a cet endroit !"); }
        else {
            for (i = 0; i < 5; i++) {
                if (boat_grid->grid[X][Y] == liste[i].id) {
                   // printf("Le bateau %c est touche en %c%d!\n", i + 'A', Y + 'A', X + 1);
                    liste[i].pv--;
                    /**
                    if(liste[i].orientation == 0){
                        printf("\n%d,%d\n",X,liste[i].CooX);
                        liste[i].pv_detaille[X - liste[i].CooX] = 1;
                    } else {
                        printf("\n%d,%d\n",Y,liste[i].CooY);
                        liste[i].pv_detaille[Y - liste[i].CooY] = 1;
                    }

                    printf("\nBateau %c a pour pv : ", liste[i].id_dead);
                    for (int j = 0; j < 5; ++j) {
                        printf("%d",liste[i].pv_detaille[j]);
                    }*/
                    printf("\nBateau %c a pour pv : %d %c\n ", liste[i].id_dead,liste[i].pv,3);



                   // printf("\n");
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
