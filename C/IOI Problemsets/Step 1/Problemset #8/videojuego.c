//
//  main.c
//  Videojuego
//
//  Created by Freddy Roman Cepeda on 12/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000000

#define distanceBetween(a,b) (abs(a.x-b.x)+abs(a.y-b.y))
#define minTwo(a,b) (a < b ? a : b)
#define min(a,b,c) minTwo(minTwo(a,b),c)

typedef struct {
    int x,y;
} Point;

int distances[MAXNUM];

int intPtrCompare(const void *a, const void *b);
int intPtrCompare(const void *a, const void *b){
    int aVal = *((int *)a), bVal = *((int *)b);
    if (aVal > bVal) {
        return 1;
    } else if (bVal > aVal){
        return -1;
    } else {
        return 0;
    }
}

int main (int argc, const char * argv[])
{
    int num, i, time;
    Point stores[3];
    scanf("%d %d", &num, &time);
    for (i = 0; i < 3; i++) {
        scanf("%d %d", &stores[i].x, &stores[i].y);
    }
    for (i = 0; i < num; i++) {
        Point nao;
        scanf("%d %d", &nao.x, &nao.y);
        distances[i] = min(distanceBetween(nao, stores[0]),
                           distanceBetween(nao, stores[1]),
                           distanceBetween(nao, stores[2]));
    }
    qsort(distances, num, sizeof(int), intPtrCompare);
    printf("%d\n", distances[time-1]);
    return 0;
}

