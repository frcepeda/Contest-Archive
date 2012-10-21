//
//  main.c
//  Rockstar
//
//  Created by Freddy Roman Cepeda on 12/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

#define MAXSONG 51
#define MAXVOL 1001

#define maxTwo(a,b) (a > b ? a : b)
#define max(a,b,c) maxTwo(maxTwo(a,b), c)

int states[MAXSONG][MAXVOL];
int increments[MAXSONG];

int main (int argc, const char * argv[])
{
    int start, songs, max;
    int i;
    
    scanf("%d %d %d", &songs, &max, &start);
    for (i = 0; i < songs; i++) {
        scanf("%d", &increments[i]);
    }
    
    
    for (i = 0; i <= max; i++) {
        states[songs][i] = i;
    }
    
    for (songs--; songs >= 0; songs--) {
        for (i = 0; i <= max; i++) {
            int up = i + increments[songs];
            int down = i - increments[songs];
            
            if (up >= 0 && up <= max) {
                up = states[songs+1][up];
            } else {
                up = -1;
            }
            
            if (down >= 0 && down <= max) {
                down = states[songs+1][down];
            } else {
                down = -1;
            }
            
            states[songs][i] = maxTwo(up, down);
        }
    }
    
    printf("%d\n", states[0][start]);
    return 0;
}

