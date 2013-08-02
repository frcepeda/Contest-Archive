#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x1, y1, x2, y2;
} square;

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int N;
square squares[5];

bool check(int a){
	int i;
	square now = squares[0];
	for (i = 1; i < N; i++){
		now.x1 = min(now.x1, squares[i].x1);
		now.y1 = min(now.y1, squares[i].y1);
		now.x2 = max(now.x2, squares[i].x2);
		now.y2 = max(now.y2, squares[i].y2);
	}
	return (now.x2 - now.x1) == (now.y2 - now.y1) && a == (now.x2 - now.x1) * (now.y2 - now.y1);
}

int main(void){
	int i, j, area = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d %d %d %d", &squares[i].x1, &squares[i].y1, &squares[i].x2, &squares[i].y2);
		area += (squares[i].x2 - squares[i].x1) * (squares[i].y2 - squares[i].y1);
	}

	if (check(area))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
