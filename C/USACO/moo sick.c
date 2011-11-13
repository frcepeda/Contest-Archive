//
//  main.c
//  Moo Sick
//
//  Created by Freddy Roman Cepeda on 11/13/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define path "moosick"//"/Users/Freddy/Desktop/USACO/Moo Sick/Moo Sick/moosick"

FILE *in;
FILE *out;

#define MAXSONG 20000
#define MAXCHORD 10

int song[MAXSONG];
int chordInd[MAXSONG];
int chord[MAXCHORD];
int chordTest[MAXCHORD];

int songLength;
int chordLength;
int foundChords;

#define sortFrag(arr) qsort(arr, chordLength, sizeof(int), compare);

int compare(const void *a, const void *b);
int compare(const void *a, const void *b){
    const int *aPoint = a;
    const int *bPoint = b;
    if (*aPoint > *bPoint) {
        return 1;
    } else if (*aPoint < *bPoint) {
        return -1;
    }
    return 0;
}

int checkSong(int start);
int checkSong(int start){
    int i;
    for (i = 0; i < chordLength; i++) {
        chordTest[i] = song[i+start];
    }
    sortFrag(chordTest);
    for (i = 0; i < chordLength - 1; i++) {
        if (chordTest[i] - chordTest[i+1] != chord[i] - chord[i+1]) {
            return 0;
        }
    }
    return 1;
}

int main (int argc, const char * argv[])
{
    in = fopen(path".in", "r");
    out = fopen(path".out", "w");
    
    int i;
    
    fscanf(in, "%d", &songLength);
    
    for (i = 0; i < songLength; i++) {
        fscanf(in, "%d", &song[i]);
    }
    
    fscanf(in, "%d", &chordLength);
    
    for (i = 0; i < chordLength; i++) {
        fscanf(in, "%d", &chord[i]);
    }
    
    sortFrag(chord);
    
    for (i = 0; i <= songLength - chordLength; i++) {
        if(checkSong(i)){
            chordInd[foundChords++] = i;
        }
    }
    
    fprintf(out, "%d\n", foundChords);
    for (i = 0; i < foundChords; i++) {
        fprintf(out, "%d\n", chordInd[i]+1);
    }
    
    return 0;
}

