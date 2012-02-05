//
//  main.c
//  Pastel
//
//  Created by Freddy Roman Cepeda on 1/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

int n,m;
int x,y;
int nim[4];

int main (int argc, const char * argv[])
{
    scanf("%d %d", &n, &m);
    scanf("%d %d", &y, &x);
    nim[0] = x-1;
    nim[1] = y-1;
    nim[2] = n-x;
    nim[3] = m-y;
    if (nim[0]^nim[1]^nim[2]^nim[3]) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}

