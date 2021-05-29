//
// Created by Admin on 27/05/2021.
//

#include "arbitre_de_la_partie.h"
#include "stdio.h"
#include <stdlib.h>
#include <time.h>
#include "gestion_bateau.h"

int win(bateau liste[], int nb_bateaux) {
    int i, nb_bateau_vivant=0;

    for(i=0; i < nb_bateaux;i++){
        if(liste[i].pv > 0 ) {
            nb_bateau_vivant++;
        }
    }

    return(nb_bateau_vivant);
}




void modifier_nombre_missile (int difficulte, missile * liste ){


    switch (difficulte){
        case  1 : // Normal
            liste->nb_missile_artillerie = 10;
            liste->nb_missile_bombe = 10;
            liste->nb_missile_default = 10;
            liste->nb_missile_tactique = 10;

            break;
        case 2 : // Moyen
            liste->nb_missile_artillerie = 3;
            liste->nb_missile_bombe = 5;
            liste->nb_missile_default = 10;
            liste->nb_missile_tactique = 5;

            break;
        case 3 : // Difficile
            liste->nb_missile_artillerie = 1;
            liste->nb_missile_bombe = 2;
            liste->nb_missile_default = 15;
            liste->nb_missile_tactique = 4;


            break;
        case 4 : // discitife des differances des differentes diffiucultes
            printf (
                    "-1- Facile : 10 de chaque categorie\n"
                    "-2- Moyen :  3 missiles de artilleries, 5 bombes, 5 missiles tactiques, 10 missiles simples\n"
                    "-3- Difficile : 1 missile de artillerie, 2 bombes, 4 missiles tactiques, 15 missiles simples\n\n\n");
            printf("Qu elle difficulte voulez vous ?\n");
            break;
        default :
            printf( "Erreur : la valeur saise n'est pas bonne.\nVeuillez saisire un chiffre compris enttre 1  et 4\n");


    }
}



int choix_missile_tire( missile * l_missile){
    int missile ; // stock le choix du joeur

        printf("\nQuel missile voulez-vous tirer ?\n1 - Missile normal : %d restant\n2 - Missile tactique : %d restant\n3 - Bombe : %d restant\n4 - Missile d'artillerie : %d restant\n",
               l_missile->nb_missile_default, l_missile->nb_missile_tactique, l_missile->nb_missile_bombe, l_missile->nb_missile_artillerie);
        scanf(" %d", &missile);


    while( missile < 0 || missile > 4){
        printf ( "Erreur : le type de missile choisie n'existe pas ");
        scanf(" %d", &missile);
    }

    return missile;
}

int aleatoir_deplacer_ou_pas( int difficulte){
    int alea;
    srand(time(0));
    alea= rand() % 100 +1;



    if ( alea <= difficulte*20){
        return 1; // 1 equivau a dire"oui un bateau est deplace"
    }
    return 0;

}



