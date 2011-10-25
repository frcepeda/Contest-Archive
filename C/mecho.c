#include <stdio.h>
#include <stdlib.h>

#define MOVS 4
#define getNext(point, i) makePoint(point.x + movs[i].x, point.y + movs[i].y)
#define isValidPoint(point) point.x >= 0 && point.x < mapSize && point.y >= 0 && point.y < mapSize
#define isGrass(point) map[point.x][point.y] == GRASS
#define INST_MAX 100000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int distance;
} Step;

Point makePoint(int x, int y){
    Point point = {x, y};
    return point;
}

Step makeStep(Point x, int y){
    Step point = {x, y};
    return point;
}

typedef enum {
    HOME = 1,
    TREE,
    GRASS,
    BEE
} mapValues;

mapValues map[801][801];
Point bees[641601];
Point movs[MOVS] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int beesNum = -1;
int beesIndexes[10000];
int beesIndexnum = -1;
int mapSize;
int speed;
Step queue[INST_MAX];
int queueStart = -1;
int queueEnd = -1;
int retracted;

void push(Step step){
    queue[++queueEnd] = step;
}

Step pop(){
    return queue[++queueStart];
}

Point start, end;

void addBee(Point bee){
    if(map[bee.x][bee.y] != BEE){
        bees[++beesNum] = bee;
        map[bee.x][bee.y] = BEE;
    }
}

int startIsOpen(){
    int i, isOpen = 0;
    for(i = 0; i < MOVS; i++){
        Point next = getNext(start, i);
        if (isValidPoint(next) && map[next.x][next.y] == GRASS){
            isOpen = 1;
            break;
        }
    }
    return isOpen;
}

void expandBees(){
    beesIndexes[++beesIndexnum] = beesNum;
    int i, j;
    for(i = 0; i <= beesIndexes[beesIndexnum]; i++){
        for(j = 0; j < MOVS; j++){
            Point next = getNext(bees[i], j);
            if(isValidPoint(next) && isGrass(next)){
                    addBee(next);
            }
        }
    }
}

void retractBees(){
    retracted++;
    int first = beesIndexes[beesIndexnum--];
    int i;
    for(i = first + 1; i <= beesNum; i++){
        Point bee = bees[i];
        map[bee.x][bee.y] = GRASS;
    }

}

int search(){
    while(startIsOpen()){
        expandBees();
    }
    Step startStep = {start, beesIndexnum + 1};
    push(startStep);
    int seconds = beesIndexnum + 1;
    while(beesIndexnum){
        retractBees();
        int currNum = queue[queueStart + 1].distance;
        while(queueStart < queueEnd){
            Step step = pop();
            if(step.distance < currNum - speed){
                push(step);
                break;
            }
            if(step.point.x == end.x && step.point.y == end.y){
                return (abs((seconds)-(step.distance)) / speed) - 1;
            }
            int i;
            for(i = 0; i < MOVS; i++){
                Point next = getNext(step.point, i);
                if(isValidPoint(next) && isGrass(next)){
                    push(makeStep(next, step.distance - 1));
                }
            }
        }
    }
    return -1;
}

int main(){
    int x, y;

    scanf("%d %d", &mapSize, &speed);

    for(y = 0; y < mapSize; y++){
        for(x = 0; x < mapSize; x++){
            char cell;
            int gotValidCharacter = 0;
            do{
                scanf("%c", &cell);
                switch(cell){
                    case 'T':
                        map[x][y] = TREE;
                        gotValidCharacter = 1;
                        break;
                    case 'M':
                        end = makePoint(x, y);
                    case 'G':
                        map[x][y] = GRASS;
                        gotValidCharacter = 1;
                        break;
                    case 'H':
                        addBee(makePoint(x, y));
                        map[x][y] = BEE;
                        gotValidCharacter = 1;
                        break;
                    case 'D':
                        map[x][y] = HOME;
                        start = makePoint(x, y);
                        gotValidCharacter = 1;
                        break;
                }
            } while(gotValidCharacter == 0);
        }
    }

    int min = search();

    /*
    printf("\n");
    for(y = 0; y < mapSize; y++){
        for(x = 0; x < mapSize; x++){
            printf("%d", map[x][y]);
        }
        printf("\n");
    }
    */

    printf("%d\n", min);

    return 0;
}
