#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX 1000
#define INST_MAX 8000000

#define SEA1 -200
#define SEA2 -100

#define finished(step) sea[step.point.x][step.point.y] == SEA2

#define isValidPoint(point) point.x >= 0 && point.x < mapSize.width && point.y >= 0 && point.y < mapSize.height && visited[point.x][point.y] == 0
#define nextPoint(point, i) makePoint(point.x + directions[i].x, point.y + directions[i].y);

#define parent(x) (x-1)/2
#define childA(x) (x*2)+1
#define childB(x) (x*2)+2

#define swap(a, b) Step swapTemp = b; b = a; a = swapTemp;

typedef struct{
    int x, y;
} Point;

typedef struct{
    int width, height;
} Size;

typedef struct{
    Point point;
    int distance;
} Step;

Point makePoint(int x, int y){
    Point point = {x, y};
    return point;
}

Step makeStep(Point point, int val){
    Step step = {point, val};
    return step;
}

Point directions[8] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

int map[SIZE_MAX][SIZE_MAX];
int visited[SIZE_MAX][SIZE_MAX];
int sea[SIZE_MAX][SIZE_MAX];
Size mapSize;
int min;

// Stack

Point stack[INST_MAX];
int stackIndex;

void pushStack(Point point){
    stack[++stackIndex] = point;
}

Point popStack(){
    return stack[stackIndex--];
}

// Heap

Step heap[INST_MAX];
int heapIndex = -1;

void pushHeap(Step step){
    //printf("Pushed: %d, %d.\tValue: %d\n", step.point.x, step.point.y, step.distance);
    heap[++heapIndex] = step;
    int newIndex = heapIndex;
    while(heap[parent(newIndex)].distance > heap[newIndex].distance){
        swap(heap[parent(newIndex)], heap[newIndex]);
        newIndex = parent(newIndex);
    }
}

Step popHeap(){
    Step returnStep = heap[0];
    heap[0] = heap[heapIndex--];
    int newIndex = 0;
    while((childA(newIndex) <= heapIndex && heap[childA(newIndex)].distance < heap[newIndex].distance) || (childB(newIndex) <= heapIndex && heap[childB(newIndex)].distance < heap[newIndex].distance)){
        int swapChild = heap[childA(newIndex)].distance < heap[childB(newIndex)].distance ? childA(newIndex) : childB(newIndex);
        swap(heap[swapChild], heap[newIndex]);
        newIndex = swapChild;
    }
    //printf("Popped: %d, %d.\tValue: %d\n", returnStep.point.x, returnStep.point.y, returnStep.distance);
    return returnStep;
}

// Fill map

Point getPointWithNegativeValue(int ignore){
    int x, y;
    for(x = 0; x < mapSize.width; x++){
        for(y = 0; y < mapSize.height; y++){
            if(map[x][y] < 0 && map[x][y] != ignore)
                return makePoint(x, y);
        }
    }
    return makePoint(0, 0); //shut the compiler up.
}

void fillAreaWithNumber(Point point, int number){
    stackIndex = -1;
    pushStack(point);
    while(stackIndex >= 0){
        point = popStack();
        map[point.x][point.y] = 0;
        sea[point.x][point.y] = number;
        if(visited[point.x][point.y]) continue;
        visited[point.x][point.y] = 1;
        int i;
        for(i = 0; i < 8; i++){
            Point next = nextPoint(point, i);
            if(isValidPoint(next) && map[next.x][next.y] < 0){
                pushStack(next);
            }
        }
    }
}

// Search

void search(Step start){
    int x, y;
    for (x = 0; x < mapSize.width; x++){
        for (y = 0; y < mapSize.height; y++){
            visited[x][y] = 0;
        }
    }
    pushHeap(start);
    while(heapIndex >= 0){
        Step step = popHeap();
        if(finished(step)){
            //printf("FOUND: %d, %d.\tValue: %d\tIndex: %d\n", step.point.x, step.point.y, step.distance, heapIndex);
            min = step.distance;
            break;
        }
        if(visited[step.point.x][step.point.y]){
            continue;
        }
        visited[step.point.x][step.point.y] = 1;
        int i;
        for(i = 0; i < 8; i++){
            Point next = nextPoint(step.point, i);
            if(isValidPoint(next)){
                pushHeap(makeStep(next, step.distance + map[next.x][next.y]));
            }
        }
    }
}

//

int main()
{
    scanf("%d %d", &mapSize.height, &mapSize.width);
    int x, y;
    for(y = 0; y < mapSize.height; y++){
        for(x = 0; x < mapSize.width; x++){
            int val;
            scanf("%d", &val);
            map[x][y] = val;
        }
    }

    Point seaPoint = getPointWithNegativeValue(0);

    fillAreaWithNumber(seaPoint, SEA1);
    fillAreaWithNumber(getPointWithNegativeValue(SEA1), SEA2);

    /*
    printf("\n");
    for(y = 0; y < mapSize.height; y++){
        for(x = 0; x < mapSize.width; x++){
            printf("%2d ", map[x][y]);
        }
        printf("\n");
    }
    */

    /*
    printf("\n");
    for(y = 0; y < mapSize.height; y++){
        for(x = 0; x < mapSize.width; x++){
            printf("%4d ", sea[x][y]);
        }
        printf("\n");
    }
    */

    search(makeStep(seaPoint, 0));

    printf("%d\n", min);
    return 0;
}
