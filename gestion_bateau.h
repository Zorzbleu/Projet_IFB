//
// Created by Admin on 27/05/2021.
//

#ifndef PROJET_IFB_GESTION_BATEAU_H
#define PROJET_IFB_GESTION_BATEAU_H
#include "structure.h"

// gestion_bateau

/**Génére des nouvelles coordonnées et orientation à un bateau
 * Utilise les autres fonctions pour vérifier si l'emplacement est valide ainsi qu'implementer le bateau dans la grille.
 * @param boat Structure boat dont on
 * @param boat_grid
 */
void generation_bateau(boat * boat, Grid * boat_grid  );

/**Implémente le bateau dans la grille
 *
 * @param boat
 * @param boat_grid
 */
void implentation_bateau(boat * boat, Grid * boat_grid);

/**Vérifie si le bateau généré peut être place
 *
 * @param boat Structure boat dont on vérifie les coordonnées
 * @param boat_grid Grille dans laquelle on vérifie si les coordonnées sont valides
 * @return
 */
int verification_emplacement_bateau(boat * boat, Grid * boat_grid);



#endif //PROJET_IFB_GESTION_BATEAU_H
