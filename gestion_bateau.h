//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_GESTION_BATEAU_H
#define PROJET_IFB_GESTION_BATEAU_H
#include "structure.h"

// gestion_bateau


void generation_bateau(bateau * boat, tableau * grid  );
void implentation_bateau(bateau * boat, tableau * grid);
int verification_emplacement_bateau(bateau * boat, tableau * grid);

void generer_caracteristique_bateaux (bateau * l_bateaux,int i );



void initialisation_pv_detaille (bateau * baot);
void sauvegarde_pv_detaille (bateau * baot,tableau  * user);




#endif //PROJET_IFB_GESTION_BATEAU_H
