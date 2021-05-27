#include <stdio.h>
#include <stdlib.h>
#include "fonctions initialisation bataille.h"



#include "gestion_bateau.h"
#include "structure.h"
#include "tire.h"
#include "initialisation_interface.h"
#include "type_missile.h"
#include "arbitre_de_la_partie.h"
#include "donnees_du_jeux.h"
#include "sauvegarde.h"
#include "load sauvegarde.h"

#define N 10

int main() {
    int i, nb_bateaux=5, shootX, shootY, type_missile, hauteur=5, largeur=5;
    char shoot[3];
    int mode_rep,choix_difficulte_rep;
    tableau boat_grid, user_grid;
    missile liste_missile;
    int D_C_Q= 1  ;
    char J_Q; /// jouer ou quitter(et sauvegarde)
    save sauvegarde;
    int cinq_case = 0, deux_case = 0  , cent_case =0; //// pour sauvegarder les pv des bateaux / pou sauvegarder les Coo des bateaux

// ca marche pas t'a grosse merde POC !!!!!!!!!!!!!!!! tu fais de la mre d se f<sbefh g
/**
 *     printf("Entrez la taille de la grille voulu : hauteur puis largeur\n");
    scanf("%d", &hauteur);
    scanf("%d", &largeur);
    */
  //  nb_bateaux =  (hauteur + largeur)/2;

 //   grid *grid = malloc(sizeof(*grid) + hauteur + largeur);
 //   grid->largeur = largeur;

  //  grid->hauteur = hauteur;

   // grid->grid[1]=5;

    regler_dimention(&boat_grid,&user_grid);
    bateau *liste_bateaux = NULL;
    liste_bateaux = malloc(sizeof(bateau) * nb_bateaux);
    liste_bateaux[0].length = 1 + nb_bateaux / 2;
    liste_bateaux[0].pv = liste_bateaux[0].length;
    initialization_grille(&user_grid);
    initialization_grille(&boat_grid);



    D_C_Q = choix_demarrage();
   if ( D_C_Q == -1 ){
       return 0;
   }

   if (D_C_Q == 2){
        FILE* f=fopen("sauvegarde.text","r");
            if ( f != NULL ){

                sauvegarde.mode_rep_save=fscanf(f,"%d",&sauvegarde.mode_rep_save);

                for (i=0 ; i< 25 ; i++){
                sauvegarde.boat_live_save[i] =fscanf(f,"%d", &sauvegarde.boat_live_save[i]);
                }

                for (i=0 ; i < 3 ; i++){
                    sauvegarde.inventory_save[i] = fscanf(f,"%d",&sauvegarde.inventory_save[i]);
                }

                for (i=0 ; i < 200 ; i++){
                    sauvegarde.grid_save[i]= fscanf(f,"%c",&sauvegarde.grid_save[i]);
                }

                for (i=0 ; i < 10 ; i++){
                    sauvegarde.Coo_save[i]= fscanf(f,"%d",&sauvegarde.Coo_save[i]);
                }






            }
        fclose(f);


       for( i=0  ; i < 25 ; i += 5 ){ //sauvegarder les vie des bateaux
           load_life_bateaux(&liste_bateaux[i],&sauvegarde, cinq_case);
           cinq_case += 5;
       }

       load_mode(&mode_rep,&sauvegarde); // sauvegarder le mode de jeux

       load_inventory (&liste_missile,&sauvegarde); //sauvegarder le nombre de chaque missile

       for (i=0 ; i<10 ; i +=2 ){ // sauvegarder les coordonees de chaque bateau
           load_Coo ( &liste_bateaux[i],&sauvegarde, deux_case);
           deux_case += 2;
       }

       load_caracteristique_grid(&boat_grid, &sauvegarde,cent_case);// sauvegarde la grid de user
       cent_case += 100;
       load_caracteristique_grid(&user_grid, &sauvegarde,cent_case); // sauvegard la grille des bateaux




   }else{


       for (i=0 ; i< nb_bateaux ; i++){
           generer_caracteristique_bateaux (&liste_bateaux[i],i);
       }

       for (i = 0; i < nb_bateaux; i++) {
           generation_bateau(&liste_bateaux[i], &boat_grid);
       }
       //fin initialisation grilles et bateaux par default
       for ( i=0 ; i<nb_bateaux ; i++ ){
           initialisation_pv_detaille(&liste_bateaux[i]);
       }

   }










    //generation_flotte(&liste_bateaux,boat_grid,nb_bateaux);





    /**
     for (i=0 ; i < nb_bateaux ; i++ ){
        initialisation_pv_detaille (&liste_bateaux[i] );
    }
    */

    printf("Bienvenue ! \n Pret a jouer a la bataille navale ?\n");


    printf ("Dans quelle mode de jeux voullez vous jouer ?\n");
    printf("Choisissez le mode de jeu :\n1. Normal\n2. Blind\n3. Bruh\n");
    do{
        scanf ("%d" , &mode_rep);
        mode_de_jeux( mode_rep);
    }while( mode_rep <1 || mode_rep > 3);


    //clear_text(0);

    printf("Qu'elle difficulte voulez vous ?\n"
           "1-Facile\n"
           "2-Moyen\n"
           "3-Difficile\n"
           "4- Rapelle des difference entre les modes\n");
    do{
        scanf ( "%d" ,  &choix_difficulte_rep);
        choix_difficulte( choix_difficulte_rep,&liste_missile);

    }while (choix_difficulte_rep <1 || choix_difficulte_rep > 3 );


    do{
        if (mode_rep != 2 ){
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
        scanf (  " %c" , &J_Q);
        if ( J_Q == 'N' ){
            for (i=0 ; i<nb_bateaux ; i++ ){
            sauvegarde_pv_detaille(&liste_bateaux[i],user_grid);
            }
            for( i=0  ; i < 25 ; i += 5 ){ //sauvegarder les vie des bateaux
            save_life_bateaux(&liste_bateaux[i],&sauvegarde, cinq_case);
            cinq_case += 5;
            }

            save_mode(mode_rep,&sauvegarde); // sauvegarder le mode de jeux

            save_inventory (&liste_missile,&sauvegarde); //sauvegarder le nombre de chaque missile

            for (i=0 ; i<10 ; i +=2 ){ // sauvegarder les coordonees de chaque bateau
            save_Coo ( &liste_bateaux[i],&sauvegarde, deux_case);
            deux_case += 2;
            }

            save_caracteristique_grid(&boat_grid, &sauvegarde,cent_case);// sauvegarde la grid de user
            cent_case += 100;
            save_caracteristique_grid((&user_grid), &sauvegarde,cent_case); // sauvegard la grille des bateaux

            FILE* f=fopen("sauvegarde.text","w");
            if(f != NULL){
                fprintf(f, "%d" , sauvegarde.mode_rep_save);

                for (i=0 ; i<25 ; i++){
                printf(f, "%d", sauvegarde.boat_live_save[i]);
                }
                fprintf(f,"");

                for( i=0 ; i< 3 ; i++){
                fprintf(f, "%d",sauvegarde.inventory_save[i] );
                }


                for( i=0 ; i< 200 ; i++){
                    fprintf(f, "%d",sauvegarde.grid_save[i] );
                }



                for( i=0 ; i< 10 ; i++){
                    fprintf(f,"%d",sauvegarde.Coo_save[i]);
                }








                fprintf(f,"%d%d%d%d" ,sauvegarde.mode_rep_save,sauvegarde.boat_live_save,sauvegarde.inventory_save,sauvegarde.Coo_save , f );
                fprintf(f,"%s",sauvegarde.grid_save);
            }
            fclose(f);





            // save_caracteristique_grid(&user_grid, &user_boat_grid);


            return 0 ; // pour quitter le programme

        }



        do{
            printf("\nQuel missile voulez-vous tirer ?\n1 - Missile normal : %d restant\n2 - Missile tactique : %d restant\n3 - Bombe : %d restant\n4 - Missile d'artillerie : %d restant\n",
                   liste_missile.nb_missile_default, liste_missile.nb_missile_tactique, liste_missile.nb_missile_bombe, liste_missile.nb_missile_artillerie);
            scanf(" %d", &type_missile);
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
        for ( i =0 ;i < nb_bateaux; i++){
            //sauvegarde_pv_detaille(&liste_bateaux[i],user_grid);
        }
    } while(win(liste_bateaux, nb_bateaux) != 0);

    return (0);
}