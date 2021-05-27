//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_LOAD_SAUVEGARDE_H
#define PROJET_IFB_LOAD_SAUVEGARDE_H
#include "structure.h"

/// on fais l'inverse des sauvegarde
void load_life_bateaux( bateau * liste_bateaux , save * sauvegarde, int cinq_case );
void load_mode (int  * mode_rep,save * sauvegarde);
void load_inventory (missile * liste,  save * sauvegarde);
void load_Coo (bateau  *liste, save * sauvegarde,int deux_case);
void load_caracteristique_grid (tableau * user_grid , save * sauvegarde , int cent_case);


#endif //PROJET_IFB_LOAD_SAUVEGARDE_H
