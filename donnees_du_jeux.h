//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_DONNEES_DU_JEUX_H
#define PROJET_IFB_DONNEES_DU_JEUX_H
#include "structure.h"

/**
 * affiche le menue des difficultes a l'utilisateur  et lui demande en qu'elle difficulte il veux jeux
 * @return la difficulte choisie
 */
int affichage_menu_difficulte();
/**
 *
 * affiche le menue des modse a l'utilisateur  et lui demande en qu'elle mod il veux jeux
 * @return  le mode de jeux choisie
 */
int affichage_menu_mode_de_jeux();
/**
 * affiche le menue de démarrage  a l'utilisateur  et lui demande si il veux commencer une nuovelle partie ou charger la précedante partie ou quitter le programme .
 * @return 1 pour commencez une nouvelle partie / 2 pour cargé la precedante partie / 3 pour quitter le jeux
 */
int affichage_menu_demarrage();
/**
 *  affiche le menue des missiles a l'utilisateur  et le demande en qu'elle missile il veux tirer
 *
 *
 * @param l_missile
 * @return
 */
int affichage_choix_missile( Inventory l_missile);


/**
 * Transforme le choix utilisateur de char venant du stdin en int entre 1 et n
 * Donne un message d'erreur si le choix n'est pas compris entre 1 et n
 * @param nombre_de_choix
 * @return
 */
int choix_menu_multiple(int nombre_de_choix);

#endif //PROJET_IFB_DONNEES_DU_JEUX_H
