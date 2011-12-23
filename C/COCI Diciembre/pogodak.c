//
//  main.c
//  POGODAK
//
//  Created by Freddy Roman Cepeda on 12/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <strings.h>

int die[3][4] = {{0,5,0,0},{4,1,3,6},{0,2,0,0}};
int temp[3][4];

//#define printdie()\
    printf("\n");\
    int _i, _j;\
    for (_i = 0; _i < 3; _i++) {\
        for (_j = 0; _j < 4; _j++) {\
            printf("%d ", die[_i][_j]);\
        }\
        printf("\n");\
    }\

int flipRight(int times);
int flipRight(int times){
    int i, ret = 0;
    for (i = 0; i < 4; i++) {
        ret += die[1][i];
    }
    ret *= (int)(times / 4);
    if(ret) ret -= die[1][1];
    times = times % 4;
    while (times--) {
        int x, y;
        for (x = 0; x < 3; x++)
            for (y = 0; y < 4; y++)
                temp[x][y] = die[x][y];
        for (i = 0; i < 4; i++) {
            int j = (i + 1) % 4;
            die[1][j] = temp[1][i];
        }
        ret += die[1][1];
    }
    return ret;
}

int flipLeft(int times);
int flipLeft(int times){
    int i, ret = 0;
    for (i = 0; i < 4; i++) {
        ret += die[1][i];
    }
    ret *= (int)(times / 4);
    if(ret) ret -= die[1][1];
    times = times % 4;
    while (times--) {
        int x, y;
        for (x = 0; x < 3; x++)
            for (y = 0; y < 4; y++)
                temp[x][y] = die[x][y];
        for (i = 0; i < 4; i++) {
            int j = (i + 4 - 1) % 4;
            die[1][j] = temp[1][i];
        }
        ret += die[1][1];
    }
    return ret;
}

int flipDown(void);
int flipDown(void){
    int x, y;
    for (x = 0; x < 3; x++)
        for (y = 0; y < 4; y++)
            temp[x][y] = die[x][y];
    die[0][1] = temp[1][3];
    die[1][3] = temp[2][1];
    die[2][1] = temp[1][1];
    die[1][1] = temp[0][1];
    return die[1][1];
}

int main (int argc, const char * argv[])
{
    int rows, columns;
    int i, sum;
    scanf("%d %d", &rows, &columns);
    columns--;
    int right = 1;
    for (i = 1; i < rows; i++) {
        if (right) {
            right = 0;
            sum += flipRight(columns);
        } else {
            right = 1;
            sum += flipLeft(columns);
        }
        sum += flipDown();
    }
    if (right) {
        sum += flipRight(columns);
    } else {
        sum += flipLeft(columns);
    }
    printf("%d\n", sum + 1);
    return 0;
}

