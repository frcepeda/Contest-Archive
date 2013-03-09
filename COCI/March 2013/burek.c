#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 100100
#define MAXCOORD 1000010

typedef struct {
	int i;
	bool open;
} mark;

int rangeCmp(const void *a, const void *b){
	if (((mark *)a)->i != ((mark *)b)->i)
		return ((mark *)a)->i - ((mark *)b)->i;
	else
		return ((mark *)a)->open ? 1 : -1;
}

mark xranges[MAXN*2], yranges[MAXCOORD];
int rCount;
int xoverlap[MAXCOORD], yoverlap[MAXCOORD];
int N, M;

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

void pass(int *overlap, mark *ranges){
	int i, r, count = 0;

	for (i = 0, r = 0; i < MAXCOORD; i++){
		for (; ranges[r].i == i && !ranges[r].open; r++)
			count--;

		overlap[i] = count;

		for (; ranges[r].i == i; r++)
			count++;
	}
}

int main(void){
	int i, j, x, y, n;
	char c;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		int lox = MAXCOORD, hix = 0;
		int loy = MAXCOORD, hiy = 0;
		for (j = 0; j < 3; j++){
			scanf("%d %d", &x, &y);
			lox = min(lox, x);
			hix = max(hix, x);
			loy = min(loy, y);
			hiy = max(hiy, y);
		}

		xranges[rCount].i = lox;
		xranges[rCount].open = true;
		yranges[rCount].i = loy;
		yranges[rCount].open = true;

		rCount++;

		xranges[rCount].i = hix;
		xranges[rCount].open = false;
		yranges[rCount].i = hiy;
		yranges[rCount].open = false;

		rCount++;
	}

	qsort(xranges, rCount, sizeof(xranges[0]), rangeCmp);
	qsort(yranges, rCount, sizeof(yranges[0]), rangeCmp);

	pass(xoverlap, xranges);
	pass(yoverlap, yranges);

	scanf("%d", &M);

	for (i = 0; i < M; i++){
		do
			c = getchar();
		while (c != 'x' && c != 'y');

		scanf(" = %d", &n);

		if (c == 'x')
			printf("%d\n", xoverlap[n]);
		else
			printf("%d\n", yoverlap[n]);
	}

	return 0;
}
