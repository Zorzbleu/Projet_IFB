//
// Created by Peterrr on 14/05/2021.
//

#include "fonctions initialisation bataille.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mtwister.h"
#define N 10

int verification_emplacement_bateau(bateau boat, char grid[N][N]) {

    if(boat.orientation == 0) { //regarde pour orientation verticale
        //if(boat.CooX + boat.length > N) //Si la CooX de la dernière case occupée par le bateau dépasse la grille, il est out of bound
        //{
        //    printf("Error : boat out of bound\n");
        //    return(0);
        //} else {
            for (; boat.CooX < boat.length; boat.CooX++) { //la vérification doit être fait pour toutes les cases occupées par le bateau
                if (grid[boat.CooX][boat.CooY] != '_') { //'_' représente une case vide : si elle n'est pas vide, un bateau est déjà à cette endroit là et on ne peut donc pas générer le nouveau bateau
                    printf("Error : object in way of boat\n");
                    return(0);
                }
            } printf("Success : no boat in the way");
            return(1);
       // }
    } else {if(boat.orientation == 1) {
            //if(boat.CooY + boat.length > N) {
            //    printf("Error : boat out of bound\n");
            //    return(0);
            //} else {
                for (; boat.CooY < boat.length; boat.CooY++ ) {
                    if (grid[boat.CooX][boat.CooY] != '_') {
                        printf("Error : object in way of boat\n");
                        return(0);
                    }
                } printf("Error : boat out of bound\n");
                return(1);
        //    }
        }
        printf("Error : boat orientation isn't 0 or 1");
        return(0);
    }
}


void implentation_bateau(bateau boat, char grid[N][N]) {
    int i;
    if(boat.orientation == 0) { //implentation verticale (axe des x)
        for (i=0; i < boat.length ; i++) {
            grid[boat.CooX+i][boat.CooY] = boat.length;
        }
    } else {
        for (i=0; i < boat.length; i++) { //implentation horizontale (axe des y)
            grid[boat.CooX][boat.CooY+i] = boat.length;
        }
    }
}

void show_grid(char grid[N][N]) {
    int x, y;

    for (x = 0; x < N; x++) {
        for (y = 0; y < N; y++) {
            printf("%c  ", grid[x][y]);
        }
        printf("\n");
    }

}

void initialization_grille(char grid[N][N]) {
    int x, y;
    for (x = 0; x < N; x++) {
        for (y = 0; y < N; y++) {
            grid[x][y] = '_';

        }
    }
}



void generation_bateau(bateau boat, char grid[N][N]) {

    MTRand r = seedRand(time(NULL));

    do {
        boat.orientation = genRand( &r ) * 2;
        if(boat.orientation ==0) {
            boat.CooX = genRand( &r ) * N - boat.length;
            boat.CooY = genRand( &r ) * N ;
        } else {
            boat.CooX = genRand( &r ) * N ;
            boat.CooY = genRand( &r ) * N - boat.length ;
        }

    } while(verification_emplacement_bateau(boat, grid) != 1);
    printf("Orientation : %d\nCooX :%d\n CooY:%d\n Longueur :%d\n", boat.orientation, boat.CooX, boat.CooY, boat.length);
    implentation_bateau(boat, grid);
}



