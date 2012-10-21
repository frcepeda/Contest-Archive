//
//  main.c
//  Hexoku
//
//  Created by Freddy Roman Cepeda on 11/19/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRIDWIDTH 11
#define GRIDHEIGHT 6
#define HEXAGONSINGRID 19
#define TRIANGLESINHEX 6
#define HEXPERTRIANGLE 3
#define POSSIBLEVALS 6

int grid[GRIDWIDTH][GRIDHEIGHT];

typedef struct {
    int x,y;
} Point;

Point makePoint(int x, int y);
Point makePoint(int x, int y){
    Point point = {x,y};
    return point;
}

#define pointInGrid(p) grid[p.x][p.y]

typedef struct {
    int from, to;
} Range;

Range hexRangeX[GRIDHEIGHT] = {
    {2,8}, {1,9}, {0,10}, {0,10}, {1,9}, {2,8}
};

Point hexagons[HEXAGONSINGRID][TRIANGLESINHEX] = {
    {{2,0},{3,0},{4,0},{2,1},{3,1},{4,1}},
    {{4,0},{5,0},{6,0},{4,1},{5,1},{6,1}},
    {{6,0},{7,0},{8,0},{6,1},{7,1},{8,1}},
    {{1,1},{2,1},{3,1},{1,2},{2,2},{3,2}},
    {{3,1},{4,1},{5,1},{3,2},{4,2},{5,2}},
    {{5,1},{6,1},{7,1},{5,2},{6,2},{7,2}},
    {{7,1},{8,1},{9,1},{7,2},{8,2},{9,2}},
    {{0,2},{1,2},{2,2},{0,3},{1,3},{2,3}},
    {{2,2},{3,2},{4,2},{2,3},{3,3},{4,3}},
    {{4,2},{5,2},{6,2},{4,3},{5,3},{6,3}},
    {{6,2},{7,2},{8,2},{6,3},{7,3},{8,3}},
    {{8,2},{9,2},{10,2},{8,3},{9,3},{10,3}},
    {{1,3},{2,3},{3,3},{1,4},{2,4},{3,4}},
    {{3,3},{4,3},{5,3},{3,4},{4,4},{5,4}},
    {{5,3},{6,3},{7,3},{5,4},{6,4},{7,4}},
    {{7,3},{8,3},{9,3},{7,4},{8,4},{9,4}},
    {{2,4},{3,4},{4,4},{2,5},{3,5},{4,5}},
    {{4,4},{5,4},{6,4},{4,5},{5,5},{6,5}},
    {{6,4},{7,4},{8,4},{6,5},{7,5},{8,5}},
};

#define hexOfPoint(p, i) hexeslistofpoint[p.x][p.y][i]

int hexeslistofpoint[GRIDWIDTH][GRIDHEIGHT][HEXPERTRIANGLE] = {
    {{-1},{-1},{7,-1},{7,-1},{-1},{-1}},
    {{-1},{3,-1},{3,7,-1},{7,12,-1},{12,-1},{-1}},
    {{0,-1},{0,3,-1},{3,7,8},{7,8,12},{12,16,-1},{16,-1}},
    {{0,-1},{0,3,4},{3,4,8},{8,12,13},{12,13,16},{16,-1}},
    {{0,1,-1},{0,1,4},{4,8,9},{8,9,13},{13,16,17},{16,17,-1}},
    {{1,-1},{1,4,5},{4,5,9},{9,13,14},{13,14,17},{17,-1}},
    {{1,2,-1},{1,2,5},{5,9,10},{9,10,14},{14,17,18},{17,18,-1}},
    {{2,-1},{2,5,6},{5,6,10},{10,14,15},{14,15,18},{18,-1}},
    {{2,-1},{2,6,-1},{6,10,11},{10,11,15},{15,18,-1},{18,-1}},
    {{-1},{6,-1},{6,11,-1},{11,15,-1},{15,-1},{-1}},
    {{-1},{-1},{11,-1},{11,-1},{-1},{-1}}
};

void printGrid(void);
void printGrid(void){
    int x,y;
    for (y = 0; y < GRIDHEIGHT; y++) {
        for (x = hexRangeX[y].from; x < hexRangeX[y].to; x++) {
            printf("%d ", grid[x][y]);
        }
        printf("%d\n", grid[x][y]);
    }
}

