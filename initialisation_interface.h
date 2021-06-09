//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_INITIALISATION_INTERFACE_H
#define PROJET_IFB_INITIALISATION_INTERFACE_H
#include "structure.h"

// initialisation_interface

/*Initialise les valeurs de l'array de la structure grid avec le caractère par défaut '_'.
 * @param grid Structure grid contenant l'array modifié, ainsi que les valeurs de sa hauteur et largeur utilisées dans la fonction.
 */
void initialization_grille(Grid * grid);

/*Affiche une grille à l'écran ainsi que les axes X (A,B,C...) et Y (1,2,3...) de la bataille navale.
 *
 */
void show_grid(Grid * grid);


/*Donne les valeurs de la largeur et de la hauteur d'une structure grid
 *@param grid structure grille dont les valeurs hauteur et largeur sont modifiées
 *@param hauteur Hauteur de la grille voulue
 *@param largeur Largeur de la grille voulue
 */
void dimension_tableau(Grid *  grid, int hauteur, int largeur);

/*Initialise la liste de bateaux par défaut : 1 taille 5, 1 taille 4, 2 taille 3 et 1 taille 2.
 * @param boat liste_bateaux][ Change les valeurs des 5 structures boat de cette liste
 */
void initialization_boats_characteristics(boat *liste_bateau, int nb_bateaux);


void initialization_default(Grid *boat_grid, Grid *user_grid, boat *liste_bateaux, int nb_bateaux);

#endif //PROJET_IFB_INITIALISATION_INTERFACE_H
