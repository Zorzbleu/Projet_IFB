//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_DONNEES_DU_JEUX_H
#define PROJET_IFB_DONNEES_DU_JEUX_H
#include "structure.h"

/**
 * affiche le menu des difficultées à l'utilisateur  et lui demande la difficultée choisie
 * @return la difficulté choisie
 */
int affichage_menu_difficulte();
/**
 *
 * affiche le menu des modes à l'utilisateur  et lui demande le mode de jeu choisie
 * @return  le mode de jeu choisie
 */
int affichage_menu_mode_de_jeux();
/**
 * affiche le menu de démarrage  à l'utilisateur  et lui demande si il veut commencer une nouvelle partie ou charger la précédante partie ou quitter le programme .
 * @return 1 pour commencez une nouvelle partie / 2 pour charger la précédante partie / 3 pour quitter le jeu
 */
int affichage_menu_demarrage();
/**
 *  affiche le menu des missiles à l'utilisateur  et lui demande le missile choisie
 * @return 1 missile normal
 * @return 2 tactical
 * @return 3 bomb
 * @return 4 artillery
 * @param l_missile Permet l'affichage des missiles restants
 * @return
 */
int affichage_choix_missile( Inventory l_missile);


/**
 * Transforme le choix utilisateur de char venant du stdin en int entre 1 et n
 * Donne un message d'erreur si le choix n'est pas compris entre 1 et n
 * @param nombre_de_choix
 * @return Le numéro de l'option choisit par l'user (exemple : Mode de jeu 3, active)
 */
int choix_menu_multiple(int nombre_de_choix);

#endif //PROJET_IFB_DONNEES_DU_JEUX_H
