//
// Created by Admin on 27/05/2021.
//

#include "arbitre_de_la_partie.h"
#include "stdio.h"
#include <stdlib.h>
#include <time.h>


int win(boat liste[], int nb_bateaux) {
    int i, nb_bateau_vivant=0;

    for(i=0; i < nb_bateaux;i++){
        if(liste[i].pv > 0 ) {
            nb_bateau_vivant++;
        }
    }

    return(nb_bateau_vivant);
}

void afficher_bateau_touche_et_pv( boat liste_bateaux[],int nb_bateaux){
    int i  ;

    for (i = 0; i < nb_bateaux; i++) {
        if (liste_bateaux[i].pv == 0)
        {printf("Le bateau %c touche le fond !\n", liste_bateaux[i].id_dead);}
        else
        {printf("%c longueur %d: %d %c.\n", liste_bateaux[i].id_dead,liste_bateaux[i].length, liste_bateaux[i].pv, 3);}
    }


}




void modifier_nombre_missile (int difficulte, Inventory * liste ){


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
            printf("Qu'elle difficulte voulez-vous ?\n");
            break;
        default :
            printf( "Erreur : la valeur saisie n'est pas bonne.\nVeuillez saisir un chiffre compris entre 1 et 4.\n");


    }
}



int choix_missile_tire( Inventory * l_missile){
    int missile ; // stock le choix du joueur

        printf("\nQuel missile voulez-vous tirer ?\n1 - Missile normal : %d restant\n2 - Missile tactique : %d restant\n3 - Bombe : %d restant\n4 - Missile d'artillerie : %d restant\n",
               l_missile->nb_missile_default, l_missile->nb_missile_tactique, l_missile->nb_missile_bombe, l_missile->nb_missile_artillerie);
    do{
        missile = fgetc(stdin) - 48;
    }while( getchar() != '\n');


    while( missile < 0 || missile > 4){
        printf ( "Erreur : le type de missile choisie n'existe pas ");
        do{
            missile = fgetc(stdin) - 48;
        }while( getchar() != '\n');
    }

    return missile;
}

int aleatoir_deplacer_ou_pas( int difficulte){
    int alea;
    srand(time(0));
    alea= rand() % 100 +1;


return 1 ;
    if ( alea <= difficulte*20){
        return 1; // 1 equivau a dire"oui un bateau est deplace"
    }
    return 0;

}






void ajouter_coordonne ( boat * liste_bateaux[],int axe_XY, int nb_bateau,int nb_deplacement, int sens_deplacement){

    if (axe_XY == 0){

        if (sens_deplacement == 1 ){
            liste_bateaux[nb_bateau]->CooX = liste_bateaux[nb_bateau]->CooX + nb_deplacement;
        } else{
            liste_bateaux[nb_bateau]->CooX = liste_bateaux[nb_bateau]->CooX - nb_deplacement;
        }
    }else{
        if (sens_deplacement == 1 ){
            liste_bateaux[nb_bateau]->CooY = liste_bateaux[nb_bateau]->CooY +  nb_deplacement ;
        }else{
            liste_bateaux[nb_bateau]->CooY = liste_bateaux[nb_bateau]->CooY - nb_deplacement ;
        }

    }


}
void retirer_coordonner (  boat * liste_bateaux[],int axe_XY, int nb_bateau,int nb_deplacement, int sens_deplacement){
    if (axe_XY == 0){

        if (sens_deplacement == 1 ){
            liste_bateaux[nb_bateau]->CooX = liste_bateaux[nb_bateau]->CooX - nb_deplacement;
        } else{
            liste_bateaux[nb_bateau]->CooX = liste_bateaux[nb_bateau]->CooX + nb_deplacement;

        }

    }else{


        if (sens_deplacement == 1 ){
            liste_bateaux[nb_bateau]->CooY = liste_bateaux[nb_bateau]->CooY -  nb_deplacement ;
        }else{
            liste_bateaux[nb_bateau]->CooY = liste_bateaux[nb_bateau]->CooY + nb_deplacement ;
        }

    }

}



