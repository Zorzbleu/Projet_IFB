//
// Created by Admin on 27/05/2021.
//
#include "type_missile.h"
#include <stdio.h>
#include "tire.h"


void fire_tactical(int X, int Y, tableau  * boat_grid, tableau * user_grid, bateau liste[],  missile *liste_missile){
    int numero_bateau=hitscan(X,Y,boat_grid,user_grid,liste), i;
    if(liste_missile->nb_missile_tactique == 0) {
        printf("Vous n'avez plus de ce missile !!!!\n");
    } else {
        if (numero_bateau > -1) {
            for (i = 0; i < liste[numero_bateau].length; i++) {
                if (liste[numero_bateau].orientation == 0) { //implentation verticale (axe des x)
                    if (user_grid->grid[liste[numero_bateau].CooX + i][liste[numero_bateau].CooY] != 'O') {
                        hitscan(liste[numero_bateau].CooX + i, liste[numero_bateau].CooY, boat_grid, user_grid, liste);
                    }
                } else {
                    if (user_grid->grid[liste[numero_bateau].CooX][liste[numero_bateau].CooY + i] != 'O') {
                        hitscan(liste[numero_bateau].CooX, liste[numero_bateau].CooY + i, boat_grid, user_grid, liste);
                    }
                }
            }

        }
        liste_missile->nb_missile_tactique--;
    }
}


void fire_artillery(int X, int Y, tableau  * boat_grid, tableau * user_grid, bateau liste[], missile *liste_missile ){
    int i;
    if(liste_missile->nb_missile_artillerie == 0) {
        printf("Vous n'avez plus de ce missile !!!!\n");
    } else {
        for (i = 0; i < N; i++) {
            hitscan(X, i, boat_grid, user_grid, liste);
            if (i != X)
                hitscan(i, Y, boat_grid, user_grid, liste);
        }
        liste_missile->nb_missile_artillerie--;
    }
}

void fire_bomb(int X, int Y, tableau * boat, tableau * user_grid, bateau liste[],  missile *liste_missile){
    int i,j;
    if(liste_missile->nb_missile_bombe == 0) {
        printf("Vous n'avez plus de ce missile !!!!\n");
    } else {
        if (X >= 0 && Y - 2 >= 0 && X < 10 && Y - 2 < 10) {
            hitscan(X, Y - 2, boat, user_grid, liste);
        }
        if (X - 2 >= 0 && Y >= 0 && X - 2 < 10 && Y < 10) {
            hitscan(X - 2, Y, boat, user_grid, liste);
        }
        if (X + 2 >= 0 && Y >= 0 && X + 2 < 10 && Y < 10) {
            hitscan(X + 2, Y, boat, user_grid, liste);
        }
        if (X >= 0 && Y + 2 >= 0 && X < 10 && Y + 2 < 10) {
            hitscan(X, Y + 2, boat, user_grid, liste);
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (X - 1 + i >= 0 && Y - 1 + j >= 0 && X - 1 + i < 10 && Y - 1 + j < 10)
                    hitscan(X - 1 + i, Y - 1 + j, boat, user_grid, liste);
            }
        }
        liste_missile->nb_missile_bombe--;
    }
}
