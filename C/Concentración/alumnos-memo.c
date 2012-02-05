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

unsigned long long int memo[STUDENTS][MAXNUM];
int visited[STUDENTS][MAXNUM];
unsigned int likes[STUDENTS];
int num;
unsigned int max;

#define setBit(a,b) a |= 1<<b

unsigned long long int mem(int stu, int sub);
unsigned long long int mem(int stu, int sub){
    if (visited[stu][sub]) {
        return memo[stu][sub];
    }
    if (stu == num-1){
        return (likes[stu] & ~sub) != 0;
    }
    int temp = likes[stu];
    while (temp) {
        int curr = temp & (~temp + 1);
        temp -= curr;
        if (curr & ~sub) {
            memo[stu][sub] += mem(stu+1,sub|curr);
        }
    }
    visited[stu][sub] = 1;
    return memo[stu][sub];
}

int main (int argc, const char * argv[])
{
    int i;
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        unsigned int liked;
        scanf("%ud", &liked);
        while (liked--) {
            unsigned int temp;
            scanf("%ud", &temp);
            setBit(likes[i], temp);
        }
    }
    
    max = 1<<num;
    
    /*
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
    */
    
    printf("%lld\n", mem(0,0));
    
    return 0;
}

