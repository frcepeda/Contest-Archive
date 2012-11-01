#include <stdio.h>
#include <stdbool.h>

#define MAXN 200020

typedef struct {
	int id, next, cost;
} node;

node tree[MAXN];
int start[MAXN];
int nextNode = 1;

#define addNode(a,b,c) tree[nextNode].id = b; tree[nextNode].cost = c; tree[nextNode].next = start[a]; start[a] = nextNode++

bool connected[MAXN];

int N, Q;
int count;

void add(int a){
	connected[a] = true;
	count++;
}

void removetree(int a){
	connected[a] = false;
	count--;
}

typedef struct {
	int acc, dist, node, parent;
	bool first;
} _stack;

_stack stack[MAXN];
int nextStack;

#define push(a) stack[nextStack++] = (a)
#define pop() (stack[--nextStack])
#define stackIsNotEmpty (nextStack)

int countLights(void){
	_stack curr, next = {.acc = 0, .first = true};
	int i;

	if (count <= 1)
		return 0;

	for (i = 1; i <= N; i++)
		if (connected[i])
			break;
	curr.node = i;
	curr.first = true;
	curr.dist = 0;
	curr.acc = 0;
	curr.parent = 200008;
	push(curr);

	while (stackIsNotEmpty){
		curr = pop();

		if (curr.first){
			curr.first = false;
			next.parent = nextStack;
			push(curr);
			for (i = start[curr.node]; i; i = tree[i].next){
				if (tree[i].id == stack[curr.parent].node) continue;
				next.node = tree[i].id;
				next.dist = tree[i].cost;
				push(next);
			}
		} else {
			stack[curr.parent].acc += connected[curr.node] || curr.acc ? curr.dist+curr.acc : 0;
		}
	}

	return stack[0].acc;
}

int main(void){
	int i, a, b, c;

	scanf("%d", &N);

	for (i = 1; i < N; i++){
		scanf("%d %d %d", &a, &b, &c);
		addNode(a,b,c);
		addNode(b,a,c);
	}

	scanf("%d", &Q);

	while (Q--){
		char type;
		do {
			type = getchar();
		} while (type != '+' && type != '-' && type != '?');
		
		switch (type){
			case '+':
				scanf("%d", &a);
				add(a);
				break;
			case '-':
				scanf("%d", &b);
				removetree(b);
				break;
			case '?':
				printf("%d\n", countLights());
				break;
		}
	}

	return 0;
}

