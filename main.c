#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 10

struct bateau
{
    int orientation;
    int length;
    int CooX;
    int CooY;
};

void initialization_grille(char grid[N][N]);
void show_grid(char grid[N][N]);
void implentation_bateau(struct bateau test, char grid[N][N]);
void check_implentation(struct bateau test, char grid[N][N]);
void boats_generation(char grid [N][N], struct bateau size2, struct bateau size3a,struct bateau size3b,struct bateau size4,struct bateau size5);
int check(struct bateau test, char grid[N][N]);
void boat_coo(struct bateau SizeX, char grid[N][N]);
void debug_Coo(struct bateau SizeX);

int main() {
    int i;
    struct bateau test = {0, 5, 0, 0};
    struct bateau Size2 = {0,2,0,0};
    struct bateau Size3a = {0,3,0,0};
    struct bateau Size3b = {0,3,0,0};
    struct bateau Size4 = {0,4,0,0};
    struct bateau Size5 = {0,5,0,0};
    char grid[N][N];
    initialization_grille(grid);
    boats_generation(grid, Size2, Size3a, Size3b,  Size4, Size5);

    show_grid(grid);




    return (0);
}
int check(struct bateau test, char grid[N][N]) {
    //check size
    if(test.orientation == 0) {
        if(test.CooX + test.length > N)
        {
            return(1);
        } else {
            for (test.CooX; test.CooX < test.length; test.CooX++) {
                if (grid[test.CooX][test.CooY] != '_') {
                    return(2);
                }
            } return(3);
        }
    } else {if(test.orientation == 1) {
        if(test.CooY + test.length > N) {
            return(1);
        } else {
            for (test.CooY; test.CooY < test.length; test.CooY++ ) {
                if (grid[test.CooX][test.CooY] != '_') {
                    return(2);
                } return(3);
            }
        }
    }
        return(4);
    }
}


    void implentation_bateau(struct bateau test, char grid[N][N]) {
        int i;
        if(test.orientation == 0) { //implentation verticale (axe des x)
            for (i=0; i < test.length ; i++) {
                grid[test.CooX+i][test.CooY] = test.length;
            }
        } else {
            for (i=0; i < test.length; i++) { //implentation horizontale (axe des y)
                grid[test.CooX][test.CooY+i] = test.length;
            }
        }
}

    void show_grid(char grid[N][N]) {
    int x, y;

    for (x = 0; x < N; x++) {
        for (y = 0; y < N; y++) {
            printf("%c  ", grid[x][y]);
        }
        printf("\n");
    }

}

    void initialization_grille(char grid[N][N]) {
        int x, y;
        for (x = 0; x < N; x++) {
            for (y = 0; y < N; y++) {
                grid[x][y] = '_';

            }
        }
    }

void check_implentation(struct bateau test, char grid[N][N]) {
    if (check(test, grid) == 3) {
        implentation_bateau(test, grid);
    }
}
    void boat_coo(struct bateau SizeX, char grid[N][N]) {
        srand(time(NULL));

        while(check(SizeX, grid) != 3 ) {
            SizeX.orientation = rand() % 2;
            SizeX.CooX = rand() % N ;
            SizeX.CooY = rand() % N ;
        }
        implentation_bateau(SizeX, grid);
}
    void boats_generation(char grid[N][N], struct bateau size2, struct bateau size3a, struct bateau size3b,
                          struct bateau size4, struct bateau size5) {
        //boat_coo(size2, grid);
        boat_coo(size2, grid);
        boat_coo(size3a, grid);
        boat_coo(size3b, grid);
        boat_coo(size4, grid);
        boat_coo(size5, grid);
    }

void debug_Coo(struct bateau SizeX){
    printf("%i, %i, %i, %i\n", SizeX.orientation, SizeX.length, SizeX.CooX, SizeX.CooY);
}