//
//  main.c
//  Serpiente
//
//  Created by Freddy Roman Cepeda on 1/10/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000000
#define max(a,b) (a>b?a:b)

typedef struct {
    int x,y;
} Point;

Point makePoint(int x, int y);
Point makePoint(int x, int y){
    Point p = {x,y};
    return p;
}

void rotate(Point *p, int times);
void rotate(Point *p, int times){
    while (times--) {
        int temp = p->y;
        p->y = -p->x;
        p->x = temp;
    }
}

void align(Point *p, const Point *o);
void align(Point *p, const Point *o){
    p->x -= o->x;
    p->y -= o->y;
}

void mirrorX(Point *p);
void mirrorX(Point *p){
    p->x = -p->x;
}

#define topleft 0
#define topright 1
#define botleft 2
#define botright 3

int spiralDistance(Point here);
int spiralDistance(Point here){
    int level = max(abs(here.x),abs(here.y));
    int corners[4];
    corners[botright] = pow(level,2)*4;
    corners[topleft] = pow(level*2+1,2)-1;
    corners[botleft] = (corners[topleft]+corners[botright])/2;
    corners[topright] = corners[botright]-(corners[botleft]-corners[botright]);
    if (here.x == level) {
        return corners[topright] + level - here.y;
    } else if (here.x == -level) {
        return corners[botleft] + level + here.y;
    } else if (here.y == level) {
        if (here.x == level) {
            return corners[topleft];
        } else {
            return corners[topright] - level + here.x;
        }
    } else {
        return corners[botleft] - level - here.x;
    }
}

int main (int argc, const char * argv[])
{
    Point start, food;
    char direction, cwise;
    scanf("%d %d", &start.x, &start.y);
    scanf("%d %d", &food.x, &food.y);
    scanf("%*[ \r\n]%c%c", &direction, &cwise);
    align(&food, &start);
    if (cwise == 'A') {
        mirrorX(&food);
    }
    switch (direction) {
        case 'E':
            rotate(&food, 3);
            break;
        case 'S':
            rotate(&food, 2);
            break;
        case 'W':
            rotate(&food, 1);
            break;
        default:
            break;
    }
    printf("%d\n", spiralDistance(food));
    return 0;
}

