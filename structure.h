//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_STRUCTURE_H
#define PROJET_IFB_STRUCTURE_H
#define N 10


/**La structure bateau contient toutes les données permettant l'affichage et la gestion de celui-ci.
 * orientation : 0 = axe des X, 1 = axe des Y
 * length : longueur du bateau
 * CooX, coordonnée X de l'origine du bateau (le plus à gauche/X le plus bas dans ce cas)
 * CooY, coordonneé Y de l'origine du bateau (le plus haut/Y le plus bas dans ce cas)
 * id, identificateur d'une case appartenant au bateau utilisé dans le grille de contrôle (a,b,c,d,e)
 * id_dead, identificateur d'une case appartenant au bateau utilisé dans la grille de contrôle ayant déjà été touché (A,B,C,D,E)
 * pv, nombre de point de vie du bateau, équivalent à longueur du bateau - nb de cases touchées
 */
typedef struct{
    int orientation;
    int length;
    int CooX;
    int CooY;
    char id;
    char id_dead;
    int pv;
} boat ;

/**Contient les données utilisées pour la gestion des grilles
 * largeur Largeur de la grille (10 par défaut)
 * hauteur Hauteur de la grille (10 par défaut)
 * grid[N][N], array de 2 dimensions de taille 10*10.
 */
typedef struct {
    int largeur;
    int hauteur;
    char grid[N][N];
} Grid ;

/**Structure contenant les nombres de missiles restant à l'utilisateur
 * On prend donc une variable pour chaque type de missile
 */
typedef struct{
    int nb_missile_bombe;
    int nb_missile_tactique;
    int nb_missile_default;
    int nb_missile_artillerie;
} Inventory;

typedef struct{
    int mode_rep_save;
   // int boat_live_save [25] ;
    int  inventory_save[4];
    char grid_save[200];
    int  Coo_save [10];
    int pv_save [5];
    int orientation_save[5];
} save ;

/**
 * Contient le char permettant à l'user d'indiquer les coordonnées où il va tirer
 * Contient les coordonées X et Y en int transformées par la fonction coordonnees_tir (fonction_tour_de_jeu.h)
 * Ainsi A1 devient (0,0), C10 (2,9) etc...
 */
typedef  struct{
    char Given_Coordinates[3];
    int X_Coordinates;
    int Y_Coordinates;
} Missile_Coordinates;


#endif //PROJET_IFB_STRUCTURE_H
