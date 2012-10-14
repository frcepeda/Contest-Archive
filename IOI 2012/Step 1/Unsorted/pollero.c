#include <stdio.h>
#include <stdlib.h>

int main(){
    int chickens, length, answer = 0;
    int chicken[20001];
    scanf("%d %d", &chickens, &length);
    int i, j;
    for (i = 0; i < chickens; i++){
        scanf("%d", &chicken[i]);
    }
    for (i = 0; i < chickens-1; i++){
        for (j = i+1; j < chickens; j++){
            if (chicken[i] + chicken[j] <= length) answer++;
        }
    }
    printf("%d", answer);
    return 0;
}
