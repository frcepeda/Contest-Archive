#include <stdio.h>

#define MAXSIZE 30
#define MOVCOUNT 8
#define MAXMOVES 5000000

#define queueIsNotEmpty (qs % MAXMOVES) < (qe % MAXMOVES)
#define nextPoint(point, i) makePoint(point.x + movs[i].x, point.y + movs[i].y)
#define pointInBoard(point) board[point.x][point.y]
#define isValidPoint(point) point.x >= 0 && point.y >= 0 && point.x < size && point.y < size

typedef struct {
    int x, y;
} Point;

Point makePoint(int x, int y){
    Point point = {x, y};
    return point;
}

typedef struct {
    Point point;
    int time;
} Move;

Move makeMove(Point point, int time){
    Move move = {point, time};
    return move;
}

int size;
int board[MAXSIZE][MAXSIZE];
int possible[MAXSIZE][MAXSIZE];
Point movs[MOVCOUNT] = {{1,2}, {2,1}, {2,-1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

Move queue[MAXMOVES];
int qs, qe;

void push(Move mo){
    queue[qe++ % MAXMOVES] = mo;
}

Move pop(void){
    return queue[qs++ % MAXMOVES];
}

int seconds;

int main(void){
    scanf("%d %d", &size, &seconds);
    Move start;
    scanf("%d %d", &start.point.x, &start.point.y);
    start.point.x--;
    start.point.y--;
    start.time = 0;

    int x, y;

    for(x = 0; x < size; x++){
        for(y = 0; y < size; y++){
            scanf("%d", &board[x][y]);
        }
    }

    push(start);
    while(queueIsNotEmpty){
        Move step = pop();
        if(step.time == seconds){
            possible[step.point.x][step.point.y] = 1;
            continue;
        }
        int i;
        Move next = makeMove(step.point, step.time+1);
        for(i = 0; i < MOVCOUNT; i++){
            next.point = nextPoint(step.point, i);
            if(isValidPoint(next.point) && next.time % pointInBoard(next.point) == 0){
                push(next);
            }
        }
    }

    int count = 0;
    for(x = 0; x < size; x++){
        for(y = 0; y < size; y++){
            if(possible[x][y]) count++;
        }
    }
    printf("%d\n", count);
    for(x = 0; x < size; x++){
        for(y = 0; y < size; y++){
            if(possible[x][y]) printf("%d %d\n", x+1, y+1);
        }
    }

    return 0;
}
