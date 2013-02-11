#include <stdio.h>

#define MAXN 10010
#define MAXM 50010

typedef struct {
	int cow, next;
} list;

typedef struct {
	int cow, time;
} cowTime;

int max(int a, int b){
	return a > b ? a : b;
}

int time[MAXN];

int start[MAXN];
list constraints[MAXM];
int nextConstraint = 1;

int before[MAXN];

int maxTime;

int N, M;

cowTime heap[MAXN];
int nextHeap;

#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)
#define heapIsNotEmpty (nextHeap)

void push(cowTime c){
	int curr = nextHeap++;

	while (curr){
		if (heap[parent(curr)].time > c.time){
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	heap[curr] = c;
}

cowTime pop(void){
	cowTime ret = heap[0];
	int curr = 0;
	int save = --nextHeap;
	int swapchild;

	while (childA(curr) < nextHeap){
		if (childB(curr) >= nextHeap || heap[childA(curr)].time < heap[childB(curr)].time)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);

		if (heap[swapchild].time < heap[save].time){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}

	heap[curr] = heap[save];

	return ret;
}

int main(void){
	freopen("msched.in", "r", stdin);
	freopen("msched.out", "w", stdout);

	int i;
	cowTime curr, next;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
		scanf("%d", &time[i]);

	for (i = 0; i < M; i++){
		int A, B;
		scanf("%d %d", &A, &B);

		before[B]++;

		constraints[nextConstraint].cow = B;
		constraints[nextConstraint].next = start[A];
		start[A] = nextConstraint++;
	}

	for (i = 1; i <= N; i++){
		if (before[i] == 0){
			curr.cow = i;
			curr.time = time[curr.cow];
			maxTime = max(maxTime, curr.time);
			push(curr);
		}
	}

	while (heapIsNotEmpty){
		curr = pop();

		for (i = start[curr.cow]; i; i = constraints[i].next){
			if (--before[constraints[i].cow] == 0){
				next.cow = constraints[i].cow;
				next.time = curr.time + time[next.cow];
				maxTime = max(maxTime, next.time);
				push(next);
			}
		}
	}

	printf("%d\n", maxTime);

	return 0;
}
