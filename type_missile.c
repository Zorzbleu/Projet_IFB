//
// Created by Admin on 27/05/2021.
//
#include "type_missile.h"
#include <stdio.h>
#define e_accent_aigu 130
#define a_accent 133


void fire_missile(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile){
    int memoire;
    if(liste_missile->nb_missile_default == 0) {
        printf("Vous n'avez plus de ce missile !\n");
    } else {
        memoire = hitscan(X, Y, boat_grid, user_grid, liste);
        if (memoire == -1)
            printf("Il n'y a pas de bateau %c cet endroit !\n", a_accent);
        else
            if (memoire == -2)
                printf("Tu as d%cj%c tir%c %c cet endroit !\n",e_accent_aigu,a_accent,e_accent_aigu,a_accent);
        liste_missile->nb_missile_default--;
    }
}

void fire_tactical(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile){
    int numero_bateau=hitscan(X,Y,boat_grid,user_grid,liste), i;
    if(liste_missile->nb_missile_tactique == 0) {
        printf("Vous n'avez plus de ce missile !\n");
    } else {
        if (numero_bateau > -1) {
            for (i = 0; i < liste[numero_bateau].length; i++) {
                if (liste[numero_bateau].orientation == 0) { //on fait des hitscan sur l'axe des X sur toute la longueur du bateau sauf si le bateau à déjà été touché à cet endroit là
                    if (user_grid->grid[liste[numero_bateau].CooX + i][liste[numero_bateau].CooY] != 'O') {
                        hitscan(liste[numero_bateau].CooX + i, liste[numero_bateau].CooY, boat_grid, user_grid, liste);
                    }
                } else {
                    if (user_grid->grid[liste[numero_bateau].CooX][liste[numero_bateau].CooY + i] != 'O') { //Même chose mais sur l'axe des Y
                        hitscan(liste[numero_bateau].CooX, liste[numero_bateau].CooY + i, boat_grid, user_grid, liste);
                    }
                }
            }

        }
        liste_missile->nb_missile_tactique--;
    }
}


void fire_artillery(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[], Inventory *liste_missile){
    int i;
    if(liste_missile->nb_missile_artillerie == 0) {
        printf("Vous n'avez plus de ce missile !\n");
    } else {
        for (i = 0; i < N; i++) {
            hitscan(X, i, boat_grid, user_grid, liste);
            if (i != X)
                hitscan(i, Y, boat_grid, user_grid, liste);        //évite de toucher deux fois l'endroit où le missile a été lancé
        }
        liste_missile->nb_missile_artillerie--;
    }
}

void fire_bomb(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile){
    int i,j;
    if(liste_missile->nb_missile_bombe == 0) {
        printf("Vous n'avez plus de ce missile !\n");
    } else {
        if (X >= 0 && Y - 2 >= 0 && X < 10 && Y - 2 < 10) {                     //vérifie si la bombe ne dépasse pas de la grille sur chaque axe
            hitscan(X, Y - 2, boat_grid, user_grid, liste);     //On effectue d'abord les hitscan les plus en périphérie
        }
        if (X - 2 >= 0 && Y >= 0 && X - 2 < 10 && Y < 10) {
            hitscan(X - 2, Y, boat_grid, user_grid, liste);
        }
        if (X + 2 >= 0 && Y >= 0 && X + 2 < 10 && Y < 10) {
            hitscan(X + 2, Y, boat_grid, user_grid, liste);
        }
        if (X >= 0 && Y + 2 >= 0 && X < 10 && Y + 2 < 10) {
            hitscan(X, Y + 2, boat_grid, user_grid, liste);
        }
        for (i = 0; i < 3; i++) {                   //Boucle pour le carré de 3 par 3 touché au centre de la bombe
            for (j = 0; j < 3; j++) {
                if (X - 1 + i >= 0 && Y - 1 + j >= 0 && X - 1 + i < 10 && Y - 1 + j < 10)
                    hitscan(X - 1 + i, Y - 1 + j, boat_grid, user_grid, liste);
            }
        }
        liste_missile->nb_missile_bombe--;
    }
}


int hitscan(int X, int Y, Grid *boat_grid, Grid *user_grid, boat  liste[]) {
    int i;
    if (boat_grid->grid[X][Y] == '_') {
        user_grid->grid[X][Y] = 'X';
        boat_grid->grid[X][Y] = 'X';
        return (-1);
    } else {
        if (boat_grid->grid[X][Y] == 'X') { return (-2);}
        else {
            for (i = 0; i < 5; i++) {
                if (boat_grid->grid[X][Y] == liste[i].id) {
                    liste[i].pv--;
                    if (liste[i].pv <= 0)
                        printf("Le bateau coule !\n");
                    user_grid->grid[X][Y] = 'O';
                    boat_grid->grid[X][Y] = 'A' + i;
                    printf("Tu as touch%c le bateau %c en %c%d!\n", e_accent_aigu,i + 'A', Y + 'A', X + 1);
                    return (i);
                    }
                }
            }
        }
        return (-3);
    }
