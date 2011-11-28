//
//  main.c
//  Dominosa
//
//  Created by Freddy Roman Cepeda on 11/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAXN 9

#define nWidth(n) (n+2)
#define nHeight(n) (n+1)

#define MAXWIDTH nWidth(MAXN)
#define MAXHEIGHT nHeight(MAXN)

#define CMAXWIDTH nWidth(n)
#define CMAXHEIGHT nHeight(n)

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int grid[MAXWIDTH][MAXHEIGHT];

#define pointInGrid(p) grid[p.x][p.y]

int n;

typedef enum {
    down = 0,
    up,
    right,
    left
} Direction;

Direction gridDirection[MAXWIDTH][MAXHEIGHT];

#define directionOfPoint(p) gridDirection[p.x][p.y]

Direction complementDir[4] = {up, down, left, right};

void printGrid(void);
void printGrid(void){
    int x,y;
    for (y = 0; y < CMAXHEIGHT; y++) {
        for (x = 0; x < CMAXWIDTH; x++) {
            switch (gridDirection[x][y]) {
                case up:
                    printf("V");
                    break;
                case down:
                    printf("^");
                    break;
                case left:
                    printf(">");
                    break;
                case right:
                    printf("<");
                    break;
            }
        }
        printf("\n");
    }
}

typedef struct {
    int x,y;
} Point;

Point makePoint(int, int);
Point makePoint(int x, int y){
    Point point = {x,y};
    return point;
}

#define MOVCOUNT 4

Point movs[MOVCOUNT] = {{0,1},{0,-1},{1,0},{-1,0}};

#define nextPoint(p,i) makePoint(p.x + movs[i].x, p.y + movs[i].y)

#define isValidPoint(p) (p.x >= 0 && p.y >= 0 && p.x < CMAXWIDTH && p.y < CMAXHEIGHT)

int inUse[MAXWIDTH][MAXHEIGHT];

#define isInUse(p) inUse[p.x][p.y]

int piecesList[MAXN + 1][MAXN + 1];

Direction cDir[MAXWIDTH][MAXHEIGHT];
int cUse[MAXWIDTH][MAXHEIGHT];
void printUsedGrid(void);
void printUsedGrid(void){
    int x,y,cmax = 0;
    static int max;
    for (y = 0; y < CMAXHEIGHT; y++) {
        for (x = 0; x < CMAXWIDTH; x++) {
            if (inUse[x][y]) {
                cmax++;
            }
        }
    }
    if (cmax > max) {
        max = cmax;
        memcpy(gridDirection, cDir, sizeof(gridDirection));
        memcpy(cUse, inUse, sizeof(inUse));
    }
}

Point getNextUndecided(Point p);
Point getNextUndecided(Point p){
    int x = p.x + 1, y = p.y;
    for (; x < CMAXWIDTH; x++) {
        if (!inUse[x][y]) {
            return makePoint(x, y);
        }
    }
    for (y++; y < CMAXHEIGHT; y++) {
        for (x = 0; x < CMAXWIDTH; x++) {
            if (!inUse[x][y]) {
                return makePoint(x, y);
            }
        }
    }
    return makePoint(-1, -1);
}

int notUsingPiece(Point a, Point b);
int notUsingPiece(Point a, Point b){
    int maxN = max(pointInGrid(a), pointInGrid(b));
    int minN = min(pointInGrid(a), pointInGrid(b));
    return !piecesList[maxN][minN];
}

void usingPiece(Point a, Point b, int isUsing);
void usingPiece(Point a, Point b, int isUsing){
    int maxN = max(pointInGrid(a), pointInGrid(b));
    int minN = min(pointInGrid(a), pointInGrid(b));
    piecesList[maxN][minN] = isUsing;
}

void bruteForce(Point here);
void bruteForce(Point here){
    if (here.x == -1 && here.y == -1) {
        printGrid();
        exit(0);
    }
    int i;
    isInUse(here) = 1;
    for (i = 0; i < MOVCOUNT; i++) {
        Point complement = nextPoint(here, i);
        Direction hereDir = i;
        Direction compDir = complementDir[i];
        if (isValidPoint(complement) && !isInUse(complement) && notUsingPiece(here, complement)) {
            directionOfPoint(here) = hereDir;
            directionOfPoint(complement) = compDir;
            usingPiece(here, complement, 1);
            isInUse(complement) = 1;
            printUsedGrid();
            bruteForce(getNextUndecided(here));
            isInUse(complement) = 0;
            usingPiece(here, complement, 0);
        }
    }
    isInUse(here) = 0;
}

int main (int argc, const char * argv[])
{
    int x,y;
    scanf("%d", &n);
    
    for (y = 0; y < CMAXHEIGHT; y++) {
        for (x = 0; x < CMAXWIDTH; x++) {
            scanf("%d", &grid[x][y]);
        }
    }
    
    bruteForce(getNextUndecided(makePoint(-1, 0)));
    
    for (y = 0; y < CMAXHEIGHT; y++) {
        for (x = 0; x < CMAXWIDTH; x++) {
            if (!cUse[x][y]) {
                printf("%d", grid[x][y]);
                continue;
            }
            switch (cDir[x][y]) {
                case up:
                    printf("V");
                    break;
                case down:
                    printf("^");
                    break;
                case left:
                    printf(">");
                    break;
                case right:
                    printf("<");
                    break;
            }
        }
        printf("\n");
    }
    
    return 1;
}

/*
 7
 6 2 2 7 5 5 6 1 7
 0 1 4 3 1 5 5 0 7
 6 0 1 6 2 7 1 4 0
 2 0 3 4 3 0 0 4 4
 0 1 5 2 4 1 1 1 5
 7 5 7 6 4 3 7 2 3
 6 5 3 5 2 2 7 0 6
 7 2 3 4 6 6 4 2 2

*/