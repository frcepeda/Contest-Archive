//
//  main.c
//  Caminos de la Vida
//
//  Created by Freddy Roman Cepeda on 12/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <strings.h>

#define update(a, i) a = (i) % 314159257;

int main (int argc, const char * argv[])
{
    int num, i;
    int vals[3] = {1,1,1};
    int temp[3];
    scanf("%d", &num);
    for (i = 1; i < num; i++) {
        update(temp[0], vals[0] + vals[1]);
        update(temp[1], temp[0] + vals[1] + vals[2]);
        update(temp[2], temp[1] + vals[2]);
        memcpy(vals, temp, sizeof(vals));
    }
    update(temp[2], vals[2]);
    update(temp[1], temp[2] + vals[2] + vals[1]);
    update(temp[0], temp[1] + vals[1] + vals[0]);
    printf("%d\n", temp[0]);
    return 0;
}

