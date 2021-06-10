//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_TYPE_MISSILE_H
#define PROJET_IFB_TYPE_MISSILE_H
#include "structure.h"


/**On lance des hitscans sur la colonne X et la ligne Y. On ne touche qu'une fois le centre (coordonnées X Y où le missile a été lancé) pour éviter des messages d'erreurs.
 *
 * @param X Coordonnées X où le missile est lancé
 * @param Y Coordonnées Y où le missile est lancé
 * @param boat_grid Grille contrôlant si un bateau est touché
 * @param user_grid Grille affichant à l'utilisateur si un bateau est touché (O) ou non (X)
 * @param liste Liste des bateaux permettant de changer leur nombre de PV
 * @param liste_missile Quand on tire un missile, on enlève un missile à l'Inventory
 * @param mode_de_jeux Permet l'affichage de coordonnées en mode blind
 */
void fire_artillery(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile,int mode_de_jeux);

/**On lance des hitscans sur les endroits touchés par la bombe, en veillant à ne pas dépasser les côtés de la grille. (voir sujet pour le pattern de la bombe)
 *
 * @param X Coordonnées X où le missile est lancé
 * @param Y Coordonnées Y où le missile est lancé
 * @param boat_grid Grille contrôlant si un bateau est touché
 * @param user_grid Grille affichant à l'utilisateur si un bateau est touché (O) ou non (X)
 * @param liste Liste des bateaux permettant de changer leur nombre de PV
 * @param liste_missile Quand on tire un missile, on enlève un missile à l'Inventory
 * @param mode_de_jeux Permet l'affichage de coordonnées en mode blind
 */
void fire_bomb(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile ,int mode_de_jeux);

/**Si un bateau est touché, on parcourt tout le bateau pour effectuer des hitscan sur les cases non touchés préalablement. Détruit donc le bateau.
 *
 * @param X Coordonnées X où le missile est lancé
 * @param Y Coordonnées Y où le missile est lancé
 * @param boat_grid Grille contrôlant si un bateau est touché
 * @param user_grid Grille affichant à l'utilisateur si un bateau est touché (O) ou non (X)
 * @param liste Liste des bateaux permettant de changer leur nombre de PV
 * @param liste_missile Quand on tire un missile, on enlève un missile à l'Inventory
 * @param mode_de_jeux Permet l'affichage de coordonnées en mode blind
 */
void fire_tactical(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile,int mode_de_jeux);

/**Si l'user possède encore des missiles normaux, on lance un hitscan sur les coordonnées X,Y.
 * Si l'user touche une case vide qui n'a pas déjà été touché auparavant, on lui indique que la case est vide à l'aide d'un printf.
 *
 * @param X Coordonnées X où le missile est lancé
 * @param Y Coordonnées Y où le missile est lancé
 * @param boat_grid Grille contrôlant si un bateau est touché
 * @param user_grid Grille affichant à l'utilisateur si un bateau est touché (O) ou non (X)
 * @param liste Liste des bateaux permettant de changer leur nombre de PV
 * @param liste_missile Quand on tire un missile, on enlève un missile à l'Inventory
 * @param mode_de_jeux Permet l'affichage de coordonnées en mode blind
 */
void fire_missile(int X, int Y, Grid *grid, Grid *user_grid, boat  liste[],  Inventory *liste_missile,int mode_de_jeux); // missile de base

/** Si aux coordonnées X Y la grille boat est vide ('_'), on place un 'X' sur la grille user et boat pour signifier que l'user à déjà touché cet endroit
 *  Si aux coordonnées X Y la grille boat contient déjà un 'X', on indique à l'utilisateur qu'il a déjà touché cet endroit.
 *  Sinon, on regarde le grille boat contient l'id d'un bateau (a,b,c,d,e). On parcourt la liste des id. Si ça matche, on enlève un PV au bateau touché, on affiche un 'O' sur la grille user, on change l'id en id_dead (A,B,C,D,E) sur la grille user et on envoie un message si le bateau est coulé.
 *  On parcourt aussi la liste des id_dead, et si la grille contient celle-ci, on indique à l'user que le bateau à déjà été touché à cet endroit là et on affiche un 'O' sur la grille user (pour le mode active)
 * @param X Coordonnées X où le missile est lancé
 * @param Y Coordonnées Y où le missile est lancé
 * @param boat_grid Grille contrôlant si un bateau est touché
 * @param user_grid Grille affichant à l'utilisateur si un bateau est touché (O) ou non (X)
 * @param liste Liste des bateaux permettant de changer leur nombre de PV
 * @param mode_de_jeux mode_de_jeux Permet l'affichage de coordonnées en mode blind
 * @return -1 si le tir touche une case vide, -2 si la case avait déjà été touché, -3 si la case n'est pas vide mais contient qqchose d'inconnu (normalement non-possible), sinon return le numéro du bateau touché dans la liste (Exemple, le bateau A de taille 2 à pour numéro 0)
 */
int hitscan(int X, int Y, Grid *boat_grid, Grid *user_grid, boat  liste[],int mode_de_jeux);


#endif //PROJET_IFB_TYPE_MISSILE_H
