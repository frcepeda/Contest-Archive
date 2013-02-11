#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 50010
#define INF (1<<30)

typedef struct {
	int x, y;
} point;

int pointCmpByX(const void *ap, const void *bp){
	const point *a = (const point *)ap;
	const point *b = (const point *)bp;
	if (a->x == b->x)
		return a->y - b->y;
	return a->x - b->x;
}

int pointCmpByY(const void *ap, const void *bp){
	const point *a = (const point *)ap;
	const point *b = (const point *)bp;
	if (a->y == b->y)
		return a->x - b->x;
	return a->y - b->y;
}

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

#define DIRS 4
int xDiff[DIRS] = {0, 1, 0, -1};
int yDiff[DIRS] = {1, 0, -1, 0};

int N;
int answer;

point pointsByX[MAXN], pointsByY[MAXN];
int accum[MAXN];
int minX = INF, minY = INF, maxX, maxY;

bool betweenPointsX(point q){
	int lo = 0, hi = N, mid, c;

	while (lo < hi){
		mid = (lo + hi) / 2;
		c = pointCmpByX(&q, &pointsByX[mid]);

		if (c < 0)
			hi = mid;
		else
			lo = mid + 1;
	}

	return pointsByX[hi-1].x == q.x && pointsByX[hi].x == q.x;
}

bool betweenPointsY(point q){
	int lo = 0, hi = N, mid, c;

	while (lo < hi){
		mid = (lo + hi) / 2;
		c = pointCmpByY(&q, &pointsByY[mid]);

		if (c < 0)
			hi = mid;
		else
			lo = mid + 1;
	}

	return pointsByY[hi-1].y == q.y && pointsByY[hi].y == q.y;
}

bool inPolygon(point q){
	if (q.x < minX || q.y < minY || q.x > maxX || q.y > maxY)
		return false;
	return betweenPointsX(q) && betweenPointsY(q);
}

int main(void){
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);

	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d %d", &pointsByX[i].x, &pointsByX[i].y);
		pointsByY[i].x = pointsByX[i].x;
		pointsByY[i].y = pointsByX[i].y;

		minX = min(minX, pointsByX[i].x);
		minY = min(minY, pointsByX[i].y);
		maxX = max(maxX, pointsByX[i].x);
		maxY = max(maxY, pointsByX[i].y);
	}

	qsort(pointsByX, N, sizeof(point), pointCmpByX);
	qsort(pointsByY, N, sizeof(point), pointCmpByY);

	for (i = 0; i < N; i++){
		for (j = 0; j < DIRS; j++){
			point curr = {pointsByX[i].x + xDiff[j], pointsByX[i].y + yDiff[j]};

			if (bsearch(&curr, pointsByX, N, sizeof(point), pointCmpByX) == NULL && !inPolygon(curr))
				answer++;
		}
	}

	printf("%d\n", answer);

	return 0;
}
