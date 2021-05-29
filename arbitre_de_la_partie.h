//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
#define PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
#include "structure.h"



//arbitre_de_la_parti

int win(bateau liste[], int nb_bateaux);

void modifier_nombre_missile (int difficulte, missile * liste );
int choix_missile_tire( missile * l_missile);
int aleatoir_deplacer_ou_pas( int difficulte);

#endif //PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
