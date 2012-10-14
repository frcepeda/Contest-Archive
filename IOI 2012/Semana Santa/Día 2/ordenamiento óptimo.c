#include <stdio.h>

#define MAXHEAP 2600000
#define MAXSIZE 10
#define MAXPERM 4000000

int cost[MAXSIZE][MAXSIZE];
int visited[MAXPERM];

typedef struct {
	char perm[MAXSIZE];
	int cost;
} step;

step makeTempStep(int i){
	step s = {.cost = i};
	return s;
}

step heap[MAXHEAP];
int nextHeap;

#define heapIsNotEmpty nextHeap
#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

void push(step s){
	int curr = nextHeap++;
	while (curr){
		if (s.cost < heap[parent(curr)].cost){
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}
	heap[curr] = s;
}

step pop(void){
	step ret = heap[0];
	int curr = 0;
	int saved = --nextHeap;
	while (childA(curr) < nextHeap){
		int swapchild;
		if (childB(curr) >= nextHeap || heap[childA(curr)].cost < heap[childB(curr)].cost)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);
		if (heap[swapchild].cost < heap[saved].cost){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}
	heap[curr] = heap[saved];
	return ret;
}

int fact(int num){
	int i;
	int ans = 1;
	for (i = 2; i <= num; i++)
		ans *= i;
	return ans;
}

int length;

int permToInt(char *perm){
	int used[MAXSIZE+1] = {0};
	int i, j;
	int total = 0;
	for (i = 0; i < length; i++){
		int num = 0;
		for (j = perm[i] - 1; j > 0; j--)
			if (!used[j]) num++;
		total += num * fact(length-i-1);
		used[perm[i]] = 1;
	}
	return total;
}

void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

int search(void){
	int i,j;

	while(heapIsNotEmpty){
		step curr = pop();
		int permNum = permToInt(curr.perm);

		if (permNum == 0) return curr.cost;

		for (i = 0; i < length; i++){
			for (j = i+1; j < length; j++){
				swap(&curr.perm[i], &curr.perm[j]);
				curr.cost += cost[i][j];
				int next = permToInt(curr.perm);
				if (!visited[next] || visited[next] > curr.cost){
					push(curr);
					visited[next] = curr.cost;
				}
				swap(&curr.perm[i], &curr.perm[j]);
				curr.cost -= cost[i][j];
			}
		}
	}
}

int main(void){
	int i,j;
	step start = {.cost = 0};

	scanf("%d", &length);

	for (i = 0; i < length; i++)
		scanf("%d", (int *)&start.perm[i]);

	for (i = 0; i < length; i++){
		for (j = 0; j < i; j++){
			scanf("%d", &cost[i][j]);
			cost[j][i] = cost[i][j];
		}
	}

	push(start);

	printf("%d\n", search());

	return 0;
}

