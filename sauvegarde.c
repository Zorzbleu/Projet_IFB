//
// Created by Admin on 27/05/2021.
//

#include "sauvegarde.h"
#include "stdio.h"
void save_inventory (missile * liste,  save * sauvegarde ){



    sauvegarde->inventory_save[0] = liste->nb_missile_artillerie;
    sauvegarde->inventory_save[1] = liste->nb_missile_bombe;
    sauvegarde->inventory_save[2] = liste->nb_missile_default;
    sauvegarde->inventory_save[3] = liste->nb_missile_tactique;
}

    void save_mode (int rep_mode, save * sauvegarde){

    sauvegarde->mode_rep_save = rep_mode;

}


    void save_life_bateaux (bateau * liste_boat, save * sauvegarde,int cinq_case){ /// la vie des bateaux est sauvegarder dans 5 case (matrice)
          int i =0;
          for (i=0 ; i< 5 ; i++){


         sauvegarde->boat_live_save[cinq_case+i]= liste_boat->pv_detaille[i];
    }


}

void save_Coo (bateau  * liste, save * sauvegarde,int deux_case){

    int i = 0;
    for ( i=0 ; i< 2 ; i++ ){
    sauvegarde->Coo_save[deux_case + i] = liste->CooX;
    sauvegarde->Coo_save[deux_case + i +1] = liste->CooY;

    }

}



void save_caracteristique_grid (tableau * grid , save * sauvegarde , int cent_case){

    int i = 0,j=0;
    int dix_case=0;

    for (j=0 ; j<10 ; j++ ){
        for ( i= 0 ; i< 10 ; i++ ){
            sauvegarde->grid_save[cent_case+dix_case+i] = grid->grid[1+i][1+j];


        }
    dix_case += 10;
    }




}
