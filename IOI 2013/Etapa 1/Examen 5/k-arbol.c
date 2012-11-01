#include <stdio.h>
#include <stdbool.h>

#define MAXN 10010
#define MAXM 510

typedef struct {
	int id, next;
} node;

int start[MAXN];
node tree[MAXN];
int nextNode = 1;

#define addNode(a, b) tree[nextNode].id = b; tree[nextNode].next = start[a]; start[a] = nextNode++

bool possibleColors[MAXN][MAXM];
int possibleCount[MAXN];
int color[MAXN];

int N, M, C;

typedef struct {
	int node, next;
} _stack;

_stack stack[MAXN];
int nextStack;

#define push(a) stack[nextStack++] = a
#define pop() (stack[--nextStack])
#define stackIsNotEmpty (nextStack)

void removeInconsistent(int from, int to){
	int i;

	for (i = 0; i < M; i++){
		if (possibleColors[from][i] && possibleCount[to] <= !!possibleColors[to][i]){
			possibleColors[from][i] = false;
			possibleCount[from]--;
		}
	}
}

void removalPass(void){
	_stack curr = {0, -1}, next = {-1, -1};
	push(curr);

	while (stackIsNotEmpty){
		curr = pop();
		
		if (start[curr.node] == 0) continue;

		if (curr.next == -1){
			curr.next = start[curr.node];
			push(curr);
			next.node = tree[curr.next].id;
			push(next);
		} else {
			removeInconsistent(curr.node, tree[curr.next].id);
			curr.next = tree[curr.next].next;
			if (curr.next){
				push(curr);
				next.node = tree[curr.next].id;
				push(next);
			}
		}
	}
}

bool pickColors(void){
	int i;
	_stack curr = {0, 501}, next;
	push(curr);

	while (stackIsNotEmpty){
		curr = pop();

		if (possibleCount[curr.node] <= 0)
			return false;

		for (i = 0; i < M; i++){
			if (possibleColors[curr.node][i] && i != curr.next){
				color[curr.node] = i;
				next.next = i;
				break;
			}
		}

		for (i = start[curr.node]; i; i = tree[i].next){
			next.node = tree[i].id;
			push(next);
		}
	}

	return true;
}

int main(void){
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			possibleColors[i][j] = true;
		}
		possibleCount[i] = M;
	}

	for (i = 1; i < N; i++){
		int p;
		scanf("%d", &p);
		addNode(p, i);
	}

	scanf("%d", &C);

	while (C--){
		int n, cant;
		scanf("%d %d", &n, &cant);
		if (possibleColors[n][cant]){
			possibleColors[n][cant] = false;
			possibleCount[n]--;
		}
	}

	removalPass();

	if (pickColors()){
		for (i = 0; i < N; i++)
			printf("%d\n", color[i]);
	} else {
		printf("-1\n");
	}

	return 0;
}

