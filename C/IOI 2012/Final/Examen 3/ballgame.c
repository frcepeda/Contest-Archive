#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXN 1009
#define MAXMOVES 5000

typedef enum { l, r } direction;

typedef struct {
	direction dir;
	int value, index;
} heap_;

heap_ makeHeapNode(direction d, int value, int index){
	heap_ h = {.dir = d, .value = value, .index = index};
	return h;
}

int turns, score;

int N, W, B;

int coins[MAXN];
int left[MAXN];
int right[MAXN];

heap_ heap[MAXMOVES];
int nextHeap;

#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)
#define heapIsNotEmpty (nextHeap)

int heapIndex[2][MAXN];

void heapGoDown(int curr){
	heap_ save = heap[curr];
	int swapChild;

	while (childA(curr) < nextHeap){
		if (childB(curr) >= nextHeap || heap[childA(curr)].value > heap[childB(curr)].value)
			swapChild = childA(curr);
		else
			swapChild = childB(curr);

		if (heap[swapChild].value > save.value){
			heapIndex[heap[swapChild].dir == l][heap[swapChild].index] = curr;
			heap[curr] = heap[swapChild];
			curr = swapChild;
		} else break;
	}

	heap[curr] = save;
	heapIndex[save.dir == l][save.index] = curr;
}

void heapGoUp(int curr){
	heap_ save = heap[curr];

	while (curr){
		if (heap[parent(curr)].value < save.value){
			heapIndex[heap[parent(curr)].dir == l][heap[parent(curr)].index] = curr;
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	heap[curr] = save;
	heapIndex[save.dir == l][save.index] = curr;
}

void push(heap_ h){
	int curr = nextHeap++;

	while (curr){
		if (heap[parent(curr)].value < h.value){
			heapIndex[heap[parent(curr)].dir == l][heap[parent(curr)].index] = curr;
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	heap[curr] = h;
	heapIndex[h.dir == l][h.index] = curr;
}

heap_ pop(void){
	heap_ ret = heap[0];
	int save = --nextHeap;
	int curr = 0;
	int swapChild;

	while (childA(curr) < nextHeap){
		if (childB(curr) >= nextHeap || heap[childA(curr)].value > heap[childB(curr)].value)
			swapChild = childA(curr);
		else
			swapChild = childB(curr);

		if (heap[swapChild].value > heap[save].value){
			heapIndex[heap[swapChild].dir == l][heap[swapChild].index] = curr;
			heap[curr] = heap[swapChild];
			curr = swapChild;
		} else break;
	}

	heap[curr] = heap[save];
	heapIndex[heap[save].dir == l][heap[save].index] = curr;

	return ret;
}

void setToZero(int i, int step, int arr){
	for (; i >= 0 && i < N; i += step){
		/*//printf("%d : %d. Zeroing out.\n", i+1, heap[heapIndex[arr][i]].value);*/
		int previous = heap[heapIndex[arr][i]].value;
		heap[heapIndex[arr][i]].value = 0;
		if (previous > 0)
			heapGoDown(heapIndex[arr][i]);
		else
			heapGoUp(heapIndex[arr][i]);
	}
}

void subtract(int i, int step, int howMuch, int arr){
	for (; i >= 0 && i < N; i += step){
		/*//printf("%d : %d. Subtracting %d\n", i+1, heap[heapIndex[arr][i]].value, howMuch);*/
		heap[heapIndex[arr][i]].value -= howMuch;
		heapGoDown(heapIndex[arr][i]);
	}
}

void repeat(int i, int step, int arr){
	int val = 0;
	if (i - step < N && i - step >= 0)
		val = heap[heapIndex[arr][i-step]].value;
	for (; i >= 0 && i < N; i += step){
		/*//printf("%d : %d. Changing to %d\n", i+1, heap[heapIndex[arr][i]].value, val);*/
		int previous = heap[heapIndex[arr][i]].value;
		heap[heapIndex[arr][i]].value = val;
		if (previous > val)
			heapGoDown(heapIndex[arr][i]);
		else
			heapGoUp(heapIndex[arr][i]);
	}
}

int main(void){
	int i, j;

	scanf("%d %d %d", &W, &B, &N);

	for (i = 0; i < N; i++){
		scanf("%d", &coins[i]);

		for (j = i; j >= 0; j -= W)
			right[j] += coins[i];

		for (j = i; j < N; j += W)
			left[j] += coins[i];
	}

	for (i = 0; i < N; i++){
		push(makeHeapNode(r, right[i], i));
		push(makeHeapNode(l, left[i], i));
	}

	while (B-- && heapIsNotEmpty){
		heap_ bestPlay = pop();

		if (bestPlay.value <= 0)
			break;

		heap_ pushcopy = bestPlay;
		pushcopy.value = 0;
		push(pushcopy);

		score += bestPlay.value;
		turns++;

		/*//printf("+++ Playing on %d to the %s +++\n", bestPlay.index+1, bestPlay.dir == l ? "left" : "right");*/

		switch (bestPlay.dir){
			case r:
				setToZero(bestPlay.index + W, W, 0);
				subtract(bestPlay.index - W, -W, bestPlay.value, 0);
				repeat(bestPlay.index, W, 1);
				break;
			case l:
				setToZero(bestPlay.index - W, -W, 1);
				subtract(bestPlay.index + W, W, bestPlay.value, 1);
				repeat(bestPlay.index, -W, 0);
				break;
		}
	}

	printf("%d %d\n", score, turns);

	return 0;
}
