#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

#define MAXMAP (50000+5)
#define SQUARE 16
#define MAXSQUARES 7500000

typedef struct {
	int y, next;
} node;

node squares[MAXSQUARES];
int next = 1;
int height, length;
int start[MAXMAP];
int last[MAXMAP];
int squareCount;

int overlap(int a, int b){
	return abs(a - b) < 16;
}

int test(int x, int y){
	int curr = start[x];
	while (curr){
		node n = squares[curr];
		if (overlap(n.y, y)) return 0;
		curr = n.next;
	}
	return 1;
}

void add(int x, int y){
	if (!start[x]){
		start[x] = next;
	} else {
		squares[last[x]].next = next;
	}
	last[x] = next;
	squares[next++].y = y;
}


int main(void){
	int i, j;
	int answer = 0;

	scanf("%d %d %d", &length, &height, &squareCount);

	for (i = 0; i < squareCount; i++){
		int x, y;
		scanf("%d %d", &x, &y);

		int can = 1;
		for (j = max(0, x-SQUARE+1); j < min(length, x+SQUARE); j++){
			if (!test(j, y)){
				can = 0;
				break;
			}
		}

		if (can){
			answer++;
			add(x,y);
		}
	}

	printf("%d\n", answer);

	return 0;
}

