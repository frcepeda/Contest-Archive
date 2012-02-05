//
//  main.c
//  Alumnos
//
//  Created by Freddy Roman Cepeda on 1/11/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

#define MAXNUM 1<<20
#define STUDENTS 20
#define SUBJECTS STUDENTS

unsigned long long int dp[STUDENTS][MAXNUM];
unsigned long long int likes[STUDENTS];
unsigned long long int num;
unsigned long long int max;

#define setBit(a,b) a |= 1<<b

int main (int argc, const char * argv[])
{
    long long int i;
    unsigned long long int num, j;
    scanf("%lld", &num);
    for (i = 0; i < num; i++) {
        unsigned long long int liked;
        scanf("%lld", &liked);
        while (liked--) {
            unsigned long long int temp;
            scanf("%lld", &temp);
            setBit(likes[i], temp);
        }
    }
    
    max = 1<<num;
    
    for (j = 0; j < max; j++) {
        if (likes[num-1] & ~j) {
            dp[num-1][j] = 1;
        }
    }
    
    for (i = num - 2; i >= 0; i--) {
        for (j = 0; j < max; j++) {
            long long int temp = likes[i];
            while (temp) {
                unsigned long long int curr = temp & (~temp + 1);
                temp -= curr;
                if (curr & ~j) {
                    dp[i][j] += dp[i+1][j|curr];
                }
            }
        }
    }
    
    printf("%lld\n", dp[0][0]);
    
    return 0;
}

