#include <stdio.h>

#define MAXWIDTH 10000+1
#define MAXHEIGHT 1000+1

unsigned long long int BIT[MAXWIDTH][MAXHEIGHT];
int width, height;
int wtf;

typedef union {
    struct {
        int x, y, val;
    } description; 
    struct {
        int x, y, x2, y2;
    } square;
} Temp;

void update(int x, int y, int v);
void update(int x, int y, int v){
    int y1;
	while (x <= width){
		y1 = y;
		while (y1 <= height){
			BIT[x][y1] += v;
			y1 += (y1 & -y1); 
		}
		x += (x & -x); 
	}
}

unsigned long long int read(int x, int y);
unsigned long long int read(int x, int y){
    unsigned long long int ret = 0;
    int y1;
	while (x > 0){
        y1 = y;
        while (y1 > 0) {
            ret += BIT[x][y1];
            y1 -= (y1 & -y1);
        }
		x -= (x & -x);
	}
	return ret;
}

void answer(int x, int y, int x2, int y2);
void answer(int x, int y, int x2, int y2){
    printf("%llu\n", read(x2,y2) - read(x2,y-1) - read(x-1,y2) + read(x-1,y-1));
    fflush(stdout);
}

int main(int argc, const char * argv[])
{
    int tasks;
    scanf("%d %d", &width, &height);
    scanf("%d", &tasks);
    Temp temp;
    while (tasks--) {
        char task;
        scanf("%*[ \t\r\n]%c", &task);
        switch (task) {
            case 'D':
                scanf("%d %d %d", &temp.description.x, &temp.description.y, &temp.description.val);
                update(temp.description.x, temp.description.y, temp.description.val);
                break;
            case 'C':
                scanf("%d %d %d %d", &temp.square.x, &temp.square.y, &temp.square.x2, &temp.square.y2);
                answer(temp.square.x, temp.square.y, temp.square.x2, temp.square.y2);
                break;
        }
    }
    return 0;
}

