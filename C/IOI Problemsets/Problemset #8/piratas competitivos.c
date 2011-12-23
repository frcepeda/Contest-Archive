//
//  main.c
//  Piratas Competitivos
//
//  Created by Freddy Roman Cepeda on 12/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100000
#define MAXVAL 2000000

typedef struct {
    int a,b,c;
} Thing;

int tree[MAXVAL];
Thing pirates[MAXNUM];
int result[MAXNUM];

void add(Thing p);
void add(Thing p){
    int x = p.b;
    while (x <= MAXVAL) {
        tree[x]++;
        x += (x & -x);
    }
}

void rem(int p);
void rem(int p){
    while (p <= MAXVAL) {
        tree[p]--;
        p += (p & -p);
    }
}

int read(int p);
int read(int p){
    int ret = 0;
    while (p > 0) {
        ret += tree[p];
        p -= (p & -p);
    }
    return ret;
}

int pComp(const void *a, const void *b);
int pComp(const void *a, const void *b){
    int aVal = ((Thing *)a)->a;
    int bVal = ((Thing *)b)->a;
    if (aVal > bVal) {
        return -1;
    } else if (bVal > aVal) {
        return 1;
    } else {
        return 0;
    }
}

int main (int argc, const char * argv[])
{
    int num, i;
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d %d", &pirates[i].a, &pirates[i].b);
        add(pirates[i]);
        pirates[i].c = i;
    }
    qsort(pirates, num, sizeof(Thing), pComp);
    for (i = 0; i < num; i++) {
        result[pirates[i].c] = read(pirates[i].b) - 1;
        rem(pirates[i].b);
    }
    for (i = 0; i < num; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}

