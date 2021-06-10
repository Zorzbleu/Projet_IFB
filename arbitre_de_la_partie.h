//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
#define PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
#include "structure.h"


#include "initialisation_interface.h"


//arbitre_de_la_parti

/**
 * Vérifie si tous les bateaux sont détruits ou non. Pour cela, on vérifie si les PV de chaque bateau sont égaux à 0 (ou non).
 * @param liste La liste contient l'ensemble des structures bateaux et donc leurs PV
 * @param nb_bateaux Permet de parcourir l'ensemble des bateaux présent dans la liste (dans le cas d'une implémentation dynamique non existante)
 * @return Le nombre de bateau vivant
 */
int check_win_condition(boat liste[], int nb_bateaux);

/**Vérifie si il reste des missiles à l'utilisateur
 * Il ne reste plus aucun de chaque type de missile, l'user à perdu.
 * @param liste_missiles Contient le nombre de chaque missile.
 * @return 0 si le joueur à perdu, 1 si il lui reste encore des missiles
 */
int check_lose_condition(Inventory liste_missiles);




/**Change le nombre de missile que l'user possède en fonction de la difficulté choisie
 * 10 de chaque pour facile, 10 normaux, 5 bombes, 5 tactiques et 3 artilleries en mode normal, 15 normaux, 2 bombes, 4 tactiques et 1 artillerie en mode difficile.
 * @param difficulte Difficulté choisie par l'utilisateur
 * @param liste Liste des missile (inventory) dont le nombre de missile est changé
 */
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
int aleatoire_deplacer_ou_pas( int difficulte);

/**
 *
 * prend un bateau et le deplace sur la grilldes baeaux
 * @param choix_difficulte : difficulté du mode de jeux choisi
 * @param liste_bateaux : caractérstique de tout les bateaux
 * @param boat_grid : grill des bateaux
 */
void active_mode(int choix_difficulte, boat liste_bateaux[], Grid* boat_grid);

//Ci-dessous: fonctions utilisées par "active_mode"

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
 * remet les coordonnée du bateau d'origine si celui-ci n'a pas put être déplacé
 * @param liste_bateaux
 * @param axe_XY
 * @param nb_deplacement
 * @param sens_deplacement
 */
void retirer_coordonner ( boat * liste_bateaux,int axe_XY,int nb_deplacement, int sens_deplacement);
/**
 * efface "l'ancien bateau" qui a été deplacé
 *
 * @param bateaux
 * @param boat_grid
 * @param nb_deplacement
 * @param axe_XY
 * @param sens_deplacement
 */
void effacer_ancien_bateau (boat * bateaux , Grid * boat_grid,int nb_deplacement,int axe_XY,int sens_deplacement  );
/**
 * sauvegarde le bateaux dans un tableau de caractère
 * place le bateau sur la grille des bateaux
 *
 * @param bateaux
 * @param boat_grid
 * @param nb_bateau
 * @param nb_deplacement
 * @param axe_XY
 * @param sens_deplacement
 */



void sauvegarder_et_placer_caracter_bateau (  boat * bateaux , Grid * boat_grid,int nb_deplacement,int axe_XY,int sens_deplacement);



#endif //PROJET_IFB_ARBITRE_DE_LA_PARTIE_H
