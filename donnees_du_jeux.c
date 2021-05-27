//
// Created by Admin on 27/05/2021.
//
#include <stdio.h>
#include "donnees_du_jeux.h"
int choix_demarrage (){
    int rep_D_C_Q ;
    printf ("1- Demarrer une nouvelle partie\n 2- Charger une partie existante\n 3- Quitter");
    scanf(" %d" , &rep_D_C_Q);
    switch ( rep_D_C_Q){
        case  1 :
            return 1;
            break;
        case 2 :
            break;
        case 3 :
            return -1;



    }



}