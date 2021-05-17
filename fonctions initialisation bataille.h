//
// Created by Peterrr on 14/05/2021.
//

#ifndef PROJET_IFB_FONCTIONS_INITIALISATION_BATAILLE_H
#define PROJET_IFB_FONCTIONS_INITIALISATION_BATAILLE_H
#define N 10

typedef struct{
    int orientation;
    int length;
    int CooX;
    int CooY;
} bateau ;

void initialization_grille(char grid[N][N]);
void show_grid(char grid[N][N]);
void implentation_bateau(bateau test, char grid[N][N]);
int verification_emplacement_bateau(bateau test, char grid[N][N]);
void generation_bateau(bateau SizeX, char grid[N][N]);


#endif //PROJET_IFB_FONCTIONS_INITIALISATION_BATAILLE_H