short gridPossibleCount[GRIDWIDTH][GRIDHEIGHT];
short gridPossible[GRIDWIDTH][GRIDHEIGHT][POSSIBLEVALS + 1];

#define pointPossibleCount(p) gridPossibleCount[p.x][p.y]
#define possibleInPoint(p, num) gridPossible[p.x][p.y][num]

void removePossibilities(Point here);
void setValue(Point here);

void setValue(Point here){
    pointPossibleCount(here) = 0;
    int c;
    for (c = 1; c <= POSSIBLEVALS; c++) {
        if (possibleInPoint(here, c)) {
            break;
        }
    }
    pointInGrid(here) = c;
    removePossibilities(here);
}

void removePossibilities(Point here){
    int hex, value = pointInGrid(here);
    for (hex = 0; hex < HEXPERTRIANGLE && hexOfPoint(here, hex) != -1; hex++) {
        int currHex = hexOfPoint(here, hex);
        int tri;
        for (tri = 0; tri < TRIANGLESINHEX; tri++) {
            Point curr = hexagons[currHex][tri];
            if (possibleInPoint(curr, value) && pointPossibleCount(curr)) {
                possibleInPoint(curr, value) = 0;
                pointPossibleCount(curr)--;
                if (pointPossibleCount(curr) == 1) {
                    setValue(curr);
                }
            }
        }
    }
}

Point getNextUndecided(Point p);
Point getNextUndecided(Point p){
    int x = p.x + 1, y = p.y;
    for (; x <= hexRangeX[y].to; x++) {
        if (gridPossibleCount[x][y]) {
            return makePoint(x, y);
        }
    }
    for (y++; y < GRIDHEIGHT; y++) {
        for (x = hexRangeX[y].from; x <= hexRangeX[y].to; x++) {
            if (gridPossibleCount[x][y]) {
                return makePoint(x, y);
            }
        }
    }
    return makePoint(-1, -1);
}

int testForValidity(Point here);
int testForValidity(Point here){
    int hex;
    for (hex = 0; hex < HEXPERTRIANGLE && hexOfPoint(here, hex) != -1; hex++) {
        int currHex = hexOfPoint(here, hex);
        int tri;
        int test[7] = {0};
        for (tri = 0; tri < TRIANGLESINHEX; tri++) {
            if (test[pointInGrid(hexagons[currHex][tri])]) {
                return 0;
            } else if (pointInGrid(hexagons[currHex][tri])) { // skip 0s
                test[pointInGrid(hexagons[currHex][tri])] = 1;
            }
        }
    }
    return 1;
}

void bruteTry(Point here);
void bruteTry(Point here){
    int i;
    if (here.x == -1 && here.y == -1) {
        printGrid();
        exit(0);
    }
    for (i = 1; i <= POSSIBLEVALS; i++) {
        if (possibleInPoint(here, i)) {
            pointInGrid(here) = i;
            if (testForValidity(here)) {
                bruteTry(getNextUndecided(here));
            }
        }
    }
    pointInGrid(here) = 0;
}

void bruteForce(void);
void bruteForce(void){
    bruteTry(getNextUndecided(makePoint(0, 0)));
}

int main (int argc, const char * argv[])
{
    int x, y;
    
    // Set all the numbers as possible.
    for (y = 0; y < GRIDHEIGHT; y++) {
        for (x = hexRangeX[y].from; x <= hexRangeX[y].to; x++) {
            gridPossibleCount[x][y] = 6;
            int c;
            for (c = 1; c <= 6; c++) {
                gridPossible[x][y][c] = 1;
            }
        }
    }
    for (y = 0; y < GRIDHEIGHT; y++) {
        for (x = hexRangeX[y].from; x <= hexRangeX[y].to; x++) {
            scanf("%d", &grid[x][y]);
            if (grid[x][y]) {
                gridPossibleCount[x][y] = 0;
            }
        }
    }

    for (y = 0; y < GRIDHEIGHT; y++) {
        for (x = hexRangeX[y].from; x <= hexRangeX[y].to; x++) {
            if (grid[x][y]) {
                removePossibilities(makePoint(x, y));
            }
        }
    }
    
    bruteForce(); // this will finish the puzzle if there are undecided\
                  triangles, or do nothing if it's complete.
    
    return 0;
}
