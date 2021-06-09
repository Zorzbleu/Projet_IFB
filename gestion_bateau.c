//
// Created by Admin on 27/05/2021.
//
#include "gestion_bateau.h"
#include "structure.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generation_bateau(boat * bateaux, Grid *boat_grid ) {
    int i=0;



    srand(time(NULL)*bateaux->id);

    do {
        bateaux->orientation = rand() % 2;
        switch(bateaux->orientation) {
            case 1 :
                bateaux->CooX = rand() % N ;
                bateaux->CooY = rand() % (N-bateaux->length) ;
                break;
            case 0 :
                bateaux->CooX = rand() % (N-bateaux->length) ;
                bateaux->CooY = rand() % N ;
                break;
            default :
                printf("Erreur : orientation ni 0 ni 1");
                exit(0);
        }
    } while(verification_emplacement_bateau(bateaux, boat_grid) != 1);

    do {
        i++;
        implentation_bateau(bateaux, boat_grid);
    } while (boat_grid->grid[bateaux->CooX][bateaux->CooY] == '_');
    if (i<1)
        printf("%d implementations !\n",i);
}


void implentation_bateau(boat  * boat, Grid * boat_grid) {
    int i;
    if(boat->orientation == 0) { //implentation verticale (axe des x)
        for (i=0; i < boat->length ; i++) {
            boat_grid->grid[boat->CooX+i][boat->CooY] = boat->id;
        }
    } else {
        for (i=0; i < boat->length; i++) { //implentation horizontale (axe des y)
            boat_grid->grid[boat->CooX][boat->CooY+i] = boat->id;
        }
    }

}



int verification_emplacement_bateau(boat * bateaux, Grid * boat_grid) {
    int X = bateaux->CooX, Y = bateaux->CooY;


    if(bateaux->orientation == 0) { //regarde pour orientation verticale
        for (; X - bateaux->CooX < bateaux->length; X++) { //la vérification doit être fait pour toutes les cases occupées par le bateau
            if (boat_grid->grid[X][Y] != '_') { //'_' représente une case vide : si elle n'est pas vide, un bateau est déjà à cette endroit là et on ne peut donc pas générer le nouveau bateau
                if ( boat_grid->grid[X][Y] != bateaux->id ||boat_grid->grid[X][Y] != bateaux->id_dead  ){
                    return(0);
                }
            }
        }
        return(1);

    } else {if(bateaux->orientation == 1) {

            for (; Y - bateaux->CooY < bateaux->length; Y++ ) {

                if (boat_grid->grid[X][Y] != '_') {
                    if ( boat_grid->grid[X][Y] != bateaux->id ||boat_grid->grid[X][Y] != bateaux->id_dead  ){
                        return(0);
                    }
                }
            }
            return(1);
        }
    }

    return(0);
}



void generer_caracteristique_bateaux (boat * l_bateaux,int i){
    if (l_bateaux == NULL){
        exit(1);
        }

        l_bateaux->length = i + 1;
        l_bateaux->id = 'a' + i;
        l_bateaux->id_dead = 'A' + i;
        l_bateaux->pv = l_bateaux->length;



}


