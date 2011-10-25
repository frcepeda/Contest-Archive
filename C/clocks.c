#include <stdio.h>
#include <stdlib.h>

#define MOVNUM 10
#define CLOCKNUM 9
#define INST_MAX 9999999
#define visitedStep(step) visited[step.clocks[0]][step.clocks[1]][step.clocks[2]][step.clocks[3]][step.clocks[4]][step.clocks[5]][step.clocks[6]][step.clocks[7]][step.clocks[8]]

int moves[MOVNUM][CLOCKNUM] = {{0}
                            , {1, 1, 0, 1, 1}
                            , {1, 1, 1}
                            , {0, 1, 1, 0, 1, 1}
                            , {1, 0, 0, 1, 0, 0, 1}
                            , {0, 1, 0, 1, 1, 1, 0, 1}
                            , {0, 0, 1, 0, 0, 1, 0, 0, 1}
                            , {0, 0, 0, 1, 1, 0, 1, 1}
                            , {0, 0, 0, 0, 0, 0, 1, 1, 1}
                            , {0, 0, 0, 0, 1, 1, 0, 1, 1}};

int visited[4][4][4][4][4][4][4][4][4];

typedef struct{
    int clocks[9];
    int parentIndex;
    int move;
} Step;

int startClocks[9];

Step queue[INST_MAX];
int queueStart = -1, queueEnd = -1;

void push(Step step){
    queue[++queueEnd] = step;
}

Step pop(){
    return queue[++queueStart];
}

int queueIsNotEmpty(){
    return queueStart < queueEnd;
}

Step search(){
    Step start;
    int wasd;
    for(wasd = 0; wasd < CLOCKNUM; wasd++)
        start.clocks[wasd] = startClocks[wasd];
    start.parentIndex = -1;
    push(start);
    while(queueIsNotEmpty()){
        Step step = pop();
        if(visitedStep(step))
            continue;
        int i, j, isTarget = 1;
        for(i = 0; i < CLOCKNUM; i++){
            if (step.clocks[i]){
                isTarget = 0;
                break;
            }
        }
        if(isTarget)
            return step;
        visitedStep(step) = 1;
        Step next;
        next.parentIndex = queueStart;
        for (i = 1; i < MOVNUM; i++){
            for (j = 0; j < CLOCKNUM; j++){
                next.clocks[j] = (step.clocks[j] + moves[i][j]) % 4;
            }
            next.move = i;
            if(visitedStep(next) == 0)
                push(next);
        }
    }
    return start; // shut the compiler up
}

int main(){
    int i;

    for(i = 0; i < 9; i++){
        scanf("%d", &startClocks[i]);
    }

    Step result = search();

    //printf("   A B C D E F G H I\n");

    while (result.parentIndex != -1){
        printf("%d ", result.move);

        /*
        printf("%d: ", result.move);
        int i;
        for(i = 0; i < CLOCKNUM; i++)
            printf("%d ", result.clocks[i]);
        printf("\n");
        */

        result = queue[result.parentIndex];
    }

    //printf("\n%d", queueEnd);

    /*
    printf("\n");

    for(i = 0; i < MOVNUM; i++){
        for(j = 0; j < CLOCKNUM; j++){
            printf("%d", moves[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}
