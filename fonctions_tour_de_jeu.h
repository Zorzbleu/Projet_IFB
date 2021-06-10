//
// Created by Peterrr on 10/06/2021.
//

#ifndef MAIN_C_FONCTIONS_TOUR_DE_JEU_H
#define MAIN_C_FONCTIONS_TOUR_DE_JEU_H

void coordonnees_tir(Missile_Coordinates* Missile);
void lancement_tir(Missile_Coordinates Coordonnees_missile, int missile_choisie, Grid* boat_grid, Grid* user_grid, boat* liste_bateaux[], Inventory* liste_missile);
char continuer_partie();
#endif //MAIN_C_FONCTIONS_TOUR_DE_JEU_H
