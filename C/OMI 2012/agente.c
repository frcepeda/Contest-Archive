#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOVS 4
#define MAXN 2010
#define MAXM 2010

#define isValidPoint(p) (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height)

typedef struct{
    int x, y;
} point;

point movs[MOVS] = {{0,1},{1,0},{0,-1},{-1,0}};

char map[MAXN][MAXM];
int width, height;
bool deleted[MAXN][MAXM];

int best;

typedef struct{
    point p;
    int next, last;
} list;

list todelete[5000000];
int nextList = 1;
int items;

int main(void){
    int i,j;

    scanf("%d %d", &height, &width);

    for (j = 0; j < height; j++){
        for (i = 0; i < width; i++){
            char tmp;
            do {
                tmp = getchar();
            } while (tmp != 'G' && tmp != '#' && tmp != '.');
            map[i][j] = tmp;
            if (tmp == 'G'){
                todelete[nextList].p.x = i;
                todelete[nextList].p.y = j;
                todelete[nextList].last = nextList - 1;
                todelete[todelete[nextList].last].next = nextList++;
                items++;
            }
        }
    }

    int loop = 0;
    while (items){
        int curr = todelete[0].next;
        loop++;
        while (curr != 0){
            point p = todelete[curr].p;
            for (i = 0; i < MOVS; i++){
                point next = {p.x + movs[i].x, p.y + movs[i].y};
                if (isValidPoint(next) && !deleted[next.x][next.y] && map[next.x][next.y] != '#' && map[next.x][next.y] != 'G'){
                    deleted[next.x][next.y] = true;
                    todelete[nextList].p.x = next.x;
                    todelete[nextList].p.y = next.y;
                    todelete[nextList].last = 0;
                    todelete[nextList].next = todelete[todelete[nextList].last].next;
                    todelete[todelete[nextList].next].last = nextList;
                    todelete[todelete[nextList].last].next = nextList++;
                    items++;
                    best = loop;
                }
            }
            todelete[todelete[curr].last].next = todelete[curr].next;
            todelete[todelete[curr].next].last = todelete[curr].last;
            items--;
            curr = todelete[curr].next;
        }
    }

    printf("%d\n", best);

    return 0;
}
