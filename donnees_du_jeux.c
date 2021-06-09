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
    scanf("%d" , &demarrer);
    while (demarrer < 1 || demarrer > 3 ){
        printf("Erreure ; la saisie est enixistante");
        scanf(" %d" , &demarrer);
    }
    return demarrer;
}

void initialisation_caracteristiques_bateaux(boat *liste_bateaux){
    liste_bateaux[0].length = 2;
    liste_bateaux[1].length = 3;
    liste_bateaux[2].length = 3;
    liste_bateaux[3].length = 4;
    liste_bateaux[4].length = 5;

    for (int i = 0; i < 5 ;++i) {
        liste_bateaux[i].id = 'a' + i;
        liste_bateaux[i].id_dead = 'A' + i;
        liste_bateaux[i].pv = liste_bateaux[i].length;
        for (int j = 0; j < 5; ++j) {
            liste_bateaux[i].pv_detaille[j] = 0;
        }
    }


}