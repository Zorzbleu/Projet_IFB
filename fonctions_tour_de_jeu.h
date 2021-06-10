//
// Created by Peterrr on 10/06/2021.
//

#ifndef MAIN_C_FONCTIONS_TOUR_DE_JEU_H
#define MAIN_C_FONCTIONS_TOUR_DE_JEU_H

/** Demande en input user un char de taille 3 maximum contenant les coordonnées où le missile va être lancé (exemple : C7, b10).
 *  Ces coordonnées sont ensuites transformées puis stockées dans la structure (Missile_Coordinates.X_Coordinate/Y_Coordinate) sous la forme d'int pour être utilisé plus facilement par le programme
 * @param Missile Contient le char permettant de récupérer l'input user ainsi que les coordonnées X/Y en int
 */
void coordonnees_tir(Missile_Coordinates* Missile);

/** Simple switch entre les différents types de missiles
 *
 * @param Coordonnees_missile
 * @param missile_choisie
 * @param boat_grid
 * @param user_grid
 * @param liste_bateaux
 * @param liste_missile
 * @param mode_de_jeux
 */
void lancement_tir(Missile_Coordinates Coordonnees_missile, int missile_choisie, Grid* boat_grid, Grid* user_grid, boat* liste_bateaux[], Inventory* liste_missile);
/**
 *
 * @return
 */
int continuer_partie();
#endif //MAIN_C_FONCTIONS_TOUR_DE_JEU_H
