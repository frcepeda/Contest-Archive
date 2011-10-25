#include <stdio.h>

#define MAXSIZE 400

#define TEST 0

#define updateMax(a) if((a) > max) max = (a);

int aDiagonal[MAXSIZE][MAXSIZE];
int bDiagonal[MAXSIZE][MAXSIZE];

int max;
int size;
int matrix[MAXSIZE][MAXSIZE];

int main(void){
    scanf("%d", &size);
    int x, y;

    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            scanf("%d", &matrix[x][y]);
        }
    }

    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            if(x > 0 && y){
                aDiagonal[x][y] = aDiagonal[x-1][y-1] + matrix[x][y];
            } else {
                aDiagonal[x][y] = matrix[x][y];
            }
        }
    }

    for(y = 0; y < size; y++){
        for(x = size - 1; x >= 0; x--){
            if(x < size - 1 && y){
                bDiagonal[x][y] = bDiagonal[x+1][y-1] + matrix[x][y];
            } else {
                bDiagonal[x][y] = matrix[x][y];
            }
        }
    }

    #if TEST

    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    }

    printf("\n");

    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            printf("%d ", aDiagonal[x][y]);
        }
        printf("\n");
    }

        printf("\n");

    for(y = 0; y < size; y++){
        for(x = 0; x < size; x++){
            printf("%d ", bDiagonal[x][y]);
        }
        printf("\n");
    }

    #endif

    for(y = 0; y < size - 1; y++){
        for(x = 0; x < size - 1; x++){
            int square;
            for(square = 2; square + x - 1 < size && square + y - 1 < size; square++){
                int xend = square + x - 1, yend = square + y - 1;
                int beauty, diag, odiag;

                diag = aDiagonal[xend][yend];
                if(x && y){
                    diag -= aDiagonal[x-1][y-1];
                }

                xend = x;
                odiag = bDiagonal[xend][yend];
                if(x < size - 1 && y){
                    diag -= bDiagonal[x+square][y-1];
                }

                beauty = diag - odiag;
                updateMax(beauty);
            }
        }
    }

    printf("%d\n", max);
    return 0;
}
