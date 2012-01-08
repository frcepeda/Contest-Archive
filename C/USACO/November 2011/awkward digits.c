//
//  main.c
//  Awkward Digits
//
//  Created by Freddy Roman Cepeda on 11/13/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define path "digits"//"/Users/Freddy/Desktop/USACO/Awkward Digits/Awkward Digits/digits"

FILE *in;
FILE *out;

int base2[30] = {0, 1, 0, 1}; //log2(1,000,000,000)
int base2Length;
int base3[19]; //log3(1,000,000,000)
int base3Length;

int getValue(int arr[], int length, int base);
int getValue(int arr[], int length, int base){
    int total = 0, i, basecount = 0;
    for (i = length - 1; i >= 0; i--) {
        total += arr[i] * pow(base, basecount++);
    }
    return total;
}

#define getBase2() getValue(base2, base2Length, 2)
#define getBase3() getValue(base3, base3Length, 3)

int main (int argc, const char * argv[])
{
    in = fopen(path".in", "r");
    out = fopen(path".out", "w");
    
    char c;
    while ((c = fgetc(in)) != '\n') {
        int i = c - '0';
        base2[base2Length++] = i;
    }
    while ((c = fgetc(in)) != '\n') {
        int i = c - '0';
        base3[base3Length++] = i;
    }
    
    int x, y, i, j;
    
    for (x = 0; x < base2Length; x++) {
        int temp = base2[x];
        for (y = (temp + 1) % 2; y != temp; y = (y + 1) % 2) {
            base2[x] = y;
            for (i = 0; i < base3Length; i++) {
                int temp2 = base3[i];
                for (j = (temp2 + 1) % 3; j != temp2; j = (j + 1) % 3) {
                    base3[i] = j;
                    if (getBase2() == getBase3()) {
                        fprintf(out, "%d\n", getBase2());
                        return 0;
                    }
                }
                base3[i] = temp2;
            }
        }
        base2[x] = temp;
    }
    
    return 0;
}