void sauvegarde_caracter_bateau ( boat * liste_bateaux[] , Grid * boat_grid,int nb_bateau,int nb_deplacement,int axe_XY,int sens_deplacement ,char * tampon){
    int i =0;



        if (liste_bateaux[nb_bateau]->orientation == 0 ){
            if (axe_XY == 0){
                if (sens_deplacement == 1 ){
                  *tampon = boat_grid->grid[liste_bateaux[nb_bateau]->CooX-nb_deplacement+i][liste_bateaux[nb_bateau]->CooY];
                }else{
                   * tampon = boat_grid->grid[liste_bateaux[nb_bateau]->CooX+nb_deplacement+i][liste_bateaux[nb_bateau]->CooY];
                }
            }else{
                if (sens_deplacement == 1 ){
                    *tampon = boat_grid->grid[liste_bateaux[nb_bateau]->CooX+i][liste_bateaux[nb_bateau]->CooY-nb_deplacement];//
                }else{
                    *tampon = boat_grid->grid[liste_bateaux[nb_bateau]->CooX+i] [liste_bateaux[nb_bateau]->CooY+nb_deplacement];//
                }
            }
        }else{//////////////// bateau orienter selon l'axe des Y

            if (axe_XY == 0){
                if (sens_deplacement == 1 ){
                    *tampon = boat_grid->grid[liste_bateaux[nb_bateau]->CooX-nb_deplacement][liste_bateaux[nb_bateau]->CooY+i];
                }else{
                    *tampon = boat_grid->grid[liste_bateaux[nb_bateau]->CooX+nb_deplacement+i][liste_bateaux[nb_bateau]->CooY+i];
                }
            }else{
                if (sens_deplacement == 1 ){
                   *tampon = boat_grid->grid[liste_bateaux[nb_bateau]->CooX][liste_bateaux[nb_bateau]->CooY-nb_deplacement+i];//
                }else{
                    *tampon = boat_grid->grid[liste_bateaux[nb_bateau]->CooX] [liste_bateaux[nb_bateau]->CooY+nb_deplacement+i];//
                }
            }

        }



}
void placer_carater_sauvegarder_bateau ( boat * liste_bateaux[] , Grid * boat_grid,char * tampon,int nb_bateau){
    int i =0;

        if (liste_bateaux[nb_bateau]->orientation == 0 ){
            boat_grid->grid[liste_bateaux[nb_bateau]->CooX+i][liste_bateaux[nb_bateau]->CooY] = *tampon;
        }else{
            boat_grid->grid[liste_bateaux[nb_bateau]->CooX][liste_bateaux[nb_bateau]->CooY+i] = *tampon;
        }
        show_grid(boat_grid);





}


void effacer_encien_bateau (boat * liste_bateaux[] , Grid * boat_grid,int nb_bateau,int nb_deplacement,int axe_XY,int sens_deplacement ){
    int i = 0 ;

    for ( i = 0 ; i < liste_bateaux[nb_bateau]->length; i++){
        if (liste_bateaux[nb_bateau]->orientation == 0 ){
            if (axe_XY == 0){
                if (sens_deplacement == 1 ){
                    boat_grid->grid[liste_bateaux[nb_bateau]->CooX-nb_deplacement+i][liste_bateaux[nb_bateau]->CooY] = '_';
                }else{
                    boat_grid->grid[liste_bateaux[nb_bateau]->CooX+nb_deplacement+i][liste_bateaux[nb_bateau]->CooY] = '_';
                }
            }else{
                if (sens_deplacement == 1 ){
                    boat_grid->grid[liste_bateaux[nb_bateau]->CooX+i][liste_bateaux[nb_bateau]->CooY-nb_deplacement] = '_';//
                }else{
                    boat_grid->grid[liste_bateaux[nb_bateau]->CooX+i] [liste_bateaux[nb_bateau]->CooY+nb_deplacement] = '_';//
                }
            }
        }else{

            if (axe_XY == 0){
                if (sens_deplacement == 1 ){
                    boat_grid->grid[liste_bateaux[nb_bateau]->CooX-nb_deplacement][liste_bateaux[nb_bateau]->CooY+i]='_';
                }else{
                    boat_grid->grid[liste_bateaux[nb_bateau]->CooX+nb_deplacement+i][liste_bateaux[nb_bateau]->CooY+i]='_';
                }
            }else{
                if (sens_deplacement == 1 ){
                    boat_grid->grid[liste_bateaux[nb_bateau]->CooX][liste_bateaux[nb_bateau]->CooY-nb_deplacement+i]='_';//
                }else{
                    boat_grid->grid[liste_bateaux[nb_bateau]->CooX] [liste_bateaux[nb_bateau]->CooY+nb_deplacement+i]='_';//
                }
            }


        }

    }


}
