//
// Created by Admin on 27/05/2021.
//

#include <stdio.h>
#include "sauvegarde.h"

void fonction_ecriture_sauvegarde(save sauvegarde){
    int i=0 ;

    FILE* fichier_sauvegarde=fopen("sauvegarde.jeu","w");
    if(fichier_sauvegarde != NULL){
        // permet de faire que deux print f
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


}


void fonction_sauvegarde( save * sauvegarde, boat liste_bateaux[],Inventory liste_missile , Grid user_grid,Grid boat_grid,int nb_bateaux,int choix_mode_de_jeux ){

    int i=0;
    int deux_case = 0 ; // utile a la sauvegarde de coordonnés
    int cent_case =0 ; //permet la sauegard du tableau user et tableau boat

    save_pv( liste_bateaux,sauvegarde,nb_bateaux);



    sauvegarde->mode_rep_save = choix_mode_de_jeux; // sauvegarder le mode de jeux

    save_inventory (&liste_missile,sauvegarde); //sauvegarder le nombre de chaque missile

     // sauvegarder les coordonees de chaque bateau
     save_Coo ( liste_bateaux,sauvegarde, deux_case,nb_bateaux);


    save_caracteristique_grid(&boat_grid, sauvegarde,cent_case);// sauvegarde la grid de user
    cent_case += 100;
    save_caracteristique_grid(&user_grid, sauvegarde,cent_case); // sauvegard la grille des bateaux

    //save orientation ( ne marche pas pk ??? pour le bateaux n1 ca marche mais pour les bateaux 2.3.4.5 l'orientationest de 257 ??? )
    save_orientation(liste_bateaux,sauvegarde,nb_bateaux);


    // toutes les donnés on ete sauvgarder il faux maintenant les ecrire dans un fichier


}

void save_inventory (Inventory * liste,  save * sauvegarde ){



    sauvegarde->inventory_save[0] = liste->nb_missile_artillerie ;
    sauvegarde->inventory_save[1] = liste->nb_missile_bombe ;
    sauvegarde->inventory_save[2] = liste->nb_missile_default  ;
    sauvegarde->inventory_save[3] = liste->nb_missile_tactique ;
}





void save_Coo (boat  liste[], save * sauvegarde,int deux_case,int nb_bateaux){
    int i = 0 ;
    for (i=0 ; i<nb_bateaux ; i ++ ){ // sauvegarder les coordonees de chaque bateau
        sauvegarde->Coo_save[deux_case ] = liste[i].CooX;
        sauvegarde->Coo_save[deux_case +1] = liste[i].CooY;

        deux_case += 2;
    }



}

void save_caracteristique_grid (Grid * grid , save * sauvegarde , int cent_case){

    int i = 0,j=0;
    int dix_case=0;

    for (j=0 ; j<10 ; j++ ){
        for ( i= 0 ; i< 10 ; i++ ){
            sauvegarde->grid_save[cent_case+dix_case+i] = grid->grid[i][j];


        }
    dix_case += 10;
    }

}

void save_orientation(boat liste_bateaux[],save * sauvegarde,int nb_bateaux){
    int i = 0 ;
    for ( i=0 ; i <nb_bateaux ; i++){
        sauvegarde->orientation_save[i] =liste_bateaux[i].orientation  ;
    }

}
void save_pv(boat liste_bateaux[],save * sauvegarde,int nb_bateaux){
    int i = 0 ;

    for (i=0; i< nb_bateaux ; i ++){ // pour sauvegarder les pv de chaque bateau
        sauvegarde->pv_save[i] = liste_bateaux[i].pv;
    }


}