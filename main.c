#include <stdio.h>
#include <stdlib.h>
#include "fonctions initialisation bataille.h"



int main() {
    int i, nb_bateaux, shootX, shootY, type_missile, hauteur, largeur, difficulte, mode_de_jeu;
    char shoot[3];


    printf("Entrez la taille de la grille voulu : hauteur puis largeur\n");
    scanf("%d", &hauteur);
    scanf("%d", &largeur);
    nb_bateaux =  (hauteur + largeur)/2;

    grid *grid = malloc(sizeof(*grid) + hauteur + largeur);
    grid->largeur = largeur;

    grid->hauteur = hauteur;

    grid->grid[1]=5;



    tableau boat_grid, user_grid;
    boat_grid.hauteur = N;
    boat_grid.largeur = N;
    user_grid.hauteur = N;
    user_grid.largeur = N;
    bateau *liste_bateaux = NULL;
    missile liste_missile;
    liste_bateaux = malloc(sizeof(bateau) * nb_bateaux);
    if (liste_bateaux == NULL)
        exit(1);
    for (i = 0; i < nb_bateaux; i++) {
        liste_bateaux[i].length = i + 1;
        liste_bateaux[i].id = 'a' + i;
        liste_bateaux[i].id_dead = 'A' + i;
        liste_bateaux[i].pv = liste_bateaux[i].length;
    }
    liste_bateaux[0].length = 1 + nb_bateaux / 2;
    liste_bateaux[0].pv = liste_bateaux[0].length;
    initialization_grille(&user_grid);
    initialization_grille(&boat_grid);
    //generation_flotte(&liste_bateaux,boat_grid,nb_bateaux);


    for (i = 0; i < nb_bateaux; i++) {
        generation_bateau(&liste_bateaux[i], &boat_grid);
    }
    //fin initialisation grilles et bateaux par default


    printf("Bienvenue ! \n Pret a jouer a la bataille navale ?\n");
    printf("Choisissez le mode de jeu :\n1. Normal\n2. Blind\n3. Bruh\n");
    do { scanf("%d", &mode_de_jeu); } while (mode_de_jeu > 3 || mode_de_jeu < 1);

    //clear_text(0);
    printf("Choisissez la difficulte :\n1. Facile\n2. Normal\n3. Difficile\n");
    do { scanf("%d", &difficulte); } while (difficulte > 3 || difficulte < 1);

    switch (difficulte) {
        case 1:
            liste_missile.nb_missile_artillerie = 10;
            liste_missile.nb_missile_bombe = 10;
            liste_missile.nb_missile_default = 10;
            liste_missile.nb_missile_tactique = 10;
            break;
        case 2:
            liste_missile.nb_missile_artillerie = 3;
            liste_missile.nb_missile_bombe = 4;
            liste_missile.nb_missile_default = 10;
            liste_missile.nb_missile_tactique = 5;
            break;
        case 3:
            liste_missile.nb_missile_artillerie = 1;
            liste_missile.nb_missile_bombe = 3;
            liste_missile.nb_missile_default = 10;
            liste_missile.nb_missile_tactique = 2;
            break;
        default :
            printf("Erreur : difficulté non comprise entre 1 et 3");
            exit(0);
    }

    do{
        if (mode_de_jeu != 2 ){show_grid(&user_grid);}
        show_grid(&boat_grid);
        for (i = 0; i < nb_bateaux; i++) {
            if (liste_bateaux[i].pv == 0)
            {printf("Le bateau %c touche le fond !\n", liste_bateaux[i].id_dead);}
            else
            {printf("%c longueur %d: %d %c.\n", liste_bateaux[i].id_dead,liste_bateaux[i].length, liste_bateaux[i].pv, 3);}
        }
        do{
            printf("\nQuel missile voulez-vous tirer ?\n1 - Missile normal : %d restant\n2 - Missile tactique : %d restant\n3 - Bombe : %d restant\n4 - Missile d'artillerie : %d restant\n",
                   liste_missile.nb_missile_default, liste_missile.nb_missile_tactique, liste_missile.nb_missile_bombe, liste_missile.nb_missile_artillerie);
            scanf("%d ", &type_missile);
        } while( type_missile < 0 || type_missile > 4);

        do {
            printf("Ou voulez-vous tirer ? Exemple : C7\n");
            fflush(stdin);
            gets(shoot);
            shootY = shoot[0] - 'A';
            shootX = shoot[1] - '1';
            if (shootX == 1) {
                if (shoot[2] == '0')
                    shootX = 9;
            }
        } while (shootX > 10 || shootX <= -1 || shootY > 10 || shootY <= -1);

        switch (type_missile) {
            case 1 :
                fire_missile(shootX,shootY,&boat_grid,&user_grid,liste_bateaux,&liste_missile);
                break;
            case 2 :
                fire_tactical(shootX,shootY,&boat_grid,&user_grid,liste_bateaux,&liste_missile);
                break;
            case 3 :
                fire_bomb(shootX,shootY,&boat_grid,&user_grid,liste_bateaux,&liste_missile);
                break;
            case 4 :
                fire_artillery(shootX,shootY,&boat_grid,&user_grid,liste_bateaux,&liste_missile);
                break;
            default :
                printf("Erreur : valeur 'type_missile' invalide");
                exit(0);
        }


    } while(win(liste_bateaux, nb_bateaux) != 0);

    return (0);
}