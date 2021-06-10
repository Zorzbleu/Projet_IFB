//
// Created by Admin on 27/05/2021.
//
#include <stdio.h>
#include "donnees_du_jeux.h"
#define e_accent_aigu 130

int affichage_menu_difficulte(){
    printf("                                                                                                                       \n"
           "                                              Choisissez la difficult%c :                                               \n"
           "                                                                                                                       \n"
           "1-Facile                    2-Moyen                  3-Difficile               4- Rappel des diff%crences entre les modes\n"
           "                                                                                         \n",e_accent_aigu,e_accent_aigu);
    return(choix_menu_multiple(4));
}


int  affichage_menu_mode_de_jeux(){
    printf("                                                                                                                       \n"
           "                                              Choisissez le mode de jeu :                                              \n"
           "                                                                                                                       \n"
           "1- Normal                                               2- Blind                                              3- Active\n"
           "                                                                                         \n");
    return(choix_menu_multiple(3));
}

int affichage_menu_demarrage(){
    printf ("                                                                                                                       \n"
            "1- Nouvelle partie                              2- Charger une partie existante                              3- Quitter\n"
            "                                                                                                                       \n");
    return(choix_menu_multiple(3));
}

void affichage_choix_missile( Inventory l_missile){
    printf("\n                      Inventory\n"
           "   ______________________________________________\n"
           "   |                                            |\n"
           "   |    1 - Normal :              %d restant",l_missile.nb_missile_default);
    if(l_missile.nb_missile_default < 10) {printf(" ");}
    printf(                                         "    |\n"
           "   |                                            |\n"
           "   |    2 - Tactique :            %d restant",l_missile.nb_missile_tactique);
    if(l_missile.nb_missile_tactique < 10) {printf(" ");}
    printf(                                         "    |\n"
           "   |                                            |\n"
           "   |    3 - Bombe :               %d restant ",l_missile.nb_missile_bombe);
    if(l_missile.nb_missile_bombe < 10)
        printf(" ");
    printf(                                          "   |\n"
           "   |                                            |\n"
           "   |    4 - Artillerie :          %d restant ",l_missile.nb_missile_artillerie);
    if(l_missile.nb_missile_artillerie < 10) {printf(" ");}
    printf(                                         "   |\n"
           "   |____________________________________________|\n");

}

int choix_missile(){
    printf("\nChoisissez votre missile.\n");
    return(choix_menu_multiple(4));
}

int choix_menu_multiple(int nombre_de_choix){
    int choix;

    do{
        fflush(stdin);

        choix = getchar() - 48; //en code ASCII, '0' a le numéro 48. On "transforme" ici un 0 "char" en 0 "int"
    }while( getchar() != '\n');

    while(choix < 1 || choix > nombre_de_choix){ // contrôle du mode de jeu
        printf( "Erreur : veuillez entrer un chiffre entre 1 et %d.\n", nombre_de_choix);

        do{
            fflush(stdin);
            choix = getchar() - 48;//même logique que précédement
        }while( getchar() != '\n');
    }

    return(choix);
}
