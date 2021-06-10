cmake_minimum_required(VERSION 3.17)
project(Projet_IFB C)

set(CMAKE_C_STANDARD 11)


add_executable(Projet_IFB main.c "arbitre_de_la_partie.c" "arbitre_de_la_partie.h" "gestion_bateau.c" "gestion_bateau.h"  "initialisation_interface.c" "initialisation_interface.h"  "structure.h" "type_missile.c" "type_missile.h" donnees_du_jeux.c donnees_du_jeux.h sauvegarde.c sauvegarde.h "load sauvegarde.c" "load sauvegarde.h" fonctions_tour_de_jeu.c fonctions_tour_de_jeu.h)

