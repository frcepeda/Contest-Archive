//
//  main.c
//  Burbujas
//
//  Created by Freddy Roman Cepeda on 1/11/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

#define MAXNUM 1001

#define max(a,b) (a>b?a:b)

int map[MAXNUM][MAXNUM];
int dp[MAXNUM][MAXNUM];
int num, total;

void printMap(void);
void printMap(void){
    int i,j;
    for (i = 1; i <= num; i++) {
        for (j = 1; j <= num - i + 1; j++) {
            printf("%d ", map[j][i]);
        }
        printf("\n");
    }
}

int main (int argc, const char * argv[])
{
    int i,j;
    
    while (scanf("%d", &num) && num) {
        for (i = 1; i <= num; i++) {
            for (j = 1; j <= i; j++) {
                scanf("%d", &map[j][i-j+1]);
            }
        }
        
        for (i = 1; i <= num; i++) {
            for (j = 2; j <= num - i + 1; j++) {
                map[i][j] += map[i][j-1];
            }
        }
        
        for (i = num; i > 0; i--) {
            for (j = 1; j <= num; j++) {
                dp[i][j] = max(dp[i][j-1], dp[i+1][j] + map[i][j]);
            }
        }
        
        printf("%d\n", dp[1][num]);
    };
    
    return 0;
}

