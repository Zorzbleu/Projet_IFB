//
// Created by Peterrr on 14/05/2021.
//

#include "fonctions initialisation bataille.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int verification_emplacement_bateau(bateau * boat, tableau * grid) {
    int X = boat->CooX, Y = boat->CooY;


    if(boat->orientation == 0) { //regarde pour orientation verticale
        for (; X - boat->CooX < boat->length; X++) { //la vérification doit être fait pour toutes les cases occupées par le bateau

            if (grid->grid[X][Y] != '_') { //'_' représente une case vide : si elle n'est pas vide, un bateau est déjà à cette endroit là et on ne peut donc pas générer le nouveau bateau

                return(0);
            }
        }
        return(1);

    } else {if(boat->orientation == 1) {

            for (; Y - boat->CooY < boat->length; Y++ ) {

                if (grid->grid[X][Y] != '_') {
                    return(0);
                }
            }
            return(1);
        }
    }

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
    srand(time(NULL)*boat->id);

    do {
        boat->orientation = rand() % 2;
        switch(boat->orientation) {
            case 1 :
                boat->CooX = rand() % N ;
                boat->CooY = rand() % (N-boat->length) ;
                break;
            case 0 :
                boat->CooX = rand() % (N-boat->length) ;
                boat->CooY = rand() % N ;
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
    if (boat_grid->grid[X][Y] == '_') {
        user_grid->grid[X][Y] = 'X';
        boat_grid->grid[X][Y] = 'X';
        return (-1);
    } else {
        if (boat_grid->grid[X][Y] == 'X') { printf("Tu as déjà tiré à cet endroit !"); }
        else {

            for (i = 0; i < 5; i++) { //use nb_bateaux
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

void fire_missile(int X, int Y, tableau  * boat_grid, tableau * user_grid, bateau liste[],  missile *liste_missile){
    if(liste_missile->nb_missile_default == 0) {
        printf("Vous n'avez plus de ce missile !!!!\n");
    } else {
        if (hitscan(X, Y, boat_grid, user_grid, liste) == -1)
            printf("Miss !\n");
        liste_missile->nb_missile_default--;
    }
}

int win(bateau liste[], int nb_bateaux) {
    int i, nb_bateau_vivant=0;

    for(i=0; i < nb_bateaux;i++){
        if(liste[i].pv > 0 ) {
            nb_bateau_vivant++;
        }
    }

    return(nb_bateau_vivant);
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

void clear_text(int lines) {
    if (lines == 0) {
        for (int i = 0; i < 50 ; ++i) {
            printf("\n");
        }
    } else {
        for (int i = 0; i < lines; ++i) {
            printf("\n");
        }
    }
}

void error_message(char variable) {
    printf("Erreur : variable '%c' non valable", variable);
}