//
//  main.c
//  La Wera
//
//  Created by Freddy Roman Cepeda on 12/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

#define MAXNUM 5001

char buffer[MAXNUM];
int message[MAXNUM];
unsigned long long int dp[MAXNUM];

int main (int argc, const char * argv[])
{
    int i, num = 0;
    char c;
    char *p = buffer;
    scanf("%s", &buffer);
    while ((c = *(p++)) != '\0' && c != '\n' && c != '\r') {
        message[num++] = c - '0';
    }
    dp[num] = 1;
    dp[num-1] = message[num-1] ? 1 : 0;
    for (i = num-2; i >= 0; i--) {
        int temp = message[i] * 10 + message[i+1];
        if (message[i] && temp <= 26 && temp > 0) {
            dp[i] = dp[i+1] + dp[i+2];
        } else if (message[i]) {
            dp[i] = dp[i+1];
        }
    }
    printf("%llu\n", dp[0]);
    return 0;
}

