//
//  main.c
//  structtest
//
//  Created by Freddy Roman Cepeda on 1/9/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

typedef struct {
    int a,b;
} aStruct;

typedef struct {
    int b,a;
} bStruct;

void print(aStruct a);
void print(aStruct a){
    bStruct b = *(bStruct *)(void *)&a;
    printf("%d %d\n", b.b, b.a);
}

int main (int argc, const char * argv[])
{
    aStruct a = {0,1};
    print(a);
    return 0;
}

