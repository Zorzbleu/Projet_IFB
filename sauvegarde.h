//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_SAUVEGARDE_H
#define PROJET_IFB_SAUVEGARDE_H
#include "structure.h"
/**
 *
 * prend toute les donné du jeux relative a la partie pour les stocker dans un structure
 *
 * @param sauvegarde : strucutre "save"  qui vas stocker toute les donné du jeux utile a la partie.
 * @param liste_bateaux : structure "boat" qui contien les caractéristique de chaque bateau. (les coordonne en X et Y, les point de vie, les longeur, leurs orientations, et leurs ids)
 * @param liste_missile : structure (Inventoryé qui contient le nombre de chaque issile restant
 * @param user_grid : structure "Grid"  qui contient le tableau aficher a l'utilisateur
 * @param boat_grid : structure "Grid"  qui contient le tableau ou les bateaux on été implémenté
 * @param nb_bateaux : nombre de bateaux sur la grille
 * @param choix_mode_de_jeux : mode de jeux choisie par l'utilisataeur
 */
void fonction_sauvegarde( save * sauvegarde, boat liste_bateaux[], Inventory liste_missile,Grid user_grid ,Grid boat_grid, int nb_bateaux, int choix_mode_de_jeux);
/**
 * pred les donné de sauvegarde pour les ecrire dans un fichier texte. (sauvegarde.jeux)
 *
 * @param sauvegarde : strucutre "save"  qui contient toute les donnés du jeux utile a la partie.
 */
void fonction_ecriture_sauvegarde(save sauvegarde);


// fonction utiliser par "fonction_sauvegarde"
void save_inventory (Inventory * liste,  save * sauvegarde );
void save_Coo (boat  liste[], save * sauvegarde,int deux_case,int nb_bateaux);
void save_caracteristique_grid (Grid * user_grid , save * sauvegarde , int cent_case);
void save_orientation(boat liste_bateaux[],save * sauvegarde,int nb_bateaux);
void save_pv(boat liste_bateaux[],save * sauvegarde,int nb_bateaux);


#endif //PROJET_IFB_SAUVEGARDE_H
