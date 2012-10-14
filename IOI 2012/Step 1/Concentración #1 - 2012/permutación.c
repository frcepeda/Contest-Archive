//
//  main.c
//  Permutation
//
//  Created by Freddy Roman Cepeda on 1/10/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

int used[16];

int factorial(int a);
int factorial(int a){
    int buf = 1;
    for (;a > 1;a--) {
        buf *= a;
    }
    return buf;
}

void printNext(int i);
void printNext(int i){
    int idx = 1;
    for (; used[idx]; idx++);
    for (; i; idx++) {
        if (!used[idx]) {
            i--;
        }
    }
    for (; used[idx]; idx++);
    used[idx] = 1;
    printf("%d ", idx);
}

void nth_permutation(int n, int len);
void nth_permutation(int n, int len){
    if (len == 1) {
        printNext(0);
        return;
    }
    int fact = factorial(--len);
    int i = (int)(n/fact);
    printNext(i);
    nth_permutation(n%(int)fact, len);
}

int main (int argc, const char * argv[])
{
    int n, m, i = 0, t = 1;
    for (i = 1; i < n; i *= i+1, t++);
    scanf("%d %d", &n, &m);
    nth_permutation(n, m);
    printf("\n");
    return 0;
}

