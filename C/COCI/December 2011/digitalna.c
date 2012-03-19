//
//  main.c
//  DIGITALNA
//
//  Created by Freddy Roman Cepeda on 12/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAXNUM 100
#define MAXSIZE 10
#define BLJTV1 "BLJTV1"
#define BLJTV2 "BLJTV2"
#define MOVEUP "1"
#define MOVEDOWN "2"
#define SWITCHUP "3"
#define SWITCHDOWN "4"

//int channels[MAXNUM];
int channel1;
int channel2;
int num;
int sum;

int lol(char *a, char *b){
    int i;
    while (a[i] != '\0' && a[i] == b[i]) {
        i++;
    }
    return a[i] == b[i] ? 0 : 1;
}

int main (int argc, const char * argv[])
{
    int i;
    char temp[MAXSIZE+1];
    temp[10] = '\0';
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        int c = 0;
        do {
            if (c > 1 && temp[c] == '\n') {
                temp[c] = '\0';
                break;
            }
            temp[c] = getchar();
        } while (temp[c] == ' ' ||
                 temp[c] == '\n' ||
                 temp[c] == '\r' ||
                 ++c < MAXSIZE);
        if (lol(temp, BLJTV1) == 0) {
            channel1 = i;
        } else if (lol(temp, BLJTV2) == 0){
            channel2 = i;
        }
    }
    for (i = 1; i < channel1; i++) {
        printf(MOVEUP);
    }
    for (i = channel1; i > 1; i--) {
        printf(SWITCHDOWN);
    }
    if (channel2 < channel1) {
        channel2++;
    }
    for (i = 1; i < channel2; i++) {
        printf(MOVEUP);
    }
    for (i = channel2; i > 2; i--) {
        printf(SWITCHDOWN);
    }
    printf("\n");
    return 0;
}

