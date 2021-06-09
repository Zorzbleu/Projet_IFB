#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "type_missile.h"
#include "fonctions initialisation bataille.h"
#include "gestion_bateau.h"
#include "initialisation_interface.h"
#include "arbitre_de_la_partie.h"
#include "donnees_du_jeux.h"
#include "sauvegarde.h"
#include "load sauvegarde.h"
#include "fonctions_tour_de_jeu.h"

#define N 10

int main() {
    int i;
    int nb_bateaux=5; //donne le nombre de bateau sur la grille (dans notre cas, 5)


    int missile_choisie;

    int choix_mode_de_jeux=0,choix_difficulte=0,choix_demarrage=0; //choix par défaut
    int deplacer_ou_pas; //gère la probabilité de déplacement d'un bateau en mode active
    int deux_case = 0; // pour sauvegarder les pv des bateaux / pour sauvegarder les Coo des bateaux


    int J_Q; // jouer ou quitter(et sauvegarde)
    save sauvegarde;




    //déclaration des structures utilisées par défaut dans le jeu
    Grid boat_grid, user_grid;
    Inventory liste_missile;
    Missile_Coordinates Coordonnees_missile;
    //initialisation de la liste des 5 bateaux
    boat *liste_bateaux = NULL;
    liste_bateaux = malloc(sizeof(boat) * nb_bateaux);


    initialization_default(&boat_grid, &user_grid, liste_bateaux, nb_bateaux);







    //Le programme démarre : menu principal

    choix_demarrage=affichage_menu_demarrage();
    switch(choix_demarrage) {

        case 3 :
            return 0;

        case 2 :
            fonction_lecture_sauvegarde(&sauvegarde);
            fonction_load (sauvegarde,&liste_missile,&liste_bateaux,&user_grid ,&boat_grid,nb_bateaux,&choix_mode_de_jeux);
            for (i =0  ; i < nb_bateaux ; i++ ){
                load_orientation(&liste_bateaux[i],sauvegarde,i );
                load_pv (&liste_bateaux[i],sauvegarde,i);
                load_Coo ( &liste_bateaux[i],sauvegarde, deux_case);
                deux_case += 2;
            }


            i = 0;
            do {
                i++;
                implentation_bateau(&liste_bateaux[i], &boat_grid);
            } while (boat_grid.grid[liste_bateaux[i].CooX][liste_bateaux[i].CooY] == '_');
            break;

        case 1 :
            for (i = 0; i < nb_bateaux; i++) {
                generation_bateau(&liste_bateaux[i], &boat_grid);
            }

            choix_mode_de_jeux= affichage_menu_mode_de_jeux();
            choix_difficulte= affichage_menu_difficulte();
            modifier_nombre_missile (choix_difficulte, &liste_missile );


    do{
        if (choix_mode_de_jeux != 2 ){
            show_grid(&user_grid);
            show_grid(&boat_grid);
        }
        afficher_bateau_touche_et_pv(liste_bateaux,nb_bateaux);



        printf( "Voulez-vous continuer a jouer ? O/N ?\n ");
        do{
            J_Q = fgetc(stdin);
        }while( getchar() != '\n');
        while (J_Q != 'O' && J_Q != 'N'){
            printf("Erreur  : saisie  incorrecte \n");
            do{
                J_Q = fgetc(stdin);
            }while( getchar() != '\n');
        }

        if ( J_Q == 'N' ){ //le joueur a choisie d'arreter de jouer, donc on sauvegarde avant de "fermer" le programme


            // On choisit d'abord de sauvegarder toues les donné utiles dans une structure.
            fonction_sauvegarde(&sauvegarde,liste_bateaux,liste_missile,user_grid,boat_grid,nb_bateaux,choix_mode_de_jeux);
            fonction_ecriture_sauvegarde(sauvegarde);
            return 0 ; // on quitte le programme après avoir écrit dans un fichier.txt la sauvegarde
        }

        missile_choisie = choix_missile_tire(&liste_missile);

        coordonnees_tir(&Coordonnees_missile);
        lancement_tir(Coordonnees_missile, missile_choisie, &boat_grid, &user_grid, &liste_bateaux, &liste_missile);



        if (choix_mode_de_jeux == 3 ){
            //active_mode(choix_difficulte, liste_bateaux, &boat_grid, &user_grid);
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
            break;
        default:
            break;
    }





       // si le joueur a choisie de load une partie, il ne faut pas : generer des bateaux , demander le mode de jeux, demander la difficulté de jeu



    return (0);
}