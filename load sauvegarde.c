//
// Created by Admin on 27/05/2021.
//

#include "load sauvegarde.h"

void fonction_lecture_sauvegarde(save  * sauvegarde){
   int i , j=0 ;

    FILE* fichier_sauvegarde=fopen("sauvegarde.jeu","r"); // ouverture de ficher de sauvegarde
    if ( fichier_sauvegarde != NULL ){

        char savemode  [2] ,savepv [6], saveinventory [13],savegrid [201],saveCoo[11],saveorientation[6]; // declaration des differentes variable qui von saervire de memoire tampon

        fgets(savegrid,201,fichier_sauvegarde);
        fgets(saveCoo,11,fichier_sauvegarde);
        fgets(savemode,2,fichier_sauvegarde);
        fgets(savepv,6,fichier_sauvegarde);
        fgets(saveinventory,13,fichier_sauvegarde); // 13 car il faux recupérer les 3 caractère de chaque missile
        fgets(saveorientation,6,fichier_sauvegarde);


        for (i=0 ; i < 200 ; i++){
            sauvegarde->grid_save[i]= savegrid[i];
        }

        for ( i=0 ; i< 10 ; i++){
            sauvegarde->Coo_save[i]= saveCoo[i] - 48 ; // -48 , on utilise la table ASCII, pour passer d'un caractère a un chiffre un suffit de faire -48
        }

        for (i=0 ; i<12 ; i+=3){
            sauvegarde->inventory_save[j]= (saveinventory[i+1]-48)*10  +(saveinventory[i+2])-48 ;
            j ++;
        }

        for ( i=0 ; i<5 ; i++){
            sauvegarde->orientation_save[i]=saveorientation[i]-48;
            sauvegarde->pv_save[i]=savepv[i]-48 ;
        }

        sauvegarde->mode_rep_save = savemode[0] -48; // charge le mode de eux de la précédante parti


    }else{
        printf ( " Erreure  : le fichier sauvegarde.txt pas trouver \n ");
    }
    fclose(fichier_sauvegarde);

}

void fonction_load (save  sauvegarde, Inventory * liste_missile,Grid * user_grid ,Grid *  boat_grid, int nb_bateaux, int * choix_mode_de_jeux ){
    int  deux_case = 0  , cent_case =0; //// pour sauvegarder les pv des bateaux / pou sauvegarder les Coo des bateaux
    int i =0 ;


    load_inventory (liste_missile,sauvegarde); //sauvegarder le nombre de chaque missile
    load_caracteristique_grid(boat_grid, sauvegarde,cent_case);// sauvegarde la grid de user
    cent_case += 100; //besoin pour la fonction loaad_caracteristique qui utilise une matrice de 200 pour sauvegarder deux fois une tableau dans le même matrice
    load_caracteristique_grid(user_grid, sauvegarde,cent_case); // sauvegard la grille des bateaux
    *choix_mode_de_jeux = sauvegarde.mode_rep_save;

    //load les coordonés de chaque bateau
    // sauvegarder les coordonees de chaque bateau

   // load les orientations






}





void load_inventory (Inventory * liste,  save sauvegarde ){


    liste->nb_missile_artillerie=sauvegarde.inventory_save[0] ;

    liste->nb_missile_bombe=sauvegarde.inventory_save[1] ;

    liste->nb_missile_default=sauvegarde.inventory_save[2] ;

    liste->nb_missile_tactique=sauvegarde.inventory_save[3] ;

}

void load_caracteristique_grid (Grid * grid , save sauvegarde , int cent_case){

    int i = 0,j=0;
    int dix_case=0;

    for (j=0 ; j<10 ; j++ ){
        for ( i= 0 ; i< 10 ; i++ ){
            grid->grid[i][j] = sauvegarde.grid_save[cent_case+dix_case+i] ;


        }
        dix_case += 10;
    }

}

void load_Coo (boat  * liste_bateaux, save   sauvegarde,int deux_case){

     // sauvegarder les coordonees de chaque bateau
        liste_bateaux->CooX=sauvegarde.Coo_save[deux_case ] ;
        liste_bateaux->CooY=sauvegarde.Coo_save[deux_case +1] ;
        deux_case += 2;





}




void load_orientation (boat  * liste_bateaux,save * sauvegarde,int i  ){


        liste_bateaux->orientation = sauvegarde->orientation_save[i]   ;

}


void load_pv(boat  * liste_bateaux,save  * sauvegarde,int i ){


        liste_bateaux->pv= sauvegarde->pv_save[i];


}

/**
void load_life_bateaux (boat * liste_boat, save sauvegarde,int cinq_case){ /// la vie des bateaux est sauvegarder dans 5 case (matrice)
    int i =0;
    for (i=0 ; i< 5 ; i++){
        liste_boat->pv_detaille[i] = sauvegarde.boat_live_save[cinq_case+i] ;


    }

}


void load_mode (int * rep_mode, save  sauvegarde){

    *rep_mode= sauvegarde.mode_rep_save  ; // on utilise la conversion ASCII

}


*/