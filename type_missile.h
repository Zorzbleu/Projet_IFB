//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_TYPE_MISSILE_H
#define PROJET_IFB_TYPE_MISSILE_H
#include "structure.h"

//type_missile
void fire_artillery(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile);
void fire_bomb(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile );
void fire_tactical(int X, int Y, Grid  * boat_grid, Grid * user_grid, boat liste[],  Inventory *liste_missile);
void fire_missile(int X, int Y, Grid *grid, Grid *user_grid, boat  liste[],  Inventory *liste_missile);


#endif //PROJET_IFB_TYPE_MISSILE_H
