//
//  main.c
//  Expresiones
//
//  Created by Freddy Roman Cepeda on 12/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

#define MAXNUM 3000
#define MOD 997
#define SIZEONE 2
#define FIRST 3
#define SECOND 5

long long int mem[MAXNUM];
int visited[MAXNUM];

long long int search(int size);
long long int search(int size){
    if (visited[size]) {
        return mem[size];
    } else if (size <= 0) {
        return 0;
    } else if (size == 1) {
        return SIZEONE;
    }
    
    mem[size] = search(size-FIRST) % MOD;
    
    int i = size-SECOND-1, j = 1;
    for (; i > 0; i--, j++) {
        mem[size] += (search(i) * search(j) * 2) % MOD;
        mem[size] %= MOD;
    }
    
    visited[size] = 1;
    
    return mem[size];
}

int main (int argc, const char * argv[])
{
    int num;
    scanf("%x", &num);
    printf("%llx\n", search(num) % MOD);
    return 0;
}

