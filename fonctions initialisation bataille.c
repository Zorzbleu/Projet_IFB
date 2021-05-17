//
// Created by Peterrr on 14/05/2021.
//

#include "fonctions initialisation bataille.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mtwister.h"
#define N 10

int verification_emplacement_bateau(bateau * boat, tableau * grid) {
    int X = boat->CooX, Y = boat->CooY;

    //printf("Coordonnees generees : %d,%d,%d,%d,%c,%c\n Grille avant implementation\n", boat->CooX,boat->CooY,boat->length,boat->orientation,boat->id,boat->id,boat->id_dead);
    //show_grid(grid);
    if(boat->orientation == 0) { //regarde pour orientation verticale
        //if(boat->CooX + boat->length > N) //Si la CooX de la dernière case occupée par le bateau dépasse la grille, il est out of bound
        //{
            //printf("Error : boat out of bound\n");
        //    return(0);
        //} else {
            for (; X - boat->CooX < boat->length; X++) { //la vérification doit être fait pour toutes les cases occupées par le bateau
                //printf("\n%c", grid[i][j]);
                if (grid->grid[X][Y] != '_') { //'_' représente une case vide : si elle n'est pas vide, un bateau est déjà à cette endroit là et on ne peut donc pas générer le nouveau bateau
                    //printf("Error : object in way of boat\n");
                    return(0);
                }
            } //printf("\nSuccess : no boat in the way\n");
            return(1);
       // }
    } else {if(boat->orientation == 1) {
       //     if(boat->CooY + boat->length > N) {
       //         //printf("\nError : boat out of bound\n");
       //         return(0);
       //     } else {
                for (; Y - boat->CooY < boat->length; Y++ ) {
                    //printf("\n%c", grid[i][j]);
                    if (grid->grid[X][Y] != '_') {
                        //printf("\nError : object in way of boat\n");
                        return(0);
                    }
                } //printf("\nSuccess : no boat in the way\n");
                return(1);
              }
        }
        //printf("\nError : boat orientation isn't 0 or 1\n");
        return(0);
    }
//}


void implentation_bateau(bateau  * boat, tableau * grid) {
    int i;
    if(boat->orientation == 0) { //implentation verticale (axe des x)
        for (i=0; i < boat->length ; i++) {
            grid->grid[boat->CooX+i][boat->CooY] = boat->id;
        }
    } else {
        for (i=0; i < boat->length; i++) { //implentation horizontale (axe des y)
            grid->grid[boat->CooX][boat->CooY+i] = boat->id;
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

void initialization_grille(tableau * grid) {
    int x, y;
    for (x = 0; x < grid->largeur; x++) {
        for (y = 0; y < grid->hauteur; y++) {
            grid->grid[x][y] = '_';
        }
    }
}



void generation_bateau(bateau * boat, tableau *grid) {
    int i=0;
    MTRand r = seedRand(time(NULL)-boat->id);

    do {
        boat->orientation = genRand( &r ) * 2;
        switch(boat->orientation) {
            case 1 :
                boat->CooX = genRand( &r ) * N ;
                boat->CooY = genRand( &r ) * (N-boat->length) ;
                break;
            case 0 :
                boat->CooX = genRand( &r ) * (N-boat->length) ;
                boat->CooY = genRand( &r ) * N ;
                break;
            default :
                printf("Erreur : orientation ni 0 ni 1");
                exit(0);
        }
    } while(verification_emplacement_bateau(boat, grid) != 1);

    do {
        i++;
        implentation_bateau(boat, grid);
    } while (grid->grid[boat->CooX][boat->CooY] == '_');
    if (i<1)
        printf("%d implementations !\n",i);
}


void debug_coo(bateau * boat){
    printf("%d,%d,%d,%d,%c,%*c\n", boat->CooX+1,boat->CooY+1,boat->length,boat->orientation,boat->id,boat->id,boat->id_dead);
}

int hitscan(int X, int Y, tableau *boat_grid, tableau *user_grid, bateau  liste[]) {
    int i;
    if(boat_grid->grid[X][Y] == '_'){
        user_grid->grid[X][Y] = 'X';
        return(-1);
    } else {
        for(i=0; i < 5; i++) { //use nb_bateaux
            if (boat_grid->grid[X][Y] == liste[i].id) {
                printf("Le bateau %c est touche!\n", i + 'A');
                liste[i].pv--;
                if (liste[i].pv == 0 )
                    printf("Le bateau coule !\n");
                user_grid->grid[X][Y] = 'O';
                boat_grid->grid[X][Y] = 'A' + i;
                return(i);
            }
            else {
                if(boat_grid->grid[X][Y] == liste[i].id_dead){
                    printf("Tu as deja touche le bateau %c a cet endroit!\n", i + 'A');
                    user_grid->grid[X][Y] = 'O';
                    return(-2);
                }
            }


        }
    } return(-1);
}
void fire_missile(int X, int Y, tableau  * boat_grid, tableau * user_grid, bateau liste[]){
    if(hitscan(X,Y,boat_grid,user_grid,liste)==-1)
        printf("Miss !\n");
}

int win(bateau liste[], int nb_bateaux) {
    int i, nb_bateau_vivant=0;

    for(i=0; i < nb_bateaux;i++){
        if(liste[i].pv > 0 ) {
            nb_bateau_vivant++;
        }
    } //while(liste[i] != NULL);

    return(nb_bateau_vivant);
}

void fire_artillery(int X, int Y, tableau  * boat_grid, tableau * user_grid, bateau liste[]){
    int i;
    for(i=0;i<10;i++)
    {
        hitscan(X,i,boat_grid,user_grid,liste);
        if(i!=X)
            hitscan(i,Y,boat_grid,user_grid,liste);
    }
}

void fire_tactical(int X, int Y, tableau  * boat_grid, tableau * user_grid, bateau liste[]){
    int numero_bateau=hitscan(X,Y,boat_grid,user_grid,liste), i;
    if(numero_bateau > -1)
    {
        for (i = 1; i < liste[numero_bateau].length; i++) {
            if(liste[numero_bateau].orientation == 0) { //implentation verticale (axe des x)
                if(user_grid->grid[liste[numero_bateau].CooX+i][liste[numero_bateau].CooY] != 'O'){
                    hitscan(X+i,Y,boat_grid,user_grid,liste);
             }
            } else {
                if (user_grid->grid[liste[numero_bateau].CooX][liste[numero_bateau].CooY + i] != 'O') {
                    hitscan(X, Y+i, boat_grid, user_grid, liste);
                }
            }
        }

    }
}