

#include "fonctions initialisation bataille.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tire.h"




void debug_coo(boat * boat){

}



void clear_text(int lines) {
    if (lines == 0) {
        for (int i = 0; i < 50 ; ++i) {
            printf("\n");
        }
    } else {
        for (int i = 0; i < lines; ++i) {
            printf("\n");
        }
    }
}

void error_message(char variable) {
    printf("Erreur : variable '%c' non valable", variable);
}

/////////////








