//
// Created by Peterrr on 14/05/2021.
//

#ifndef PROJET_IFB_FONCTIONS_INITIALISATION_BATAILLE_H
#define PROJET_IFB_FONCTIONS_INITIALISATION_BATAILLE_H
#define N 10

typedef struct {
    char grid[10][10];
    int largeur;
    int hauteur;
} tableau ;
typedef struct{
    int orientation;
    int length;
    int CooX;
    int CooY;
    char id;
    char id_dead;
    int pv;
} bateau ;

typedef struct{
    int nb_missile_bombe;
    int nb_missile_tactique;
    int nb_missile_default;
    int nb_missile_artillerie;
} missile;

void initialization_grille(tableau * grid);
void show_grid(tableau * grid);
void implentation_bateau(bateau * boat, tableau * grid);
int verification_emplacement_bateau(bateau * boat, tableau * grid);
void generation_bateau(bateau * boat, tableau *grid);
void generation_flotte(bateau * liste[], tableau * grid, int nb_bateaux);
void debug(bateau * boat);
void fire_artillery(int X, int Y, tableau  * boat_grid, tableau * user_grid, bateau liste[],  missile *liste_missile);
void fire_bomb(int X, int Y, tableau  * boat_grid, tableau * user_grid, bateau liste[],  missile *liste_missile);
void fire_tactical(int X, int Y, tableau  * boat_grid, tableau * user_grid, bateau liste[],  missile *liste_missile);
void fire_missile(int X, int Y, tableau *grid, tableau *user_grid, bateau  liste[],  missile *liste_missile);
int hitscan(int X, int Y, tableau *grid, tableau *user_grid, bateau  liste[]);
int is_alive();
int win(bateau liste[], int nb_bateaux);
int check_inventory(missile *liste_missile, int type_missile);
#endif //PROJET_IFB_FONCTIONS_INITIALISATION_BATAILLE_H