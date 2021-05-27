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
    char pv_detaille[5];
} bateau ;

typedef struct {
    int largeur;
    int hauteur;
    char grid[N][N];
} tableau ;

typedef struct {
    int largeur;
    int hauteur;
    char grid[];
} grid ;



typedef struct{
    int nb_missile_bombe;
    int nb_missile_tactique;
    int nb_missile_default;
    int nb_missile_artillerie;
} missile;

typedef struct{
    int mode_rep_save;
    char boat_live_save [25] ;
    char inventory_save[3];
    char grid_save[200];
    char Coo_save [10];
} save ;




#endif //PROJET_IFB_STRUCTURE_H
