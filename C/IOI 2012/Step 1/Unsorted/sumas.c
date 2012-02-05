#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXCOMB 100
#define square(a) pow(a, 2)

int combinations[MAXCOMB][6];
int combinationsCount;

int num, length, max;

int checkForNewCombination(){
    if(combinationsCount == 0) return 1;
    int i;
    int isNew[MAXCOMB];
    int result = 1;
    for(i = 0; i < combinationsCount; i++){
        int j;
        int Acounted[100] = {0};
        int Bcounted[100] = {0};
        for(j = 0; j < length; j++){
            int a = combinations[combinationsCount][j] - 1;
            int b = combinations[i][j] - 1;
            Acounted[a]++;
            Bcounted[b]++;
        }
        for(j = 0; j < max; j++){
            if(Acounted[j] == Bcounted[j]){Acounted[j] = -1;}
        }
        for(j = 0; j < max; j++){
            if(Acounted[j] != -1) isNew[i] = 1;
        }
    }
    for(i = 0; i < combinationsCount; i++){
        if(isNew[i] != 1) {result = 0; break;}
    }
    return result;
}

void magic(int currNum, int numLength){
    int i;
    if(currNum == num && numLength == length) {
        if(checkForNewCombination()){
            for(i = 0; i < length; i++){
                combinations[combinationsCount + 1][i] = combinations[combinationsCount][i];
            }
            combinationsCount++;
        }
        return;
    }
    if(currNum >= num || numLength >= length) return;
    for(i = 1; i <= max; i++){
        combinations[combinationsCount][numLength] = i;
        magic(currNum + square(i), numLength+1);
    }
}

int main()
{
    scanf("%d", &num);
    scanf("%d", &length);

    max = sqrt(num);

    magic(0, 0);

    printf("%d\n", combinationsCount);
    return 0;
}
