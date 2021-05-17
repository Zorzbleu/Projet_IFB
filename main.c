#include <stdio.h>
#include <stdlib.h>
#include "fonctions initialisation bataille.h"



int main() {
    int i, nb_bateaux = 5, shootX, shootY, type_missile, hauteur, largeur;
    char shoot[3];
    tableau boat_grid, user_grid;
    boat_grid.hauteur = 10;
    boat_grid.largeur = 10;
    user_grid.hauteur = 10;
    user_grid.largeur = 10;
    bateau *liste_bateaux = NULL;
    liste_bateaux = malloc(sizeof(bateau) * nb_bateaux);
    if(liste_bateaux == NULL)
        exit(1);
    for(i = 0; i < nb_bateaux; i++) {
        liste_bateaux[i].length = i+1;
        liste_bateaux[i].id = 'a' + i;
        liste_bateaux[i].id_dead = 'A' + i;
        liste_bateaux[i].pv = liste_bateaux[i].length;
    }
    liste_bateaux[0].length = 1+nb_bateaux/2 ; liste_bateaux[0].pv = liste_bateaux[0].length;
    initialization_grille(&user_grid);
    initialization_grille(&boat_grid);
    //generation_flotte(&liste_bateaux,boat_grid,nb_bateaux);
    for(i = 0; i < nb_bateaux; i++) {
       generation_bateau(&liste_bateaux[i], &boat_grid);
    }

    do {
        show_grid(&user_grid);
        show_grid(&boat_grid);
        for (i = 0; i < nb_bateaux; i++) {
            if (liste_bateaux[i].pv == 0)
            {printf("Le bateau %c touche le fond !\n", liste_bateaux[i].id_dead);}
            else
            {printf("Le bateau %c est de longueur %d et a %d points de vie.\n", liste_bateaux[i].id_dead,liste_bateaux[i].length, liste_bateaux[i].pv);}
        }
        do{
            printf("Quel missile voulez-vous tirer ?\n1 - Missile normal : x restant\n2 - Missile tactique : x restant\n3 - Bombe : x restant\n4 - Missile d'artillerie : x restant");
            scanf("%d", &type_missile);
        } while( type_missile < 1 || type_missile > 3);
        do {
            printf("\nOu voulez-vous tirer ? Exemple : C7\n");

            gets(shoot);






            shootY = shoot[0] - 'A';
            shootX = shoot[1] - '1';
            if (shootX == 1) {
                if (shoot[2] == '0')
                    shootX = 9;
            }
        } while (shootX > 10 || shootX <= -1 || shootY > 10 || shootY <= -1);
        //printf("%d,%d", shootX, shootY);
        switch (type_missile) {
            case 1 :
                fire_missile(shootX,shootY,&boat_grid,&user_grid,liste_bateaux);
                break;
            case 2 :
                fire_tactical(shootX,shootY,&boat_grid,&user_grid,liste_bateaux);
                break;
            //case 3 :
                fire_bomb(shootX,shootY,&boat_grid,&user_grid,liste_bateaux);
                break;
            case 4 :
                fire_artillery(shootX,shootY,&boat_grid,&user_grid,liste_bateaux);
                break;
            default :
                printf("Erreur : valeur 'type missile' invalide");
                exit(0);
        }
        fire_artillery(shootX,shootY,&boat_grid, &user_grid,liste_bateaux);

    } while(win(liste_bateaux, nb_bateaux) != 0);

    return (0);
}

