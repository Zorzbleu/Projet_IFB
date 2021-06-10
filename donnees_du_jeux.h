//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_DONNEES_DU_JEUX_H
#define PROJET_IFB_DONNEES_DU_JEUX_H
#include "structure.h"

/*Menu à trois choix présentant les différentes difficultées
 *
 */
int affichage_menu_difficulte();
int affichage_menu_mode_de_jeux();
int affichage_menu_demarrage();
int affichage_choix_missile( Inventory l_missile);

/*Transforme le choix utilisateur de char venant du stdin en int entre 1 et n
 *Donne un message d'erreur si le choix n'est pas compris entre 1 et n
 * param nombre_de_choix Nombre d'options du menu
 */
int choix_menu_multiple(int nombre_de_choix);

#endif //PROJET_IFB_DONNEES_DU_JEUX_H
