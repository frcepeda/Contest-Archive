/*
    ID: frceped1
    LANG: C
    TASK: rect1
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("rect1.in", "r", stdin); freopen("rect1.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXRECTS 500000
#define MAXCOLORS 2501

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

typedef struct {
	int xs, ys, xe, ye, color;
	bool deleted;
} rect;

rect makeRect(int xs, int ys, int xe, int ye, int color){
	rect r = {xs, ys, xe, ye, color};
	return r;
}

rect rects[MAXRECTS];
int rectCount;

#define area(r) ((r.xe-r.xs)*(r.ye-r.ys))
#define intersectQ(a,b) (a.xe > b.xs && b.xe > a.xs && a.ye > b.ys && b.ye > a.ys)

int count[MAXCOLORS];

int N, A, B;

void breakRect(rect a, rect rem){
	if (a.xs < rem.xs)
		rects[rectCount++] = makeRect(a.xs, a.ys, rem.xs, a.ye, a.color);
	if (a.ys < rem.ys)
		rects[rectCount++] = makeRect(max(a.xs, rem.xs), a.ys, min(a.xe, rem.xe), rem.ys, a.color);
	if (a.xe > rem.xe)
		rects[rectCount++] = makeRect(rem.xe, a.ys, a.xe, a.ye, a.color);
	if (a.ye > rem.ye)
		rects[rectCount++] = makeRect(max(a.xs, rem.xs), rem.ye, min(a.xe, rem.xe), a.ye, a.color);
}

void addRect(rect r){
	int i;

	for (i = rectCount-1; i >= 0; i--){
		if (!rects[i].deleted && intersectQ(rects[i], r)){
			rects[i].deleted = true;
			breakRect(rects[i], r);
		}
	}

	rects[rectCount++] = r;
}

int main(void){
	openFiles();
	
	int i;

	scanf("%d %d %d", &A, &B, &N);

	rect tmp = {0, 0, A, B, 1};
	addRect(tmp);

	for (i = 0; i < N; i++, rectCount++){
		scanf("%d %d %d %d %d", &tmp.xs, &tmp.ys, &tmp.xe, &tmp.ye, &tmp.color);
		addRect(tmp);
	}

	for (i = 0; i < rectCount; i++)
		if (!rects[i].deleted)
			count[rects[i].color] += area(rects[i]);

	for (i = 1; i < MAXCOLORS; i++)
		if (count[i])
			printf("%d %d\n", i, count[i]);

	return 0;
}
