//
// Created by Admin on 27/05/2021.
//

#include "arbitre_de_la_partie.h"
#include "stdio.h"
#include <stdlib.h>
#include <time.h>
#include "gestion_bateau.h"

int check_win_condition(boat liste[], int nb_bateaux) {
    int i, nb_bateau_vivant=0;

    for(i=0; i < nb_bateaux;i++){
        if(liste[i].pv > 0 ) {
            nb_bateau_vivant++;
        }
    }

    return(nb_bateau_vivant);
}

int check_lose_condition(Inventory liste_missiles){
    if(liste_missiles.nb_missile_artillerie == 0 && liste_missiles.nb_missile_bombe == 0 && liste_missiles.nb_missile_tactique == 0 && liste_missiles.nb_missile_default ==0){
        return(0); // le joueur a perdu
    }
    else{
        return(1); // le joueur n'a pas perdu
    }
}

void afficher_bateau_couler_et_pv( boat liste_bateaux[],int nb_bateaux){
    int i  ;
    printf(" ____________________\n");
    for (i = 0; i < nb_bateaux*2; i++) {
        if( (i+1) % 2 == 1)
        {
            printf(" |%c longueur %d: %d %c |",liste_bateaux[i/2].id_dead,liste_bateaux[i/2].length, liste_bateaux[i/2].pv, 3);
        }
        else
        {
            if(i==nb_bateaux*2-1)
            {
                printf(" |__________________|\n");
            }
            else{
                printf(" |                  |");
            }
        }
        printf("\n");
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
        case 4 : // discritife  des differentes difficultes
            printf ("                                                                                                                       \n"
                    "                                                                                                                       \n"
                    "-1- Facile :    10 de chaque categorie.                                                                                 \n"
                    "                                                                                                                       \n"
                    "-2- Moyen :     3 missiles d'artilleries, 5 bombes, 5 missiles tactiques, 10 missiles simples.\n"
                    "                                                                                                                       \n"
                    "-3- Difficile : 1 missile d'artillerie,   2 bombes, 4 missiles tactiques, 15 missiles simples.\n\n\n");

            break;
        default :
            printf( "\nErreur : la valeur saisie n'est pas bonne.\n\nVeuillez saisir un chiffre compris entre 1 et 4.\n");


    }
}





int aleatoire_deplacer_ou_pas( int difficulte){
    int alea;
    srand(time(0));
    alea= rand() % 100 +1;

    if ( alea <= difficulte*20){
        return 1; // 1 equivaut à dire "oui un bateau vas être deplace"
    }
    return 0;

}



void modifier_coordonne ( boat * bateaux,int axe_XY,int nb_deplacement, int sens_deplacement){

    if (axe_XY == 0){

        if (sens_deplacement == 1 ){
            bateaux->CooX = bateaux->CooX + nb_deplacement;
        } else{
            bateaux->CooX = bateaux->CooX - nb_deplacement;
        }
    }else{
        if (sens_deplacement == 1 ){
            bateaux->CooY = bateaux->CooY +  nb_deplacement ;
        }else{
            bateaux->CooY = bateaux->CooY - nb_deplacement ;
        }

    }


}
void retirer_coordonner (  boat * liste_bateaux,int axe_XY, int nb_deplacement, int sens_deplacement){
    if (axe_XY == 0){

        if (sens_deplacement == 1 ){
            liste_bateaux->CooX = liste_bateaux->CooX - nb_deplacement;
        } else{
            liste_bateaux->CooX = liste_bateaux->CooX + nb_deplacement;

        }

    }else{


        if (sens_deplacement == 1 ){
            liste_bateaux->CooY = liste_bateaux->CooY -  nb_deplacement ;
        }else{
            liste_bateaux->CooY = liste_bateaux->CooY + nb_deplacement ;
        }

    }

}




void effacer_ancien_bateau (boat * bateaux , Grid * boat_grid,int nb_deplacement,int axe_XY,int sens_deplacement ){
    int i;

    for ( i = 0 ; i < bateaux->length; i++){
        if (bateaux->orientation == 0 ){
            if (axe_XY == 0){
                if (sens_deplacement == 1 ){
                    boat_grid->grid[bateaux->CooX-nb_deplacement+i][bateaux->CooY] = '_';
                }else{
                    boat_grid->grid[bateaux->CooX+nb_deplacement+i][bateaux->CooY] = '_';
                }
            }else{
                if (sens_deplacement == 1 ){
                    boat_grid->grid[bateaux->CooX+i][bateaux->CooY-nb_deplacement] = '_';//
                }else{
                    boat_grid->grid[bateaux->CooX+i] [bateaux->CooY+nb_deplacement] = '_';//
                }
            }
        }else{

            if (axe_XY == 0){
                if (sens_deplacement == 1 ){
                    boat_grid->grid[bateaux->CooX-nb_deplacement][bateaux->CooY+i]='_';
                }else{
                    boat_grid->grid[bateaux->CooX+nb_deplacement][bateaux->CooY+i]='_';
                }
            }else{
                if (sens_deplacement == 1 ){
                    boat_grid->grid[bateaux->CooX][bateaux->CooY-nb_deplacement+i]='_';//
                }else{
                    boat_grid->grid[bateaux->CooX] [bateaux->CooY+nb_deplacement+i]='_';//
                }
            }


        }

    }


}


