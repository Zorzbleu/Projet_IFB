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

/**
 *
 * renseigne le joueur sur les bateaux coulées et les points de vie restant de chaque bateaux
 * @param liste_bateaux : caractérstique de tout les bateaux
 * @param nb_bateaux : nombre de bateaux dans la partie
 */
void afficher_bateau_couler_et_pv( boat liste_bateaux[],int nb_bateaux);

/**
 * choisie si on deplace ou pas un bateau en mode active, la probabilité que l'évènement a lieu depand de mode de difficulté ( 20% pour facile / 40% pour moyen et 60% pour difficile)
 * @param difficulte
 * @return : 1 si on deplace un bateau sinon 0
 */
int aleatoir_deplacer_ou_pas( int difficulte);

/**
 *
 * prend un bateau et le deplace sur la grilldes baeaux
 * @param choix_difficulte : difficulté du mode de jeux choisi
 * @param liste_bateaux : caractérstique de tout les bateaux
 * @param boat_grid : grill des bateaux
 */
void active_mode(int choix_difficulte, boat liste_bateaux[], Grid* boat_grid);

// fonction utilisé par "active_mode"

/**
 * modifie les coordonnées du bateau deplacé
 * @param bateaux : caracteristique du bateau a deplacé
 * @param axe_XY : l'axe sur le qu'elle ele bateau doit être deplacé
 * @param nb_deplacement : le nombre de case que le bateau ce déplace
 * @param sens_deplacement : se deplace dans ke sens croissant ou decroissant de l'axe
 */
void modifier_coordonne ( boat * bateaux,int axe_XY,int nb_deplacement, int sens_deplacement);

/**
 *
 * remer les coordonné du bateau d'origie si celui si n'a pas pue être déplacé
 * @param liste_bateaux
 * @param axe_XY
 * @param nb_deplacement
 * @param sens_deplacement
 */
void retirer_coordonner ( boat * liste_bateaux,int axe_XY,int nb_deplacement, int sens_deplacement);
/**
 * efface "l'encien bateau" qui a été deplacé
 *
 * @param bateaux
 * @param boat_grid
 * @param nb_deplacement
 * @param axe_XY
 * @param sens_deplacement
 */
void effacer_ancien_bateau (boat * bateaux , Grid * boat_grid,int nb_deplacement,int axe_XY,int sens_deplacement  );
/**
 * sauvegarde le bateaux dans un tableau de caratère
 * place le bateau sur la grill des bateaux
 *
 * @param bateaux
 * @param boat_grid
 * @param nb_bateau
 * @param nb_deplacement
 * @param axe_XY
 * @param sens_deplacement
 */



void sauvegarder_et_placer_caracter_bateau (  boat * bateaux , Grid * boat_grid,int nb_bateau,int nb_deplacement,int axe_XY,int sens_deplacement);



#endif //PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
