//
// Created by Peterrr on 14/05/2021.
//

#ifndef PROJET_IFB_FONCTIONS_INITIALISATION_BATAILLE_H
#define PROJET_IFB_FONCTIONS_INITIALISATION_BATAILLE_H
#define N 10
#include "structure.h"




/////

// sauvergard_load



void generation_flotte(boat * liste[], Grid * grid, int nb_bateaux);
void debug(boat * boat);
int check_inventory(Inventory *liste_missile, int type_missile);
void clear_text(int lines);
void error_message(char variable);
void sauvegarder (Inventory *liste_missile,int choix_difficulte_rep, save *sauvegarde);
int is_alive();


#endif //PROJET_IFB_FONCTIONS_INITIALISATION_BATAILLE_H