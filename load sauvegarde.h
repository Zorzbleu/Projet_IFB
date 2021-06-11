//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_LOAD_SAUVEGARDE_H
#define PROJET_IFB_LOAD_SAUVEGARDE_H
#include "structure.h"
#include "gestion_bateau.h"
#include <stdio.h>
#include <stdlib.h>
// on fais l'inverse des sauvegarde
/**
 * regle tous le paramètre du jeux a l'aide de le strusture save (sauvegarde)
 *
 * @param sauvegarde
 * @param liste_bateaux
 * @param liste_missile
 * @param user_grid
 * @param boat_grid
 * @param nb_bateaux
 * @param choix_mode_de_jeux
 */
void fonction_load (save  sauvegarde, Inventory * liste_missile,Grid * user_grid ,Grid *  boat_grid, int * choix_mode_de_jeux);

/**
 *
 * lis le fichier "sauvegarde.jeux" qui contient le donné de l'enienne partie et  les mets dans "sauvegarde"
 * @param sauvegarde structure save qui vas contenire toute les ensiegne donné du jeux
 */
void fonction_lecture_sauvegarde(save * sauvegarde);

// fonction utilier par "fonction_load"
void load_inventory (Inventory * liste,save  sauvegarde);
void load_caracteristique_grid (Grid * user_grid ,save sauvegarde , int cent_case);

void load_orientation(boat  * liste_bateaux,save sauvegarde, int i );
void load_pv(boat  * liste_bateaux,save  sauvegarde , int i );
void load_Coo (boat  * liste_bateaux,save  sauvegarde,int deux_case);


#endif //PROJET_IFB_LOAD_SAUVEGARDE_H
