/*
    ID: frceped1
    LANG: C
    TASK: humble
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("humble.in", "r", stdin); freopen("humble.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXK 110
#define MAXHEAP 2000000

unsigned int primes[MAXK];
int N, K;

unsigned int heap[MAXHEAP];
int nextHeap;

#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

void push(int a){
	int curr = nextHeap++;
	if (nextHeap >= MAXHEAP)
		nextHeap = MAXHEAP-1;
	while (curr){
		if (a < heap[parent(curr)]){
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}
	heap[curr] = a;
}

int pop(void){
	unsigned int ret = heap[0];
	int save = --nextHeap;
	int curr = 0;

	while (childA(curr) < nextHeap){
		int swapchild;
		if (childB(curr) >= nextHeap || heap[childA(curr)] < heap[childB(curr)])
			swapchild = childA(curr);
		else
			swapchild = childB(curr);
		if (heap[swapchild] < heap[save]){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}
	heap[curr] = heap[save];

	return ret;
}

int main(void){
	openFiles();

	unsigned int i, curr;

	scanf("%d %d", &K, &N);

	for (i = 0; i < K; i++){
		scanf("%u", &primes[i]);
		push(primes[i]);
	}

	int last = -1;
	while (N){
		curr = pop();
		if (curr == last) continue;
		for (i = 0; i < K; i++)
			if (curr <= UINT_MAX / primes[i])
				push(curr * primes[i]);
		last = curr;
		N--;
	}

	printf("%u\n", curr);

	return 0;
}
