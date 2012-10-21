#include <stdio.h>
#include <stdlib.h>

#define isValidPoint(point) point.x >= 0 && point.x < mapSize.width && point.y >= 0 && point.y < mapSize.height
#define nextPoint(point, i) makePoint(point.x + movs[i].x, point.y + movs[i].y)
#define pointInMap(point) map[point.x][point.y]
#define pointEqualsPoint(a, b) a.x == b.x && a.y == b.y
#define printPoint(point) printf("%d, %d\n", point.x, point.y)
#define visited(point) visited[point.x][point.y]

typedef struct {
    int x, y;
} Point;

Point makePoint(int x, int y){
    Point point = {x, y};
    return point;
}

typedef struct {
    int width, height;
} Size;

Size makeSize(int width, int height){
    Size size = {width, height};
    return size;
}

typedef struct {
    Point point;
    int distance;
} Step;

Step makeStep(Point point, int distance){
    Step step = {point, distance};
    return step;
}

#define INST_MAX 50000

Point queue[INST_MAX];
int qs, qe;

void push(Point step){
    //printf("%d : %d\n", qs, qe);
    queue[qe++] = step;
}

Point pop(){
    //printf("%d : %d\n", qs, qe);
    return queue[qs++];
}

int queueIsNotEmpty(){
    return qs < qe;
}

void resetQueue(){
    qs = qe = 0;
}

/* // 4 movs
#define MOVCOUNT 4
Point movs[MOVCOUNT] = {{0,1}, {0, -1}, {1,0}, {-1, 0}};
*/

// 8 movs
#define MOVCOUNT 8
Point movs[MOVCOUNT] = {{0,1}, {0, -1}, {1,0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

#define MAXWIDTH 70
#define MAXHEIGHT 100

int map[MAXWIDTH][MAXHEIGHT];
int visited[MAXWIDTH][MAXHEIGHT];
Size mapSize;

void printMap(){
    int x, y;
    printf("\n");
    for(y = 0; y < MAXHEIGHT; y++){
        for(x = 0; x < MAXWIDTH; x++){
            printf("%d ", map[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d %d", &mapSize.height, &mapSize.width);

    int x, y;
    for(y = 0; y < mapSize.height; y++){
        for(x = 0; x < mapSize.width; x++){
            scanf("%d", &map[x][y]);
        }
    }

    for(x = 0; x < mapSize.width; x++){
        for(y = 0; y < mapSize.height; y++){
            resetQueue();
            Point start = makePoint(x, y);
            push(start);
            int temp = pointInMap(start);
            while(queueIsNotEmpty()){
                Point step = pop();
                if(visited(step)){
                    continue;
                }
                visited(step) = 1;
                int i;
                for(i = 0; i < MOVCOUNT; i++){
                    Point next = nextPoint(step, i);
                    if(isValidPoint(next) && visited(next) == 0 && pointInMap(next) <= pointInMap(step)){
                        push(next);
                    }
                }
                pointInMap(step) = 0;
            }
            //printf("%d\n", qe);
            pointInMap(start) = temp;
        }
    }

    //printMap();

    int answer = 0;

    for(x = 0; x < mapSize.width; x++){
        for(y = 0; y < mapSize.height; y++){
            if(map[x][y])
                answer++;
        }
    }

    printf("%d\n", answer);

    return 0;
}
