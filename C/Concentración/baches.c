//
//  main.c
//  Baches
//
//  Created by Freddy Roman Cepeda on 1/11/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXBUMPS 50//000

int bumps[MAXBUMPS];

int intCompare(const void *a, const void *b);
int intCompare(const void *a, const void *b){
    if (*(int *)a > *(int *)b) {
        return 1;
    } else if (*(int *)a < *(int *)b){
        return -1;
    } else {
        return 0;
    }
}

int main (int argc, const char * argv[])
{
    int i, bumpnum, planks, total = 0;
    scanf("%*d %d", &bumpnum);
    for(i = 0; i < bumpnum; i++){
        scanf("%d", &bumps[i]);
    }
    scanf("%d", &planks);
    qsort(bumps, bumpnum, sizeof(int), intCompare);
    for (i = 1; i < bumpnum; i++) {
        bumps[i-1] = bumps[i] - bumps[i-1];
    }
    qsort(bumps, bumpnum, sizeof(int), intCompare);
    for (i = 0; planks < bumpnum; planks++, i++) {
        total += bumps[i];
    }
    printf("%d\n", total);
    return 0;
}

