/*
    ID: frceped1
    LANG: C
    TASK: packrec
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("packrec.in", "r", stdin); freopen("packrec.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

int max(int num, int a, int b, ...){
	int ret = a > b ? a : b;
	num -= 2;
	va_list list;
	va_start(list, b);
	while (num--){
		int next = va_arg(list, int);
		if (next > ret) ret = next;
	}
	return ret;
}

#define RECTNUM 4
#define ORDERINGS 6

#define swap(a,b) int _temp = a; a = b; b = _temp

typedef struct {
	int x, y;
} rectangle;

int rectCmp(const void *a, const void *b){
	rectangle ar = *(rectangle *)a;
	rectangle br = *(rectangle *)b;
	if (ar.x > br.x) return 1;
	else if (ar.x < br.y) return -1;
	else if (ar.y > br.y) return 1;
	else if (ar.y < br.y) return -1;
	else return 0;
}

rectangle rectangles[RECTNUM];

int permutation[RECTNUM] = {0,1,2,3};

void reverse(int start, int end){
	while (start < end){
		swap(permutation[start], permutation[end]);
		start++, end--;
	}
}

int nextPermutation(void){
	int i, j;
	
	static unsigned char first = 1;
	if (first){
		first = 0;
		return 1;
	}

	for (i = RECTNUM - 2; i >= 0; i--){
		if (permutation[i] < permutation[i+1]){
			for (j = RECTNUM - 1; j > i; j--){
				if (permutation[i] < permutation[j]){
					swap(permutation[i], permutation[j]);
					reverse(i+1, RECTNUM - 1);
					return 1;
				}
			}
		}
	}
	return 0;
}

rectangle best[20];
int next;
int minArea = 1<<20;

void add(int width, int height){
	int area = width * height;

	if (area > minArea) return;

	if (width > height) {
		swap(width, height);
	}

	rectangle r = {width, height};

	if (area == minArea){ // Add to answer list
		int i;
		for (i = 0; i < next; i++)
			if (r.x == best[i].x && r.y == best[i].y)
				return;
		best[next++] = r;
	} else { // New best area
		minArea = area;
		best[0] = r;
		next = 1;
	}
}


void makeRectangle(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy){
	int width, height;

	//Ordering 1
	width = ax + bx + cx + dx;
	height = max(4, ay, by, cy, dy);
	add(width,height);

	//Ordering 2
	width = max(2, ax + bx + cx, dx);
	height = dy + max(3, ay, by, cy);
	add(width, height);

	//Ordering 3
	width = max(2, ax + bx, dx) + cx;
	height = max(2, max(2,ay,by) + dy, cy);
	add(width, height);

	//Ordering 4
	width = ax + cx + max(2, bx, dx);
	height = max(3, ay, cy, by + dy);
	add(width, height);

	//Ordering 5
	width = max(2, ax, dx) + bx + cx;
	height = max(3, ay + dy, by, cy);
	add(width, height);

	//Ordering 6
	width = max(3, ax + bx, bx + cx, cx + dx);
	height = max(3, ay + cy, ay + dy, by + dy);
	add(width, height);

}

void try(rectangle a, rectangle b, rectangle c, rectangle d){
	makeRectangle(a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y);
	makeRectangle(a.x,a.y,b.x,b.y,c.x,c.y,d.y,d.x);
	makeRectangle(a.x,a.y,b.x,b.y,c.y,c.x,d.x,d.y);
	makeRectangle(a.x,a.y,b.x,b.y,c.y,c.x,d.y,d.x);

	makeRectangle(a.x,a.y,b.y,b.x,c.x,c.y,d.x,d.y);
	makeRectangle(a.x,a.y,b.y,b.x,c.x,c.y,d.y,d.x);
	makeRectangle(a.x,a.y,b.y,b.x,c.y,c.x,d.x,d.y);
	makeRectangle(a.x,a.y,b.y,b.x,c.y,c.x,d.y,d.x);

	makeRectangle(a.y,a.x,b.x,b.y,c.x,c.y,d.x,d.y);
	makeRectangle(a.y,a.x,b.x,b.y,c.x,c.y,d.y,d.x);
	makeRectangle(a.y,a.x,b.x,b.y,c.y,c.x,d.x,d.y);
	makeRectangle(a.y,a.x,b.x,b.y,c.y,c.x,d.y,d.x);

	makeRectangle(a.y,a.x,b.y,b.x,c.x,c.y,d.x,d.y);
	makeRectangle(a.y,a.x,b.y,b.x,c.x,c.y,d.y,d.x);
	makeRectangle(a.y,a.x,b.y,b.x,c.y,c.x,d.x,d.y);
	makeRectangle(a.y,a.x,b.y,b.x,c.y,c.x,d.y,d.x);
}

int main(void){
	openFiles();
	int i;

	for (i = 0; i < RECTNUM; i++)
		scanf("%d %d", &rectangles[i].x, &rectangles[i].y);

	while (nextPermutation()){
		try(rectangles[permutation[0]],
			rectangles[permutation[1]],
			rectangles[permutation[2]],
			rectangles[permutation[3]]);
	}

	qsort(best, next, sizeof(rectangle), rectCmp);

	printf("%d\n", minArea);
	for (i = 0; i < next; i++)
		printf("%d %d\n", best[i].x, best[i].y);

	return 0;
}