void sauvegarder_et_placer_caracter_bateau (  boat * bateaux , Grid * boat_grid,int nb_deplacement,int axe_XY,int sens_deplacement){
    int i =0;
    char sauvegards_des_caracters [5];

    for ( i = 0 ; i < bateaux->length; i++){

        if (bateaux->orientation == 0 ){ /// bateau orienter selon l'axe des x
            if (axe_XY == 0){
                if (sens_deplacement == 1 ){
                    sauvegards_des_caracters[i] = boat_grid->grid[bateaux->CooX-nb_deplacement+i][bateaux->CooY];
                }else{
                    sauvegards_des_caracters[i] = boat_grid->grid[bateaux->CooX+nb_deplacement+i][bateaux->CooY];
                }
            }else{
                if (sens_deplacement == 1 ){
                    sauvegards_des_caracters[i] = boat_grid->grid[bateaux->CooX+i][bateaux->CooY-nb_deplacement];//
                }else{
                    sauvegards_des_caracters[i] = boat_grid->grid[bateaux->CooX+i] [bateaux->CooY+nb_deplacement];//
                }
            }
        }else{/// bateau orienter selon l'axe des Y

            if (axe_XY == 0){
                if (sens_deplacement == 1 ){
                    sauvegards_des_caracters[i] = boat_grid->grid[bateaux->CooX-nb_deplacement][bateaux->CooY+i];
                }else{
                    sauvegards_des_caracters[i] = boat_grid->grid[bateaux->CooX+nb_deplacement+i][bateaux->CooY+i];
                }
            }else{
                if (sens_deplacement == 1 ){
                    sauvegards_des_caracters[i] = boat_grid->grid[bateaux->CooX-nb_deplacement][bateaux->CooY+i];//
                }else{
                    sauvegards_des_caracters[i] = boat_grid->grid[bateaux->CooX+nb_deplacement] [bateaux->CooY+i];//
                }
            }

        }
    }

    for ( i = 0 ; i < bateaux->length; i++){
        if (bateaux->orientation == 0 ){
            boat_grid->grid[bateaux->CooX+i][bateaux->CooY] = sauvegards_des_caracters[i];
        }else{
            boat_grid->grid[bateaux->CooX][bateaux->CooY+i] = sauvegards_des_caracters[i];
        }
    }
}




void active_mode(int choix_difficulte, boat liste_bateaux[], Grid *boat_grid){
    int deplacer_ou_pas ;

    deplacer_ou_pas  = aleatoire_deplacer_ou_pas(choix_difficulte);
    if( deplacer_ou_pas == 1 ){
        int axe_XY,nb_bateau,nb_deplacement,sens_deplacement;

        srand(time(0));
        do{
            axe_XY = rand () % 2; //alea1 axe x ou y exemple : si axe_XY = 0 alors ons ce deplace dans le sens des X
            nb_bateau = rand () % 6 ; //numero du bateau
            nb_deplacement = rand () % 2 + 1  ; //nombre de deplacement
            sens_deplacement = rand () % 2+1; // + ou - Exemple si sens_deplacement = 1 alors le bateau avance si non il recule


            modifier_coordonne(&liste_bateaux[nb_bateau], axe_XY,nb_deplacement,sens_deplacement);

            if (verification_emplacement_bateau(&liste_bateaux[nb_bateau], boat_grid) != 1){/// si le ne pouvais pas ce deplacer , il faut le redonner ses coordoné d'origine
                retirer_coordonner(&liste_bateaux[nb_bateau], axe_XY,nb_deplacement,sens_deplacement);
            }
        }while(verification_emplacement_bateau(&liste_bateaux[nb_bateau], boat_grid) != 1);


        sauvegarder_et_placer_caracter_bateau(&liste_bateaux[nb_bateau],boat_grid,nb_deplacement,axe_XY,sens_deplacement);



        effacer_ancien_bateau(&liste_bateaux[nb_bateau],boat_grid,nb_deplacement,axe_XY,sens_deplacement);

        if (choix_difficulte <= 2 ){ // si le joueur joue en moyen ou en facile on lui dit qu'elle bateau a été deplacé
            printf ("Le bateau %c a ete deplacé !\n",  liste_bateaux[nb_bateau].id_dead);
        }else{
            printf (" Un bateau a ete deplace !!!!\n");
        }

    }

}

