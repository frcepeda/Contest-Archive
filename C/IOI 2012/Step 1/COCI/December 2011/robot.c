//
//  main.c
//  ROBOT
//
//  Created by Freddy Roman Cepeda on 12/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100000

#define distanceBetween(a,b) (abs(a.x-b.x)+abs(a.y-b.y))

typedef struct {
    int x,y;
} Point;

Point points[MAXNUM];
Point me;
int num;

int distanceBetweenAll(void);
int distanceBetweenAll(void){
    int sum = 0, i;
    for (i = 0; i < num; i++) {
        sum += distanceBetween(me, points[i]);
    }
    return sum;
}

int main (int argc, const char * argv[])
{
    int i, queries;
    scanf("%d %d", &num, &queries);
    for (i = 0; i < num; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    for (i = 0; i < queries; i++) {
        char q;
        do {
            q = getchar();
        } while (q == '\n' || q == '\r' || q == ' ');
        switch (q) {
            case 'S':
                me.y++;
                break;
            case 'J':
                me.y--;
                break;
            case 'I':
                me.x++;
                break;
            case 'Z':
                me.x--;
                break;
            default:
                break;
        }
        printf("%d\n", distanceBetweenAll());
    }
    return 0;
}

