#include <stdio.h>
#include <stdlib.h>

int schools[101][100];
int visited[101];
int network[101];

void countLinks(int school, int networkNum){
    if(visited[school]){
        return;
    }

    visited[school] = 1;

    int i = -1;
    while(1){
        if(schools[school][++i] == 0){
            break;
        }
        countLinks(schools[school][i], networkNum);
    }

    network[school] = networkNum;
    visited[school] = 0;

    return;
}

int main()
{
    int schoolNum;
    scanf("%d", &schoolNum);
    int i, j;
    for(i = 1; i <= schoolNum; i++){
        int counter = -1;
        do {
            scanf("%d", &schools[i][++counter]);
        } while(schools[i][counter]);
    }

    for(i = 1; i <= schoolNum; i++){
        if(network[i] == 0) countLinks(i, i);
    }

    int uniqueCount = 0;
    visited[uniqueCount++] = network[1];
    for(i = 1; i <= schoolNum; i++){
        int different = 1;
        for(j = 0; j < uniqueCount; j++){
            if(network[i] == visited[j])
                different = 0;
        }
        if(different){
            visited[uniqueCount++] = network[i];
        }
    }

    printf("%d\n", uniqueCount);
    return 0;
}
