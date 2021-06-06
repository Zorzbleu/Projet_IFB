//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_GESTION_BATEAU_H
#define PROJET_IFB_GESTION_BATEAU_H
#include "structure.h"

// gestion_bateau


void generation_bateau(boat * boat, Grid * grid  );
void implentation_bateau(boat * boat, Grid * grid);
int verification_emplacement_bateau(boat * boat, Grid * grid);

void generer_caracteristique_bateaux (boat * l_bateaux,int i );



void initialisation_pv_detaille (boat * baot);
void sauvegarde_pv_detaille (boat * baot,Grid  * user);




#endif //PROJET_IFB_GESTION_BATEAU_H
