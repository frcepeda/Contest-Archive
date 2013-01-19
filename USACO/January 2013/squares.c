#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTREE 100000
#define MAXN 50100
#define MAXLEVEL 5

typedef struct {
	int x, y;
} point;

point makePoint(int x, int y){
	point p = {x, y};
	return p;
}

typedef struct {
	point a, b;
} rect;

rect makeRect(point a, point b){
	rect r = {a,b};
	return r;
}

typedef struct _node{
	struct _node *NW, *NE, *SW, *SE;
	short count;
	point pts[MAXLEVEL];
	int rectIdx[MAXLEVEL];
	rect range;
} node;

bool rectContainsInclusive(rect r, point p){
	return r.a.x <= p.x && r.a.y <= p.y && r.b.x >= p.x && r.b.y >= p.y;
}

bool rectContainsExclusive(rect r, point p){
	return r.a.x < p.x && r.a.y < p.y && r.b.x > p.x && r.b.y > p.y;
}

node tree[MAXTREE];
int nextTree = 1;

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

node *makeNode(int a, int b, int c, int d){
	tree[nextTree].range.a.x = a;
	tree[nextTree].range.a.y = b;
	tree[nextTree].range.b.x = c;
	tree[nextTree].range.b.y = d;
	return &tree[nextTree++];
}

void subDivide(node *n){
	point center = {n->range.a.x + (n->range.b.x - n->range.a.x) / 2, n->range.a.y + (n->range.b.y - n->range.a.y) / 2};
	n->NW = makeNode(n->range.a.x, n->range.a.y, center.x, center.y);
	n->SW = makeNode(n->range.a.x, center.y + 1, center.x, n->range.b.y);
	n->NE = makeNode(center.x + 1, center.y + 1, n->range.b.x, n->range.b.y);
	n->SE = makeNode(center.x + 1, n->range.a.y, n->range.b.x, center.y);
}

node *root = &tree[0];

int N, K;

rect rects[MAXN];

void multipleIntersections(void){
	printf("-1\n");
	exit(0);
}

long long int rectOverlap(rect m, rect n){
	rect over = {{max(m.a.x, n.a.x), max(m.a.y, n.a.y)}, {min(m.b.x, n.b.x), min(m.b.y, n.b.y)}};

	if (over.a.x >= over.b.x || over.a.y >= over.b.y)
		return 0;
	else
		return ((long long int)(over.b.x - over.a.x)) * (over.b.y - over.a.y);
}

int queryRange(node *n, rect range){
	int i, idx = -1, ret;

	if (n == NULL || rectOverlap(n->range, range) == 0)
		return -1;

	for (i = 0; i < n->count; i++){
		if (rectContainsExclusive(range, n->pts[i])){
			if (idx == -1)
				idx = n->rectIdx[i];
			else if (idx != n->rectIdx[i])
				multipleIntersections();
		}
	}

	ret = queryRange(n->NW, range);

	if (idx == -1 && ret != -1)
		idx = ret;
	else if (idx != -1 && ret != -1 && ret != idx)
		multipleIntersections();

	ret = queryRange(n->NE, range);

	if (idx == -1 && ret != -1)
		idx = ret;
	else if (idx != -1 && ret != -1 && ret != idx)
		multipleIntersections();

	ret = queryRange(n->SW, range);

	if (idx == -1 && ret != -1)
		idx = ret;
	else if (idx != -1 && ret != -1 && ret != idx)
		multipleIntersections();

	ret = queryRange(n->SE, range);

	if (idx == -1 && ret != -1)
		idx = ret;
	else if (idx != -1 && ret != -1 && ret != idx)
		multipleIntersections();


	return idx;
}

void insertPt(node *n, point p, int idx){
	if (n == NULL || !rectContainsInclusive(n->range, p))
		return;

	if (n->count < MAXLEVEL){
		n->pts[n->count] = p;
		n->rectIdx[n->count] = idx;
		n->count++;
	} else {
		if (n->NW == NULL)
			subDivide(n);

		insertPt(n->NW, p, idx);
		insertPt(n->NE, p, idx);
		insertPt(n->SW, p, idx);
		insertPt(n->SE, p, idx);
	}
}

int main(void){
	int i;
	long long int answer = 0;

	freopen("squares.in", "r", stdin);
	freopen("squares.out", "w", stdout);

	scanf("%d %d", &N, &K);

	root->range = makeRect(makePoint(-1500010, -1500010), makePoint(1500010, 1500010));

	for (i = 0; i < N; i++){
		int x, y, overlap, index;
		scanf("%d %d", &x, &y);

		index = queryRange(root, makeRect(makePoint(x-K/2, y-K/2), makePoint(x+K/2, y+K/2)));

		insertPt(root, makePoint(x-K/2, y-K/2), i);
		insertPt(root, makePoint(x-K/2, y+K/2), i);
		insertPt(root, makePoint(x+K/2, y-K/2), i);
		insertPt(root, makePoint(x+K/2, y+K/2), i);

		rects[i] = makeRect(makePoint(x-K/2, y-K/2), makePoint(x+K/2, y+K/2));

		if (index != -1 && !answer)
			answer = rectOverlap(rects[index], rects[i]);
		else if (index != -1)
			multipleIntersections();
	}

	printf("%lld\n", answer);

	return 0;
}
