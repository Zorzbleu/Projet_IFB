//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
#define PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
#include "structure.h"


#include "initialisation_interface.h"


//arbitre_de_la_parti

int check_win_condition(boat liste[], int nb_bateaux);
int check_lose_condition(Inventory liste_missiles);

void modifier_nombre_missile (int difficulte, Inventory * liste );
void afficher_bateau_touche_et_pv( boat liste_bateaux[],int nb_bateaux);
int choix_missile_tire( Inventory * l_missile);
int aleatoir_deplacer_ou_pas( int difficulte);




void retirer_coordonner ( boat * liste_bateaux,int axe_XY,int nb_deplacement, int sens_deplacement);
void sauvegarde_caracter_bateau (  boat * liste_bateaux[] , Grid * boat_grid,int nb_bateau,int nb_deplacement,int axe_XY,int sens_deplacement ,char * tampon);
void placer_carater_sauvegarder_bateau (  boat * liste_bateaux[] , Grid * boat_grid,char * tampon,int nb_bateau);
void effacer_ancien_bateau (boat * bateaux , Grid * boat_grid,int nb_deplacement,int axe_XY,int sens_deplacement  );
void active_mode(int choix_difficulte, boat liste_bateaux[], Grid* boat_grid);
#endif //PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
