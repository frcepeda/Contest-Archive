#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 250009

typedef struct {
	int parent, children, next;
} node;

typedef struct {
	int node, dist;
} dfsstack;

#define stackIsNotEmpty (nextStack)
#define push(a) stack[nextStack++] = (a)
#define pop() stack[--nextStack]
#define peek() stack[nextStack-1]
#define discard() (nextStack--)

node tree[MAXN];
int N, M;

int minupdated = (1<<30);

int distance[MAXN];
bool deleted[MAXN];

void dfs(void){
	int i;
	static dfsstack stack[MAXN];
	static int nextStack;

	dfsstack curr = {.node = 1, .dist = 0}, next;
	push(curr);

	while (stackIsNotEmpty){
		curr = pop();
		distance[curr.node] = curr.dist;

		next.dist = curr.dist + 1;
		for (i = tree[curr.node].children; i != 0; i = tree[i].next){
			next.node = i;
			push(next);
		}
	}
}

bool cached[MAXN];
int cache[MAXN];
int up(int node){
	static int stack[MAXN];
	static int nextStack;
	int count = -1, curr;

	nextStack = 0;
	push(node);

	while (stackIsNotEmpty){
		curr = peek();

		if (curr == 1){
			count = 0;
			discard();
		} else if (cached[curr] && curr < minupdated){
			count = cache[curr];
			discard();
		} else if (count == -1){
			push(tree[curr].parent);
		} else {
			count += deleted[curr];
			cache[curr] = count;
			cached[curr] = true;
			discard();
		}
	}

	return count;
}

int query(int node){
	return distance[node] - up(node);
}

void highway(int a, int b){
	if (minupdated > b)
		minupdated = b;
	deleted[b] = true;
}

int main(void){
	int i;

	scanf("%d", &N);

	for (i = 1; i < N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b){
			int t = a;
			a = b;
			b = t;
		}
		tree[b].parent = a;
		if (tree[a].children){
			tree[b].next = tree[a].children;
		}
		tree[a].children = b;
	}

	/*for (i = 1 ; i <= N; i++){
		int curr = tree[i].children;
		for (; curr != 0; curr = tree[curr].next)
			printf("%d -> %d\n", i, curr);
	}// */

	dfs();

	scanf("%d", &M);

	char q;
	int a, b;
	for (i = 1; i < M+N; i++){
		do {
			q = getchar();
		} while (q != 'W' && q != 'A');

		switch (q){
			case 'W':
				scanf("%d", &a);
				printf("%d\n", query(a));
				break;
			case 'A':
				scanf("%d %d", &a, &b);
				highway(a, b);
				break;
		}
	}

	return 0;
}
