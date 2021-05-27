//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_SAUVEGARDE_H
#define PROJET_IFB_SAUVEGARDE_H
#include "structure.h"

void save_life_bateaux (bateau * liste_boat, save * sauvegarde,int cinq_case,int a);
void save_mode (int rep_mode, save * sauvegarde);
void save_inventory (missile * liste,  save * sauvegarde );
void save_Coo (bateau  *liste, save * sauvegarde,int deux_case);
void save_caracteristique_grid (tableau * user_grid , save * sauvegarde , int cent_case);
void inisialisation_pv_save (save * sauvgarde);

#endif //PROJET_IFB_SAUVEGARDE_H
