//
// Created by Admin on 27/05/2021.
//
#include <stdio.h>
#include "donnees_du_jeux.h"

int affichage_menu_difficulte(){
    printf("Quelle difficulte voulez-vous ?\n"
           "1-Facile\n"
           "2-Moyen\n"
           "3-Difficile\n"
           "4- Rappel des difference entre les modes\n");
    return(choix_menu_multiple(4));
}


int  affichage_menu_mode_de_jeux(){
    printf("Bienvenue ! \n Pret a jouer a la bataille navale ?\n"
           "Dans quel mode de jeu voulez-vous jouer ?\n"
           "Choisissez le mode de jeu :\n1. Normal\n2. Blind\n3. Active\n");
    return(choix_menu_multiple(3));
}

int affichage_menu_demarrage(){
    printf ("1- Demarrer une nouvelle partie\n2- Charger une partie existante\n3- Quitter\n");
    return(choix_menu_multiple(3));
}


int choix_menu_multiple(int nombre_de_choix){
    int choix;

    do{
        choix = getchar() - 48; //en code ASCII, '0' a le numéro 48. On "transforme" ici un 0 "char" en 0 "int"
    }while( getchar() != '\n');

    while(choix < 1 || choix > nombre_de_choix){ // contrôle du mode de jeu
        printf ( "Erreur : veuillez entrer un chiffre entre 1 et 3.\n");
        printf("char choix : %c, int choix %d\n", choix, (int)choix);
        do{
            choix = getchar() - 48;//même logique que précédement
        }while( getchar() != '\n');
    }

    return(choix);
}
