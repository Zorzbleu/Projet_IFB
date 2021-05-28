//
// Created by Admin on 27/05/2021.
//

#include "load sauvegarde.h"
#include "structure.h"

void load_life_bateaux (bateau * liste_boat, save * sauvegarde,int cinq_case){ /// la vie des bateaux est sauvegarder dans 5 case (matrice)
    int i =0;
    for (i=0 ; i< 5 ; i++){
        liste_boat->pv_detaille[i] = sauvegarde->boat_live_save[cinq_case+i] ;


    }

}

void load_mode (int * rep_mode, save * sauvegarde){

    *rep_mode= sauvegarde->mode_rep_save  ; // on utilise la conversion ASCII

}


void load_inventory (missile * liste,  save * sauvegarde ){


    liste->nb_missile_artillerie=sauvegarde->inventory_save[0] ;

    liste->nb_missile_bombe=sauvegarde->inventory_save[1] ;

    liste->nb_missile_default=sauvegarde->inventory_save[2] ;

    liste->nb_missile_tactique=sauvegarde->inventory_save[3] ;

}

void load_Coo (bateau  * liste, save * sauvegarde,int deux_case){



        liste->CooX=sauvegarde->Coo_save[deux_case ] ;
        liste->CooY=sauvegarde->Coo_save[deux_case +1] ;


}


void load_caracteristique_grid (tableau * grid , save * sauvegarde , int cent_case){

    int i = 0,j=0;
    int dix_case=0;

    for (j=0 ; j<10 ; j++ ){
        for ( i= 0 ; i< 10 ; i++ ){
            grid->grid[i][j] = sauvegarde->grid_save[cent_case+dix_case+i] ;


        }
        dix_case += 10;
    }




}


