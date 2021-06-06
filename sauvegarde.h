//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_SAUVEGARDE_H
#define PROJET_IFB_SAUVEGARDE_H
#include "structure.h"

void fonction_sauvegarde( save * sauvegarde, boat liste_bateaux[], Inventory liste_missile,Grid user_grid ,Grid boat_grid, int nb_bateaux, int choix_mode_de_jeux);
void fonction_ecriture_sauvegarde(save sauvegarde);


// faonction utiliser par "fonction_sauvegarde"

void save_inventory (Inventory * liste,  save * sauvegarde );
void save_Coo (boat  liste[], save * sauvegarde,int deux_case,int nb_bateaux);
void save_caracteristique_grid (Grid * user_grid , save * sauvegarde , int cent_case);
void save_orientation(boat liste_bateaux[],save * sauvegarde,int nb_bateaux);
void save_pv(boat liste_bateaux[],save * sauvegarde,int nb_bateaux);


#endif //PROJET_IFB_SAUVEGARDE_H
