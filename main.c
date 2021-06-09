#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#include "fonctions initialisation bataille.h"
#include "gestion_bateau.h"
#include "initialisation_interface.h"
#include "type_missile.h"
#include "arbitre_de_la_partie.h"
#include "donnees_du_jeux.h"
#include "sauvegarde.h"
#include "load sauvegarde.h"

#define N 10

int main() {
    int i=0, nb_bateaux=5, shootX, shootY, missile_choisie;
    char shoot[3]; // variable pour stocker les coordone de tire
    int choix_mode_de_jeux=0,choix_difficulte=0,choix_demarrage=0;
    int deplacer_ou_pas ;


    char J_Q; /// jouer ou quitter(et sauvegarde)
    save sauvegarde;
    int cinq_case = 0, deux_case = 0  , cent_case =0; //// pour sauvegarder les pv des bateaux / pou sauvegarder les Coo des bateaux
    int j = 0 ;

    Grid boat_grid, user_grid;
    Inventory liste_missile;







    regler_dimention(&boat_grid,&user_grid);
    boat *liste_bateaux = NULL;
    liste_bateaux = malloc(sizeof(boat) * 5);




   // initialization_caracteristiques_bateaux(&liste_bateaux); ne marche pas ???

    liste_bateaux[0].length = 2;
    liste_bateaux[1].length = 3;

    for (int i = 2; i < 5; ++i) {
        liste_bateaux[i].length = i+1;
    }

    for (int i = 0; i < 5; ++i) {

        liste_bateaux[i].id = 'a' +i;
        liste_bateaux[i].id_dead = 'A' +i;
        liste_bateaux[i].pv = liste_bateaux[i].length;
    }

    initialization_grille(&user_grid);
    initialization_grille(&boat_grid);









    choix_demarrage=affichage_menu_demarrage();

   if ( choix_demarrage == 3 ){ // quitter la partie
       return 0; // interomp le progamme
   }

   if (choix_demarrage == 2){
       // le joueur a choisie de charger sa dernier partie
       fonction_lecture_sauvegarde(&sauvegarde);
       fonction_load (sauvegarde,&liste_missile,&liste_bateaux,&user_grid ,&boat_grid,nb_bateaux,&choix_mode_de_jeux);
       for (i =0  ; i < nb_bateaux ; i++ ){
           load_orientation(&liste_bateaux[i],&sauvegarde,i );
           load_pv (&liste_bateaux[i],&sauvegarde,i);
           load_Coo ( &liste_bateaux[i],sauvegarde, deux_case);
           deux_case += 2;
       }


    i = 0;
       do {
           i++;
           implentation_bateau(&liste_bateaux[i], &boat_grid);
       } while (boat_grid.grid[liste_bateaux[i].CooX][liste_bateaux[i].CooY] == '_');

   }else{
       // si le joueur a choisie de load une partie il ne faux pas : generer des bateaux , demander le mode de jeux et el difficulté de jeux
       for (i = 0; i < nb_bateaux; i++) {
           generation_bateau(&liste_bateaux[i], &boat_grid); // donne une orientation aleatoire a chaque bateau en controlan que les case sont disponilbe  (fonction: verification_emplacement_bateau) et si elle le sont il place le bateaux sur la grille bateaux (fonction: implentation_bateau)
       }

       choix_mode_de_jeux= affichage_menu_mode_de_jeux();
       choix_difficulte= affichage_menu_difficulte();
       modifier_nombre_missile (choix_difficulte, &liste_missile );
   }


    do{
        if (choix_mode_de_jeux != 2 ){
            show_grid(&user_grid);
            show_grid(&boat_grid);
            }
        afficher_bateau_touche_et_pv(liste_bateaux,nb_bateaux);



        printf( " Voullez vous continuer a jouer ? O/N ?\n ");
        scanf (  " %c" , &J_Q);
        while (J_Q != 'O' && J_Q != 'N'){
            printf("Erreure  : sasie  incorrecte \n");
        scanf (  " %c" , &J_Q);
        }

        if ( J_Q == 'N' ){ //le joueur a choisie d'arete de jouer, donc on sauvegard avant de "fermer" le programme


            // On choisi d'abord de sauvegarder toues les donné utiles dans une structure.
            fonction_sauvegarde(&sauvegarde,liste_bateaux,liste_missile,user_grid,boat_grid,nb_bateaux,choix_mode_de_jeux);
            fonction_ecriture_sauvegarde(sauvegarde);
            return 0 ; // on quite le programe après voir erie dans un fichier.text la sauvegarde


        }

        missile_choisie = choix_missile_tire(&liste_missile);



        do {
            printf("Ou voulez-vous tirer ? Exemple : C7\n");
            fflush(stdin);
            gets(shoot);
            shootY = toupper(shoot[0]) - 'A';

            if (strlen(shoot) == 3){ // si le joeur a rentrer 3 caratère alors il a décider de tier dean la 10iem colonne
                shootX = 9;
            }else{
                shootX = shoot[1]-48 -1 ;
            }

        } while (shootX > 10 || shootX <= -1 || shootY > 10 || shootY <= -1);

        switch (missile_choisie) {
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

        if (choix_mode_de_jeux == 3 ){
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


                    if (verification_emplacement_bateau(&liste_bateaux[nb_bateau], &boat_grid) != 1){/// si le ne pouvais pas ce deplacer , il faut le redonner ses coordoné d'origine

                        retirer_coordonner(&liste_bateaux, axe_XY,nb_bateau,nb_deplacement,sens_deplacement);
                    }

                }while(verification_emplacement_bateau(&liste_bateaux[nb_bateau], &boat_grid) != 1);


                    char tampon [5]= {0};
                for ( i = 0 ; i < liste_bateaux[nb_bateau].length; i++){
                    sauvegarde_caracter_bateau(&liste_bateaux,&boat_grid,nb_bateau,nb_deplacement,axe_XY,sens_deplacement,&tampon[i]);
                }



                for ( i=0 ; i< liste_bateaux[nb_bateau].length ; i++){
                    placer_carater_sauvegarder_bateau(&liste_bateaux,&user_grid,&tampon[i],nb_bateau);
                }


                effacer_encien_bateau(&liste_bateaux,&boat_grid,nb_bateau,nb_deplacement,axe_XY,sens_deplacement);

                }
            printf (" Un bateau a ete deplace !!!!\n");

            }

    } while(win(liste_bateaux, nb_bateaux) != 0);


    return (0);
}