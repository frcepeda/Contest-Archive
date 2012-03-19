//
//  main.c
//  D’HONDT
//
//  Created by Freddy Roman Cepeda on 12/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define SEATS 14
#define MAXPARTIES 10

#define toInt(a) (a - 'A')
#define toChar(a) ('A' + a)

typedef struct {
    int party;
    double score;
} Thing;

Thing makeThing(int party, double score);
Thing makeThing(int party, double score){
    Thing t = {party, score};
    return t;
}

int thingCmp(const void *a, const void *b);
int thingCmp(const void *a, const void *b){
    double aV = ((Thing *)a)->score;
    double bV = ((Thing *)b)->score;
    if (aV > bV) {
        return -1;
    } else if (bV > aV){
        return 1;
    } else {
        return 0;
    }
}

Thing scores[MAXPARTIES*SEATS];
int partyVotes[MAXPARTIES];
int usingParty[MAXPARTIES];

int main (int argc, const char * argv[])
{
    int parties, voters, i, lastScore = 0;
    scanf("%d %d", &voters, &parties);
    for (i = 0; i < parties; i++) {
        char party;
        int votes;
        do {
            party = getchar();
            if (party == EOF) {
                break;
            }
        } while (party == '\n' ||
                 party == '\r' ||
                 party == ' ');
        scanf("%d", &votes);
        partyVotes[toInt(party)] = votes;
        usingParty[toInt(party)] = 1;
    }
    for (i = 0; i < MAXPARTIES; i++) {
        int j;
        if (usingParty[i] && partyVotes[i] > voters * 0.05) {
            for (j = 1; j <= SEATS; j++) {
                scores[lastScore++] = makeThing(i, partyVotes[i] / j);
            }
        }
    }
    qsort(scores, lastScore, sizeof(Thing), thingCmp);
    memset(partyVotes, 0, sizeof(partyVotes));
    for (i = 0; i < SEATS; i++) {
        partyVotes[scores[i].party]++;
    }
    for (i = 0; i < MAXPARTIES; i++) {
        if (usingParty[i] && partyVotes[i])
            printf("%c %d\n", toChar(i), partyVotes[i]);
    }
    return 0;
}

