//
//  main.c
//  Nodos mágicos
//
//  Created by Freddy Roman Cepeda on 11/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <strings.h>

#define MAXPAIRS 100
#define MAXNODES 24

typedef struct {
    int a, b;
} Pair;

Pair pairs[MAXPAIRS];

int nodes[MAXNODES];

int nodeNum, pairNum, magicNum;

int isPossible(int remaining, int current);
int isPossible(int remaining, int current){
    int retval;
    if (current == pairNum && remaining >= 0) {
        retval = 1;
    } else {
        retval = 0;
        if (nodes[pairs[current].a] || nodes[pairs[current].b]) {
            retval = isPossible(remaining, current + 1);
        } else if (remaining) {
            nodes[pairs[current].a] = 1;
            if (!(retval = isPossible(remaining - 1, current + 1))) {
                nodes[pairs[current].a] = 0;
                nodes[pairs[current].b] = 1;
                retval = isPossible(remaining - 1, current + 1);
                nodes[pairs[current].b] = 0;
            }
        }
    }
    return retval;
}

int startThingy(void);
int startThingy(void){
    if (magicNum > nodeNum) {
        return 0;
    }
    return isPossible(magicNum, 0);
}

void doCase(void);
void doCase(void){
    int i;
    scanf("%d %d %d", &nodeNum, &pairNum, &magicNum);
    for (i = 0; i < pairNum; i++) {
        scanf("%d %d", &pairs[i].a, &pairs[i].b);
    }
    if (startThingy()) {
        printf("S\n");
    } else {
        printf("N\n");
    }
}

int main (int argc, const char * argv[])
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        memset(pairs, 0, sizeof(pairs));
        memset(nodes, 0, sizeof(nodes));
        doCase();
    }
    return 0;
}
