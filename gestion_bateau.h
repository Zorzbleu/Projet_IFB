//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_GESTION_BATEAU_H
#define PROJET_IFB_GESTION_BATEAU_H
#include "structure.h"

// gestion_bateau


void generation_bateau(boat * bateaux, Grid * boat_grid  );
void implentation_bateau(boat * bateaux, Grid * boat_grid);
int verification_emplacement_bateau(boat * bateaux, Grid * boat_grid);

void generer_caracteristique_bateaux (boat * l_bateaux,int i );



void initialisation_pv_detaille (boat * baot);
void sauvegarde_pv_detaille (boat * baot,Grid  * user);
void effacer_bateau (Grid *boat_grid, boat bateau, int numero_bateau);



#endif //PROJET_IFB_GESTION_BATEAU_H
