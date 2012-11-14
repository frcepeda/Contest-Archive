#include <stdio.h>
#include <stdlib.h>

#define MAXN 100010

typedef struct {
	int l, r, id;
} segment;

int intCmp(int a, int b){
	if (a > b)
		return 1;
	if (b > a)
		return -1;
	return 0;
}

int segCmp(const void *a, const void *b){
	int ret;
	if ((ret = intCmp(((segment *)a)->l, ((segment *)b)->l)))
		return ret;
	if ((ret = intCmp(((segment *)a)->r, ((segment *)b)->r)))
		return ret;
	return 0;
}

segment segments[MAXN];
int N;

int main(void){
	int i, best, minl = 1<<30, maxr = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		scanf("%d %d", &segments[i].l, &segments[i].r);
		segments[i].id = i;
		if (segments[i].r > maxr)
			maxr = segments[i].r;
		if (segments[i].l < minl)
			minl = segments[i].l;
	}

	qsort(segments+1, N, sizeof(segment), segCmp);

	for (i = 1; i <= N; i++){
		if (segments[i].l != minl)
			break;
		if (segments[i].r == maxr){
			printf("%d\n", segments[i].id);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}
