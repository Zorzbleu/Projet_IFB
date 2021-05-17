cmake_minimum_required(VERSION 3.17)
project(Projet_IFB C)

set(CMAKE_C_STANDARD 11)


add_executable(Projet_IFB main.c mtwister.c mtwister.h "fonctions initialisation bataille.c" "fonctions initialisation bataille.h" "tirs missiles.c" "tirs missiles.h")