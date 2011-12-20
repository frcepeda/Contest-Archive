//
//  main.c
//  Regalos Navideños
//
//  Created by Freddy Roman Cepeda on 12/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

#define MAXNUM 1000000

#define max(a,b) (a) > (b) ? (a) : (b)

int gifts[MAXNUM];

int main (int argc, const char * argv[])
{
    int num, i, max;
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d", &gifts[i]);
    }
    max = gifts[--num];
    for (i = num - 1; i >= 0; i--) {
        gifts[i] = max(gifts[i], gifts[i] + gifts[i+1]);
        if (gifts[i] > max) {
            max = gifts[i];
        }
    }
    
    printf("%d\n", max);
    
    return 0;
}

