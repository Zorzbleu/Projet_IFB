#include <stdio.h>
#include "fonctions initialisation bataille.h"
#define N 10




int main() {
    bateau Size2 = {0,2,0,0};
    bateau Size31 = {0,3,0,0};
    bateau Size4 = {0,4,0,0};
    bateau Size32 = {0,3,0,0};
    bateau Size5 = {0,5,0,0};
    char grid[N][N];

    initialization_grille(grid);

    //boats_generation(grid, Size2, Size3a, Size3b,  Size4, Size5);
    printf("Boat2\n");
    generation_bateau(Size2, grid);
    printf("Boat3\n");
    generation_bateau(Size31, grid);
    printf("Boat3b\n");
    generation_bateau(Size32, grid);
    printf("Boat4\n");
    generation_bateau(Size4, grid);
    printf("Boat5\n");
    generation_bateau(Size5, grid);


    show_grid(grid);


    return (0);
}
