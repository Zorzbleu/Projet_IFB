//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_STRUCTURE_H
#define PROJET_IFB_STRUCTURE_H
#define N 10
  // .h qi stock toutes les structures
typedef struct{
    int orientation;
    int length;
    int CooX;
    int CooY;
    char id;
    char id_dead;
    int pv;
    int pv_detaille[5];
} boat ;

typedef struct {
    int largeur;
    int hauteur;
    char grid[N][N];
} Grid ;
/**
typedef struct {
    int largeur;
    int hauteur;
    char grid[];
} grid ;
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

typedef  struct{
    char Given_Coordinates[3];
    int X_Coordinates;
    int Y_Coordinates;
} Missile_Coordinates;


#endif //PROJET_IFB_STRUCTURE_H
