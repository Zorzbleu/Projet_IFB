//
// Created by Peterrr on 10/06/2021.
//
#include <stdio.h>
#include <ctype.h>
#include "string.h"
#include "structure.h"
#include "fonctions_tour_de_jeu.h"
#include "type_missile.h"
#include "arbitre_de_la_partie.h"
#include "gestion_bateau.h"
#include <stdlib.h>
#include <time.h>

void coordonnees_tir(Missile_Coordinates* Coordonnees_missile){

    do {
        printf("Ou voulez-vous tirer ? Exemple : C7\n");
        do{
            fgets(Coordonnees_missile->Given_Coordinates, 4, stdin);
            Coordonnees_missile->Given_Coordinates[strcspn(Coordonnees_missile->Given_Coordinates, "\n")] = '\0';
        }while((getchar()) != '\n');

        Coordonnees_missile->Y_Coordinates = (toupper(Coordonnees_missile->Given_Coordinates[0]) - 'A');

        if (Coordonnees_missile->Given_Coordinates[1] == '1' && Coordonnees_missile->Given_Coordinates[2] == '0') {
            Coordonnees_missile->X_Coordinates = 9;
        }else{
            Coordonnees_missile->X_Coordinates = Coordonnees_missile->Given_Coordinates[1]-48 -1 ;
        }

    } while (Coordonnees_missile->X_Coordinates > 10 || Coordonnees_missile->X_Coordinates <= -1 || Coordonnees_missile->Y_Coordinates > 10 || Coordonnees_missile->Y_Coordinates <= -1);
}

void lancement_tir(Missile_Coordinates Coordonnees_missile, int missile_choisie, Grid boat_grid, Grid user_grid, boat liste_bateaux[], Inventory liste_missile){

    switch (missile_choisie) {
        case 1 :
            fire_missile(Coordonnees_missile.X_Coordinates, Coordonnees_missile.Y_Coordinates, &boat_grid, &user_grid, liste_bateaux, &liste_missile);
            break;
        case 2 :
            fire_tactical(Coordonnees_missile.X_Coordinates, Coordonnees_missile.Y_Coordinates, &boat_grid, &user_grid, liste_bateaux, &liste_missile);
            break;
        case 3 :
            fire_bomb(Coordonnees_missile.X_Coordinates, Coordonnees_missile.Y_Coordinates, &boat_grid, &user_grid, liste_bateaux, &liste_missile);
            break;
        case 4 :
            fire_artillery(Coordonnees_missile.X_Coordinates, Coordonnees_missile.Y_Coordinates, &boat_grid, &user_grid, liste_bateaux, &liste_missile);
            break;
        default :
            printf("Erreur : valeur 'type_missile' invalide");
    }
}

void active_mode(int choix_difficulte, boat *liste_bateaux, Grid* boat_grid, Grid* user_grid){
    int i;
    int deplacer_ou_pas; //gère la probabilité de déplacement d'un bateau en mode active
    deplacer_ou_pas  = aleatoir_deplacer_ou_pas(choix_difficulte);
    if( deplacer_ou_pas == 1 ){
        int axe_XY,nb_bateau,nb_deplacement,sens_deplacement;

        srand(time(0));
        do{
            axe_XY = rand () % 2; //alea1 axe x ou y exemple : si axe_XY = 0 alors ons ce deplace dans le sens des X
            nb_bateau = rand () % 6 ; //numero du bateau
            nb_deplacement = rand () % 2 + 1  ; //nombre de deplacement
            sens_deplacement = rand () % 2+1; // + ou - Exemple si sens_deplacement = 1 alors le bateau avance si non il recule

            ajouter_coordonne(&liste_bateaux, axe_XY,nb_bateau,nb_deplacement,sens_deplacement);


            if (verification_emplacement_bateau(&liste_bateaux[nb_bateau], boat_grid) != 1){/// si le ne pouvais pas ce deplacer , il faut le redonner ses coordoné d'origine

                retirer_coordonner(&liste_bateaux, axe_XY,nb_bateau,nb_deplacement,sens_deplacement);
            }

        }while(verification_emplacement_bateau(&liste_bateaux[nb_bateau], boat_grid) != 1);


        char tampon [5]= {0};
        for ( i = 0 ; i < liste_bateaux[nb_bateau].length; i++){
            sauvegarde_caracter_bateau(&liste_bateaux,boat_grid,nb_bateau,nb_deplacement,axe_XY,sens_deplacement,&tampon[i]);
        }



        for ( i=0 ; i< liste_bateaux[nb_bateau].length ; i++){
            placer_carater_sauvegarder_bateau(&liste_bateaux,user_grid,&tampon[i],nb_bateau);
        }


        effacer_encien_bateau(&liste_bateaux,boat_grid,nb_bateau,nb_deplacement,axe_XY,sens_deplacement);

    }
    printf (" Un bateau a ete deplace !!!!\n");
}