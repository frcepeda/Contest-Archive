#include <stdio.h>
#include <stdlib.h>

#define isValidPoint(point) point.x >= 0 && point.x < mapSize.width && point.y >= 0 && point.y < mapSize.height
#define nextPoint(point, i) makePoint(point.x + movs[i].x, point.y + movs[i].y)
#define pointInMap(point) map[point.x][point.y]
#define pointEqualsPoint(a, b) a.x == b.x && a.y == b.y
#define printPoint(point) printf("%d, %d\n", mapToCoord(point.x), mapToCoord(point.y))

typedef struct {
    short x, y;
} Point;

Point makePoint(int x, int y){
    Point point = {x, y};
    return point;
}

typedef struct {
    short width, height;
} Size;

Size makeSize(int width, int height){
    Size size = {width, height};
    return size;
}

typedef struct {
    Point point;
    short distance;
} Step;

Step makeStep(Point point, int distance){
    Step step = {point, distance};
    return step;
}

#define INST_MAX 2160000

Step queue[INST_MAX];
int qs, qe;

void push(Step step){
    //printf("%d : %d\n", qs, qe);
    queue[qe++] = step;
}

Step pop(){
    //printf("%d : %d\n", qs, qe);
    return queue[qs++];
}

int queueIsNotEmpty(){
    return qs < qe;
}

void resetQueue(){
    qs = qe = 0;
}

// 4 movs
#define MOVCOUNT 4
Point movs[MOVCOUNT] = {{0,1}, {0, -1}, {1,0}, {-1, 0}};

/* // 8 movs
#define MOVCOUNT 8
Point mov[MOVCOUNT] = {{0,1}, {0, -1}, {1,0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
*/

#define MAXWIDTH 1001
#define MAXHEIGHT 1001

#define MAPOFFSET -500
#define coordToMap(coord) coord - MAPOFFSET
#define mapToCoord(map) map + MAPOFFSET

short map[MAXWIDTH][MAXHEIGHT];
Size mapSize = {MAXWIDTH, MAXHEIGHT};

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

// -----

Point start = {coordToMap(0), coordToMap(0)};
Point end;

int main()
{
    int num, answer = 0;
    scanf("%d %d %d", &end.x, &end.y, &num);
    end.x = coordToMap(end.x);
    end.y = coordToMap(end.y);
    int i;
    for(i = 0; i < num; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        map[coordToMap(x)][coordToMap(y)] = 1;
    }

    Step startStep = makeStep(start, 0);
    push(startStep);

    while(queueIsNotEmpty()){
        Step step = pop();
        if(pointEqualsPoint(step.point, end)){
            answer = step.distance;
            break;
        }
        if(pointInMap(step.point) == 1){
            continue;
        }
        pointInMap(step.point) = 1;
        //printPoint(step.point);
        int i;
        for(i = 0; i < MOVCOUNT; i++){
            Point nextPoint = nextPoint(step.point, i);
            if(isValidPoint(nextPoint) && pointInMap(nextPoint) == 0){
                Step nextStep = makeStep(nextPoint, step.distance + 1);
                push(nextStep);
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
