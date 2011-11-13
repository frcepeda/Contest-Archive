//
//  main.c
//  Cow Beauty
//
//  Created by Freddy Roman Cepeda on 11/13/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

#define path "pageant"//"/Users/Freddy/Desktop/USACO/Cow Beauty/Cow Beauty/pageant"

#define MAXSIZE 50
#define MAXQUEUE 10000

typedef struct {
    int x, y;
} Point;

Point makePoint(int x, int y);
Point makePoint(int x, int y){
    Point point = {x, y};
    return point;
}

typedef struct {
    int width, height;
} Size;

int map[MAXSIZE][MAXSIZE];
Size mapSize;

#define pointInMap(p) map[p.x][p.y]
#define isValidPoint(p) (p.x >= 0 && p.x < mapSize.width && p.y >= 0 && p.y < mapSize.height)

#define MOVCOUNT 4
Point movs[MOVCOUNT] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
#define nextPoint(p,i) makePoint(p.x + movs[i].x, p.y + movs[i].y)

Point queue[MAXQUEUE];
int qs, qe;

#define push(p) queue[qe++ % MAXQUEUE] = p;
#define pop() queue[qs++ % MAXQUEUE];
#define queueIsNotEmpty (qs < qe)
#define resetQueue() qs = qe = 0

FILE *in;
FILE *out;

#define test -1
#define EMPTY 1 * test
#define SPOT 2 * test
#define SPOTA 3 * test
#define SPOTB 4 * test

void color(Point start, int col);
void color(Point start, int col){
    push(start);
    while (queueIsNotEmpty) {
        Point curr = pop();
        pointInMap(curr) = col;
        int i;
        for (i = 0; i < MOVCOUNT; i++) {
            Point next = nextPoint(curr, i);
            if (isValidPoint(next) && pointInMap(next) == SPOT) {
                push(next);
            }
        }
    }
    resetQueue();
}

#define printMap() for (y = 0; y < mapSize.height; y++) {for (x = 0; x < mapSize.width; x++)\
{fprintf(out, "%d ", map[x][y]);} fprintf(out, "\n");}fprintf(out, "\n");

Point startPoint(void);
Point startPoint(void){
    int x, y;
    for (y = 0; y < mapSize.height; y++) {
        for (x = 0; x < mapSize.width; x++) {
            if (map[x][y] == SPOTA) {
                return makePoint(x, y);
            }
        }
    }
    return makePoint(0, 0);
}

int doSearch(Point start);
int doSearch(Point start){
    int minDist = INT_MAX;
    pointInMap(start) = 0;
    push(start)
    while (queueIsNotEmpty) {
        Point curr = pop();
        int i;
        for (i = 0; i < MOVCOUNT; i++) {
            Point next = nextPoint(curr, i);
            if (isValidPoint(next)) {
                if (pointInMap(next) == SPOTB && minDist > pointInMap(curr)) {
                    minDist = pointInMap(curr);
                } else if (pointInMap(next) == SPOTA) {
                    pointInMap(next) = 0;
                    push(next);
                } else if (pointInMap(next) == EMPTY) {
                    pointInMap(next) = pointInMap(curr) + 1;
                    push(next);
                } else if (pointInMap(next) > pointInMap(curr) + 1) {
                    pointInMap(next) = pointInMap(curr) + 1;
                    push(next);
                }
            }
        }
    }
    return minDist;
}

int main (int argc, const char * argv[])
{
    in = fopen(path".in", "r");
    out = fopen(path".out", "w");
    
    fscanf(in, "%d %d", &mapSize.height, &mapSize.width);
    
    int x, y;
    
    for (y = 0; y < mapSize.height; y++) {
        for (x = 0; x < mapSize.width; x++) {
            char c;
            do{
                fscanf(in, "%c", &c);
            } while (c != 'X' && c != '.');
            map[x][y] = c == 'X' ? SPOT : EMPTY;
        }
    }
    
    int col = SPOTA;
    for (y = 0; y < mapSize.height; y++) {
        for (x = 0; x < mapSize.width; x++) {
            if (map[x][y] == SPOT) {
                color(makePoint(x, y), col);
                col = SPOTB;
            }
        }
    }
    
    //printMap();
    
    Point start = startPoint();

    int result = doSearch(start);
    
    fprintf(out, "%d\n", result);

    return 0;
}

