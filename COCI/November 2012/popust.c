#include <stdio.h>
#include <stdbool.h>

#define MAXN 500010
#define MAXHEAP MAXN*2+10000

int min(int a, int b){
	return a < b ? a : b;
}

typedef struct {
	int id, A, B;
} meal;

int N;
int A[MAXN], B[MAXN];

bool inUse[MAXN];

long long int answer;

meal Aheap[MAXHEAP], Bheap[MAXHEAP];
int nextHeapA, nextHeapB;
#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

meal peekA(void){
	return Aheap[0];
}

void pushA(meal m){
	int curr = nextHeapA++;

	while (curr){
		if (m.A < Aheap[parent(curr)].A){
			Aheap[curr] = Aheap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	Aheap[curr] = m;
}

meal popA(void){
	meal ret = Aheap[0];
	int curr = 0;
	int save = --nextHeapA;

	while (childA(curr) < nextHeapA){
		int swapchild;

		if (childB(curr) >= nextHeapA || Aheap[childA(curr)].A < Aheap[childB(curr)].A)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);

		if (Aheap[swapchild].A < Aheap[save].A){
			Aheap[curr] = Aheap[swapchild];
			curr = swapchild;
		} else break;
	}

	Aheap[curr] = Aheap[save];

	return ret;
}

meal peekB(void){
	return Bheap[0];
}

void pushB(meal m){
	int curr = nextHeapB++;

	while (curr){
		if (m.B < Bheap[parent(curr)].B){
			Bheap[curr] = Bheap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	Bheap[curr] = m;
}

meal popB(void){
	meal ret = Bheap[0];
	int curr = 0;
	int save = --nextHeapB;

	while (childA(curr) < nextHeapB){
		int swapchild;

		if (childB(curr) >= nextHeapB || Bheap[childA(curr)].B < Bheap[childB(curr)].B)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);

		if (Bheap[swapchild].B < Bheap[save].B){
			Bheap[curr] = Bheap[swapchild];
			curr = swapchild;
		} else break;
	}

	Bheap[curr] = Bheap[save];

	return ret;
}

int main(void){
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d %d", &A[i], &B[i]);
		meal tmp = {.id = i, .A = A[i], .B = B[i]};
		pushA(tmp);
		pushB(tmp);
	}

	meal currA = popA();
	inUse[currA.id] = true;
	answer = currA.A;

	printf("%lld\n", answer);

	for (i = 2; i <= N; i++){
		meal takeA;
		meal takeB;

		while (inUse[peekA().id])
			popA();
		takeA = peekA();

		while (inUse[peekB().id])
			popB();
		takeB = peekB();

		if (-currA.A + takeA.A + min(currA.B, takeB.B) < takeB.B){
			answer += -currA.A + takeA.A + min(currA.B, takeB.B);

			popA();
			pushA(currA);
			pushB(currA);

			inUse[currA.id] = false;
			inUse[popB().id] = true;
			inUse[takeA.id] = true;

			currA = takeA;
		} else {
			answer += popB().B;
			inUse[takeB.id] = true;
		}

		printf("%lld\n", answer);
	}

	return 0;
}

