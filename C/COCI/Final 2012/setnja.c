#include <stdio.h>

#define MAXMAP 200+5
#define MAXFRIENDS MAXMAP
#define MAXHEAP 5000000
#define BIGNUM (1<<30)

#define isValidFriend(f) (f.x >= 0 && f.x < MAXMAP && f.y >= 0 && f.y < MAXMAP)

int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}

typedef struct {
	int x, y;
} point;

typedef struct {
	int x, y, p;
} friend;

friend makeFriend(int x, int y, int p){
	friend fr = {x,y,p};
	return fr;
}

friend heap[MAXHEAP];
int nextHeap;

#define queueIsNotEmpty (nextHeap)
#define parent(a) (((a)-1)/2)
#define childA(a) ((a)*2+1)
#define childB(a) ((a)*2+2)

void push(friend s){
	int curr = nextHeap++;

	while (curr){
		if (heap[parent(curr)].p > s.p){
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	heap[curr] = s;
}

friend pop(void){
	friend ret = heap[0];
	int saved = --nextHeap;
	int curr = 0;

	while (childA(curr) < nextHeap){
		int swapchild;

		if (childB(curr) >= nextHeap || heap[childA(curr)].p < heap[childB(curr)].p)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);

		if (heap[swapchild].p < heap[saved].p){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}

	heap[curr] = heap[saved];

	return ret;
}

#define MAXDIR 8
point dir[MAXDIR] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0},
	{1,1},
	{-1,-1},
	{-1,1},
	{1,-1}
};

friend friends[MAXFRIENDS];
int friendNum;

int cost[MAXFRIENDS][MAXMAP][MAXMAP];
int visited[MAXFRIENDS][MAXMAP][MAXMAP];
int width, height;
int answer = BIGNUM;

void doStuff(void){
	int i,j,k;

	for (i = 0; i < friendNum; i++){
		nextHeap = 0;

		for (j = max(0, friends[i].x - friends[i].p); j <= min(200, friends[i].x + friends[i].p); j++)
			for (k = max(0, friends[i].y - friends[i].p); k <= min(200, friends[i].y + friends[i].p); k++)
				push(makeFriend(j,k, i > 0 ? cost[i-1][j][k]: 0));

		while (queueIsNotEmpty){
			friend curr = pop();
			for (j = 0; j < MAXDIR; j++){
				friend next = makeFriend(curr.x+dir[i].x, curr.y+dir[i].y, curr.p+1);
				if (isValidFriend(next)){
					if (next.p >= cost[i][next.x][next.y]) continue;
					cost[i][next.x][next.y] = next.p;
					push(next);
				}
			}
		}
	}
}

int main(void){
	int i,j,k;

	scanf("%d", &friendNum);

	for (i = 0; i < MAXMAP; i++)
		for (j = 0; j < MAXMAP; j++)
			for (k = 0; k < MAXMAP; k++)
				cost[i][j][k] = BIGNUM;

	for (i = 0; i < friendNum; i++)
		scanf("%d %d %d", &friends[i].x, &friends[i].y, &friends[i].p);

	doStuff();

	const int last = friendNum - 1;
	for (i = max(0, friends[last].x - friends[last].p); i <= min(MAXMAP, friends[last].x + friends[last].p); i++)
		for (j = max(0, friends[last].y - friends[last].p); j <= min(MAXMAP, friends[last].y + friends[last].p); j++)
			answer = min(answer, cost[last-1][i][j]);

	printf("%d\n", answer);

	return 0;
}

