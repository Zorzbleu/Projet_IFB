//
// Created by Peterrr on 10/06/2021.
//
#include <stdio.h>
#include <ctype.h>
#include "structure.h"
#include "fonctions_tour_de_jeu.h"
#include "type_missile.h"
#define u_accent 151
#define e_circonflexe 136

void coordonnees_tir(Missile_Coordinates* Coordonnees_missile){

    do {
        printf("O%c voulez-vous tirer ? Exemple : C7\n",u_accent );


        fflush(stdin);
        fgets(Coordonnees_missile->Given_Coordinates, 4, stdin);


        Coordonnees_missile->Y_Coordinates = (toupper(Coordonnees_missile->Given_Coordinates[0]) - 'A');

        if (Coordonnees_missile->Given_Coordinates[1] == '1' && Coordonnees_missile->Given_Coordinates[2] == '0') {
            Coordonnees_missile->X_Coordinates = 9;
        }else{
            Coordonnees_missile->X_Coordinates = Coordonnees_missile->Given_Coordinates[1]-48 -1 ;
        }

    } while (Coordonnees_missile->X_Coordinates > 10 || Coordonnees_missile->X_Coordinates <= -1 || Coordonnees_missile->Y_Coordinates > 10 || Coordonnees_missile->Y_Coordinates <= -1);
}

void lancement_tir(Missile_Coordinates Coordonnees_missile, int missile_choisie, Grid* boat_grid, Grid* user_grid, boat* liste_bateaux[], Inventory* liste_missile){

    switch (missile_choisie) {
        case 1 :
            fire_missile(Coordonnees_missile.X_Coordinates, Coordonnees_missile.Y_Coordinates, boat_grid, user_grid, *liste_bateaux, liste_missile);
            break;
        case 2 :
            fire_tactical(Coordonnees_missile.X_Coordinates, Coordonnees_missile.Y_Coordinates, boat_grid, user_grid, *liste_bateaux, liste_missile);
            break;
        case 3 :
            fire_bomb(Coordonnees_missile.X_Coordinates, Coordonnees_missile.Y_Coordinates, boat_grid, user_grid, *liste_bateaux, liste_missile);
            break;
        case 4 :
            fire_artillery(Coordonnees_missile.X_Coordinates, Coordonnees_missile.Y_Coordinates, boat_grid, user_grid, *liste_bateaux, liste_missile);
            break;
        default :
            printf("Erreur : valeur 'type_missile' invalide\n");
    }
}


int continuer_partie(){
    int J_Q; // jouer ou quitter(et sauvegarde)
    printf( "\n"
            "                                         Voulez-vous continuer de jouer ?                                              \n"
            "                    Continuer : O                                                     Arr%cter : N                      \n\n", e_circonflexe);
    fflush(stdin);
    J_Q = fgetc(stdin);

    while (J_Q != 'O' && J_Q != 'N'){
        printf("Erreur  : saisie  incorrecte \n");
        fflush(stdin);
        J_Q = fgetc(stdin);
    }
    return(J_Q);
}