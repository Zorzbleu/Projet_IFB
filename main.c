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

    tableau boat_grid, user_grid;
    missile liste_missile;






    regler_dimention(&boat_grid,&user_grid);
    bateau *liste_bateaux = NULL;
    liste_bateaux = malloc(sizeof(bateau) * 5);

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

   if (choix_demarrage == 2){ // le joueur a choisie de chrger ca dernier partie
        FILE* fichier_sauvegarde=fopen("sauvegarde.jeu","r"); // ouverture de ficher de sauvegarde
            if ( fichier_sauvegarde != NULL ){

               char savemode  [2] , savelife[26],savepv [6], saveinventory [13],savegrid [201],saveCoo[11],saveorientation[6]; // declaration des differentes variable qui von saervire de memoire tampon

                fgets(savegrid,201,fichier_sauvegarde);
                fgets(saveCoo,11,fichier_sauvegarde);
                fgets(savemode,2,fichier_sauvegarde);
                fgets(savepv,6,fichier_sauvegarde);
                fgets(saveinventory,13,fichier_sauvegarde); // 13 car il faux recupérer les 3 caractère de chaque missile
                fgets(saveorientation,6,fichier_sauvegarde);



                for (i=0 ; i < 200 ; i++){
                    sauvegarde.grid_save[i]= savegrid[i];
                }

                for ( i=0 ; i< 10 ; i++){
                    sauvegarde.Coo_save[i]= saveCoo[i]-48;
                }

                for (i=0 ; i<12 ; i+=3){
                    sauvegarde.inventory_save[j]= (saveinventory[i+1]-48)*10  +(saveinventory[i+2])-48 ;
                    j ++;
                }

                for ( i=0 ; i<5 ; i++){
                    sauvegarde.orientation_save[i]=saveorientation[i]-48;
                    sauvegarde.pv_save[i]=savepv[i]-48 ;
                }

                sauvegarde.mode_rep_save = savemode[0] -48; // charge le mode de eux de la précédante parti


            }else{
           printf ( " Erreure  : le fichier sauvegarde.txt pas trouver \n ");
           return 0;
       }
        fclose(fichier_sauvegarde);


       load_inventory (&liste_missile,&sauvegarde); //sauvegarder le nombre de chaque missile
       load_caracteristique_grid(&boat_grid, &sauvegarde,cent_case);// sauvegarde la grid de user
       cent_case += 100; //besoin pour la fonction loaad_caracteristique qui utilise une matrice de 200 pour sauvegarder deux fois une tableau dans le même matrice
       load_caracteristique_grid(&user_grid, &sauvegarde,cent_case); // sauvegard la grille des bateaux
       choix_mode_de_jeux = sauvegarde.mode_rep_save;

       //load les coordonés de chaque bateau
       for (i=0 ; i<nb_bateaux ; i +=1 ){ // sauvegarder les coordonees de chaque bateau
           load_Coo ( &liste_bateaux[i],&sauvegarde, deux_case);
           deux_case += 2;
       }

       // load les orientations
       for (i=0 ; i< nb_bateaux ; i++){
           liste_bateaux[i].orientation = sauvegarde.orientation_save[i];
       }

       for( i=0 ; i<5 ; i++){
           liste_bateaux[i].pv=sauvegarde.pv_save[i];
       }


       i=0;
       do {
           i++;
           implentation_bateau(&liste_bateaux[i], &boat_grid);
       } while (boat_grid.grid[liste_bateaux[i].CooX][liste_bateaux[i].CooY] == '_');
       if (i<1)
           printf("%d implementations !\n",i);


   }else{



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
        for (i = 0; i < nb_bateaux; i++) {
            if (liste_bateaux[i].pv == 0)
            {printf("Le bateau %c touche le fond !\n", liste_bateaux[i].id_dead);}
            else
            {printf("%c longueur %d: %d %c.\n", liste_bateaux[i].id_dead,liste_bateaux[i].length, liste_bateaux[i].pv, 3);}
        }


        printf( " Voullez vous continuer a jouer ? O/N ?\n ");
        do{
        scanf (  " %c" , &J_Q);
        }while (J_Q != 'O' && J_Q != 'N');

        if ( J_Q == 'N' ){ //le joueur a choisie d'arete de jouer, donc on sauvegard avant de "fermer" le programme


            for (i=0; i< nb_bateaux ; i ++){ // pour sauvegarder les pv de chaque bateau
                sauvegarde.pv_save[i] = liste_bateaux[i].pv;
            }

            sauvegarde.mode_rep_save = choix_mode_de_jeux; // sauvegarder le mode de jeux

            save_inventory (&liste_missile,&sauvegarde); //sauvegarder le nombre de chaque missile

            for (i=0 ; i<nb_bateaux ; i ++ ){ // sauvegarder les coordonees de chaque bateau
            save_Coo ( &liste_bateaux[i],&sauvegarde, deux_case);
            deux_case += 2;
            }

            save_caracteristique_grid(&boat_grid, &sauvegarde,cent_case);// sauvegarde la grid de user
            cent_case += 100;
            save_caracteristique_grid(&user_grid, &sauvegarde,cent_case); // sauvegard la grille des bateaux

            //save orientation ( ne marche pas pk ??? pour le bateaux n1 ca marche mais pour les bateaux 2.3.4.5 l'orientationest de 257 ??? )
            for ( i=0 ; i <nb_bateaux ; i++){
                sauvegarde.orientation_save[i] =liste_bateaux[i].orientation  ;
            }
            for ( i=0 ; i<nb_bateaux ; i++){
                printf ( "%d\n" , liste_bateaux[i].orientation);
            }
            // toutes les donnés on ete sauvgarder il faux maintenant les ecrire dans un fichier

            FILE* fichier_sauvegarde=fopen("sauvegarde.jeu","w");
            if(fichier_sauvegarde != NULL){

                char memoir_tampon_char [200] ;
                int memoir_tampon_int[100];

                // sauvegarde des donné dans deux variable
                for (i=0 ; i < 200 ; i++){
                    memoir_tampon_char[i] = sauvegarde.grid_save[i] ;
                }

                for ( i=0 ; i< 10 ; i++){
                    memoir_tampon_int[i]=sauvegarde.Coo_save[i] ;
                }

                memoir_tampon_int[10] = sauvegarde.mode_rep_save  ;

                for ( i=11; i<16; i++){
                    memoir_tampon_int[i]= sauvegarde.pv_save[i-11] ;
                }

                for (i=16 ; i<20 ; i++ ){
                    memoir_tampon_int[i]=sauvegarde.inventory_save[i-16]  +100; // comme ca peux importe le nombre de missile je sais que il vas prednre trois caractèr dans le fichier
                }

                for (i=20 ; i<25 ; i++){
                    memoir_tampon_int[i]= sauvegarde.orientation_save[i-20];
                }


                // ecriture des donné dans le fichier
                for ( i =0 ; i<200 ; i++){

                    fprintf(fichier_sauvegarde, "%c", memoir_tampon_char[i]);
                }
                for ( i = 0; i<35 ; i++){

                    fprintf(fichier_sauvegarde, "%d", memoir_tampon_int[i]);
                }


            }else{
                printf ( " Erreure  : le fichier sauvegarde.txt pas trouver \n ");
            }
            fclose(fichier_sauvegarde);




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
                do{
                srand(time(0));
                alea1 = rand () % 2+1;
                alea2 = rand () % 5 ;
                alea3 = rand () % 2 + 1  ;
                alea4 = rand () % 2+1;
                    if (alea1 == 0){

                        if (alea4 == 1 ){
                            liste_bateaux[alea2].CooX += alea3;
                        } else{
                            liste_bateaux[alea2].CooX -= alea3;

                        }

                    }else{


                        if (alea4 == 1 ){
                            liste_bateaux[alea2].CooY +=  alea3 ;
                        }else{
                            liste_bateaux[alea2].CooY -=  alea3 ;
                        }

                    }
                    }while(verification_emplacement_bateau(&liste_bateaux[alea1], &boat_grid) != 1);
                    i=0;
                    do {
                        i++;
                        implentation_bateau(&liste_bateaux[alea1], &boat_grid);
                    } while (boat_grid.grid[liste_bateaux[alea1].CooX][liste_bateaux[alea1].CooY] == '_');


                }




            }


    } while(win(liste_bateaux, nb_bateaux) != 0);


    return (0);
}