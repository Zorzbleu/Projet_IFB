//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
#define PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
#include "structure.h"



//arbitre_de_la_parti

int win(boat liste[], int nb_bateaux);

void modifier_nombre_missile (int difficulte, Inventory * liste );
void afficher_bateau_touche_et_pv( boat liste_bateaux[],int nb_bateaux);
int choix_missile_tire( Inventory * l_missile);
int aleatoir_deplacer_ou_pas( int difficulte);

void mode_active_deplacer_bateaux ( boat * liste_bateaux , Grid * boat_grid);

#endif //PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
