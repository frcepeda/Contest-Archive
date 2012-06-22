#include <stdio.h>

#define MAXNUM 1000010
#define MAXSTACK MAXNUM + 50000
#define magic(i) ((i) == cycleSize ? 0 : ((i) == -1 ? cycleSize-1 : (i)))

long long int max(long long int a, long long int b){
	return a > b ? a : b;
}

typedef struct {
	int node, cost;
} _input;

typedef struct {
	int node, cost, next;
} node;

typedef struct {
	int node, parent, cost, next;
} _stack;

typedef struct {
	int node, parent;
	long long int cost;
} _queue;

_input input[MAXNUM];

node graph[MAXNUM*2];
int nextNode = 1;
int start[MAXNUM];

long long int answer;

enum {
	notVisited,
	inProgress,
	alreadyVisited
} visited[MAXNUM];

int nodeNum;

long long int best[MAXNUM];
int cycle[MAXNUM];
long long int sum[MAXNUM];
int cycleSize;

long long int bestSoFar;

_stack stack[MAXSTACK];
int nextStack;
#define pushStack(a) stack[nextStack++] = (a)
#define popStack() stack[--nextStack]
#define peekStack() stack[nextStack-1]
#define topOfStack stack[nextStack-1]
#define stackIsNotEmpty nextStack

_queue queue[MAXSTACK];
int qs, qe;
#define queueIsNotEmpty qs < qe
#define pop() queue[qs++]

void findCycle(int s){
	int i;

	nextStack = 0;
	stack[nextStack].node = s;
	stack[nextStack].parent = -1;
	stack[nextStack].cost = 0;
	stack[nextStack].next = start[s];
	nextStack++;

	while (stackIsNotEmpty){
		_stack curr = peekStack();

		visited[curr.node] = inProgress;

		if (curr.next){
			i = topOfStack.next;
			topOfStack.next = graph[i].next;

			if (graph[i].node == curr.parent || visited[graph[i].node] == alreadyVisited)
				continue;

			stack[nextStack].parent = curr.node;
			stack[nextStack].node = graph[i].node;
			stack[nextStack].cost = graph[i].cost;
			stack[nextStack].next = start[graph[i].node];

			if (visited[stack[nextStack].node] == inProgress){
				cycle[0] = stack[nextStack].node;
				sum[0] = stack[nextStack].cost;

				cycleSize = 1;
				for (i = nextStack - 1; stack[i].node != stack[nextStack].node; i--, cycleSize++){
					cycle[cycleSize] = stack[i].node;
					sum[cycleSize] = sum[cycleSize-1] + stack[i].cost;
				}
				
				continue;
			}

			nextStack++;
		} else {
			visited[curr.node] = alreadyVisited;

			/* check for cycle of 2 nodes */
			if (curr.node == input[input[curr.node].node].node){
				cycleSize = 2;

				cycle[0] = curr.node;
				cycle[1] = input[curr.node].node;

				sum[0] = input[cycle[0]].cost;
				sum[1] = input[cycle[1]].cost + sum[0];
			}

			nextStack--;
		}
	}
}

void bfs(void){
	int i, j;

	qs = qe = 0;

	for (i = 0; i < cycleSize; i++){
		for (j = start[cycle[i]]; j; j = graph[j].next){
			if (graph[j].node == cycle[magic(i-1)] || graph[j].node == cycle[magic(i+1)])
				continue;

			queue[qe].node = graph[j].node;
			queue[qe].cost = graph[j].cost;
			queue[qe].parent = cycle[i];
			qe++;
		}
	}

	while (queueIsNotEmpty){
		_queue curr = pop();

		for (i = start[curr.node]; i; i = graph[i].next){
			if (graph[i].node == curr.parent)
				continue;

			queue[qe].node = graph[i].node;
			queue[qe].cost = graph[i].cost;
			queue[qe].parent = curr.node;
			qe++;
		}
	}
}

void getLongestDistances(void){
	int i;

	for (i = qe-1; i >= 0; i--){
		bestSoFar = max(bestSoFar, best[queue[i].parent] + best[queue[i].node] + queue[i].cost);

		best[queue[i].parent] = max(best[queue[i].parent], best[queue[i].node] + queue[i].cost);
	}
}

long long int sweep(void){
	long long int right = 0, left = 0;
	long long int lastRight, lastLeft;
	int i;

	lastLeft = lastRight = best[cycle[0]];

	right = best[cycle[1]] + sum[0] + lastRight;
	lastRight = max(lastRight, best[cycle[1]] - sum[0]);

	left = best[cycle[1]] - sum[0] + lastLeft;
	lastLeft = max(lastLeft, best[cycle[1]] + sum[0]);

	for (i = 2; i < cycleSize; i++){
		right = max(right, lastRight + sum[i-1] + best[cycle[i]]);
		lastRight = max(lastRight, best[cycle[i]] - sum[i-1]);

		left = max(left, lastLeft - sum[i-1] + best[cycle[i]]);
		lastLeft = max(lastLeft, best[cycle[i]] + sum[i-1]);
	}

	return max(right, sum[cycleSize-1] + left);
}

void doStuff(int node){
	bestSoFar = 0;

	findCycle(node);
	bfs();
	getLongestDistances();
	answer += max(bestSoFar, sweep());
}

int main(void){
	int i;

	scanf("%d", &nodeNum);

	for (i = 1; i <= nodeNum; i++){
		scanf("%d %d", &input[i].node, &input[i].cost);

		graph[nextNode].next = start[i];
		graph[nextNode].node = input[i].node;
		graph[nextNode].cost = input[i].cost;
		start[i] = nextNode++;

		graph[nextNode].next = start[input[i].node];
		graph[nextNode].node = i;
		graph[nextNode].cost = input[i].cost;
		start[input[i].node] = nextNode++;
	}

	for (i = 1; i <= nodeNum; i++)
		if (!visited[i])
			doStuff(i);

	printf("%lld\n", answer);

	return 0;
}

