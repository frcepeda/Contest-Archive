#include <stdio.h>
#include <stdlib.h>

#define isValidPoint(x,y) x > 0 && x <= width && y > 0 && y <= height
#define X point.x
#define Y point.y

typedef struct {
    int x, y, distance;
} Point;

int map[1001][1001];
int distance[1001][1001];
int visited[1001][1001];
Point queue[1000000];
int width, height;
int counter = 0, start = 0;

void push(Point point){
    queue[counter++ % 1000000] = point;
}

Point pop(){
    return queue[start++ % 1000000];
}

void search(int x, int y, int people){

    counter = start = 0;

    int i, j;

    for(i = 1; i <= width; i++){
        for(j = 1; j <= height; j++){
            visited[i][j] = 0;
        }
    }

    Point a = {x, y, 0};
    push(a);

    while(start < counter){
        Point point = pop();

        if((map[X][Y] && point.distance) || visited[X][Y])
            continue;

        distance[X][Y] += point.distance * people;

        Point temp = {0, 0, point.distance+1};
        visited[X][Y] = 1;

        if(isValidPoint(X+1, Y)){
            temp.x = X+1;
            temp.y = Y;
            push(temp);
        }

        if(isValidPoint(X-1, Y)){
            temp.x = X-1;
            temp.y = Y;
            push(temp);
        }

        if(isValidPoint(X, Y+1)){
            temp.x = X;
            temp.y = Y+1;
            push(temp);
        }

        if(isValidPoint(X, Y-1)){
            temp.x = X;
            temp.y = Y-1;
            push(temp);
        }
    }
}

int main(){
    int buildings;
    int river;

    scanf("%d %d", &width, &height);
    scanf("%d", &buildings);

    int i, j;

    for(i = 0; i < buildings; i++){
        int x, y, a;
        scanf("%d %d %d", &x, &y, &a);
        map[x][y] = a;
    }

    scanf("%d", &river);

    for(i = 0; i < river; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][y] = -1;
    }

    for(i = 1; i <= width; i++){
        for(j = 1; j <= height; j++){
            if (map[i][j] > 0){
                search(i, j, map[i][j]);
            }
        }
    }

    int minlength = distance[1][1];
    counter = 0;

    for(i = 1; i <= width; i++){
        for(j = 1; j <= height; j++){
            if (distance[i][j] > 0 && distance[i][j] < minlength){
                counter = 0;
                minlength = distance[i][j];
                Point point = {i, j, 0};
                queue[counter++] = point;
            } else if (distance[i][j] == minlength){
                Point point = {i, j, 0};
                queue[counter++] = point;
            }
        }
    }

    printf("%d\n", minlength);

    for(i = 0; i < counter; i++){
        Point point = queue[i];
        printf("%d %d\n", X, Y);
    }

    return 0;
}
