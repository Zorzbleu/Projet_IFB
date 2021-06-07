#include <stdio.h>
#include <stdlib.h>
#include <time.h>




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
    int i, nb_bateaux=5, shootX, shootY, missile_choisie;
    char shoot[3]; // variable pour stocker les coordone de tire
    int choix_mode_de_jeux,choix_difficulte,choix_demarrage;
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

    liste_bateaux[0].length = 1 + nb_bateaux / 2;// utile ?
    liste_bateaux[0].pv = liste_bateaux[0].length;// utile ??

    initialization_grille(&user_grid);
    initialization_grille(&boat_grid);


// a remplacer (génération des bateaux)
    liste_bateaux[0].length = 2;
    liste_bateaux[0].id = 'a' ;
    liste_bateaux[0].id_dead = 'A' ;
    liste_bateaux[0].pv = 2;

    liste_bateaux[1].length = 3;
    liste_bateaux[1].id = 'b' ;
    liste_bateaux[1].id_dead = 'B' ;
    liste_bateaux[1].pv = 3;

    liste_bateaux[2].length = 3;
    liste_bateaux[2].id = 'c' ;
    liste_bateaux[2].id_dead = 'C' ;
    liste_bateaux[2].pv = 3;

    liste_bateaux[3].length = 4;
    liste_bateaux[3].id = 'd' ;
    liste_bateaux[3].id_dead = 'D' ;
    liste_bateaux[3].pv = 4;

    liste_bateaux[4].length = 5;
    liste_bateaux[4].id = 'e' ;
    liste_bateaux[4].id_dead = 'E' ;
    liste_bateaux[4].pv = 5;





    choix_demarrage=affichage_menu_demarrage();

   if ( choix_demarrage == 3 ){ // quitter la partie
       return 0; // interomp le progamme
   }

   if (choix_demarrage == 2){
       // le joueur a choisie de charger sa dernier partie
       fonction_lecture_sauvegarde(&sauvegarde);
       fonction_load (sauvegarde,&liste_missile,&user_grid ,&boat_grid,nb_bateaux,&choix_mode_de_jeux);
       for (i =0  ; i < nb_bateaux ; i++ ){
           load_orientation(&liste_bateaux[i],&sauvegarde,i );
           load_pv (&liste_bateaux[i],&sauvegarde,i);
           load_Coo ( &liste_bateaux[i],sauvegarde, deux_case);
           deux_case += 2;
       }



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
            return 0 ; // pour quitter le programme


        }

        missile_choisie = choix_missile_tire(&liste_missile);



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

                printf (" Un bateau a ete deplace !!!!\n");
                int alea1,alea2,alea3,alea4;

                srand(time(0));
                do{
                alea1 = rand () % 2;
                alea2 = rand () % 6 ;
                alea3 = rand () % 2 + 1  ;
                alea4 = rand () % 2+1;
                for (i=0 ; i< liste_bateaux[alea2].length ; i++){
                    if (alea1 == 0){

                        if (alea4 == 1 ){
                            boat_grid.grid[liste_bateaux[alea2].CooX+alea3+i][liste_bateaux[alea2].CooY] = boat_grid.grid[liste_bateaux[alea2].CooX+i][liste_bateaux[alea2].CooY];

                        } else{
                            boat_grid.grid[liste_bateaux[alea2].CooX-alea3+i][liste_bateaux[alea2].CooY]  =  boat_grid.grid[liste_bateaux[alea2].CooX+i][liste_bateaux[alea2].CooY] ;

                        }

                    }else{


                        if (alea4 == 1 ){
                            boat_grid.grid[liste_bateaux[alea1].CooX] [liste_bateaux[alea2].CooY+alea3+i] = boat_grid.grid[liste_bateaux[alea2].CooX] [liste_bateaux[alea2].CooY+i];
                        }else{
                            boat_grid.grid[liste_bateaux[alea1].CooX][liste_bateaux[alea2].CooY-alea3+i] = boat_grid.grid[liste_bateaux[alea2].CooX][liste_bateaux[alea2].CooY+i] ;

                        }

                    }
                }
                    }while(verification_emplacement_bateau(&liste_bateaux[alea2], &boat_grid) != 1);
                    i=0;
                }

                i=0;
                do {
                    i++;
                    implentation_bateau(&liste_bateaux[i], &boat_grid);
                } while (boat_grid.grid[liste_bateaux[i].CooX][liste_bateaux[i].CooY] == '_');



/**
                //initialization_grille(&boat_grid);
                for (i=0 ; i< alea3 ; i++){
                    if( alea1 == 0 ){
                        if (alea4 == 1 ){
                            boat_grid.grid[liste_bateaux[alea1].CooX-alea3+i][liste_bateaux[alea1].CooY] = '_';
                        }else{
                            boat_grid.grid[liste_bateaux[alea1].CooX+alea3+i][liste_bateaux[alea1].CooY] = '_';
                            }
                        }else{
                            if (alea4 == 1 ){
                                boat_grid.grid[liste_bateaux[alea1].CooX][liste_bateaux[alea1].CooY-alea3+i] = '_';
                            }else{
                                boat_grid.grid[liste_bateaux[alea1].CooX] [liste_bateaux[alea1].CooY+alea3+i]= '_';
                        }

                    }
                }
*/


                }



    } while(win(liste_bateaux, nb_bateaux) != 0);


    return (0);
}