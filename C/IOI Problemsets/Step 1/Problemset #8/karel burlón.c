//
//  main.c
//  Karel Burlón
//
//  Created by Freddy Roman Cepeda on 12/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXNUM 100000

#define distanceBetween(a,b) (abs(a.x-b.x)+abs(a.y-b.y))

#define min(a,b) (a < b ? a : b)

typedef struct{
    int x,y;
} Point;

Point makePoint(int x, int y);
Point makePoint(int x, int y){
    Point p = {x,y};
    return p;
}

int intCompare(int a, int b);
int intCompare(int a, int b){
    if (a > b) {
        return 1;
    } else if (b > a) {
        return -1;
    }
    return 0;
}

int xCompare(const void *a, const void *b);
int xCompare(const void *a, const void *b){
    return intCompare(((Point *)a)->x, ((Point *)b)->x);
}

int yCompare(const void *a, const void *b);
int yCompare(const void *a, const void *b){
    return intCompare(((Point *)a)->y, ((Point *)b)->y);
}

Point pointsByX[MAXNUM];

int bruteMinDistance(Point points[], int count);
int bruteMinDistance(Point points[], int count){
    if (count == 1) {
        return INT_MAX;
    }
    return distanceBetween(points[0], points[1]);
}

int minDistance(Point xSort[], int count);
int minDistance(Point xSort[], int count){
    int minLeft, minRight, min, mid, a;
    if (count <= 2) {
        return bruteMinDistance(xSort, count);
    }
    mid = count/2;
    minLeft = minDistance(xSort, mid);
    minRight = minDistance(xSort + mid, count - mid);
    min = min(minRight, minLeft);
    for (a = mid - 1; a >= 0 && xSort[mid].x - xSort[a].x < min; a--) {
        int b;
        for (b = mid; b < count && xSort[b].x - xSort[mid].x < min; b++) {
            if (distanceBetween(xSort[a], xSort[b]) < min) {
                min = distanceBetween(xSort[a], xSort[b]);
            }
        }
    }
    return min;
}

int main (int argc, const char * argv[])
{
    int num, i;
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d %d", &pointsByX[i].x, &pointsByX[i].y);
    }
    qsort(pointsByX, num, sizeof(Point), xCompare);
    printf("%d\n", minDistance(pointsByX, num));
    return 0;
}

