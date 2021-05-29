//
// Created by Admin on 27/05/2021.
//
#include <stdio.h>
#include "donnees_du_jeux.h"
int affichage_menu_difficulte(){
    int difficulte;
    printf("Qu'elle difficulte voulez vous ?\n"
           "1-Facile\n"
           "2-Moyen\n"
           "3-Difficile\n"
           "4- Rapelle des difference entre les modes\n");
    scanf ("%d" , &difficulte);

    while (difficulte < 1 || difficulte > 3 ){
        printf ( "Erreur : la difficulte choisie n'exite pas. ");
        scanf ("%d" , &difficulte);
    }
    return difficulte;
}

int  affichage_menu_mode_de_jeux(){
    int mode;

    printf("Bienvenue ! \n Pret a jouer a la bataille navale ?\n");
    printf ("Dans quelle mode de jeux voullez vous jouer ?\n");
    printf("Choisissez le mode de jeu :\n1. Normal\n2. Blind\n3. Active\n");
    scanf ("%d" , &mode);

    while( mode <1 || mode > 3){ // permet de controler si le mode de jeux existe
        printf ( "Erreur : le mode de jeux choisie n'exite pas. ");
        scanf ("%d" , &mode);
    }

    return mode;

}

int affichage_menu_demarrage(){
    int demarrer ;

    printf ("1- Demarrer une nouvelle partie\n2- Charger une partie existante\n3- Quitter\n");
    scanf(" %d" , demarrer);
    while (demarrer < 1 || demarrer > 3 ){
        printf("Erreure ; la saisie est enixistante")
        scanf(" %d" , demarrer);
    }
    return demarrer;
}