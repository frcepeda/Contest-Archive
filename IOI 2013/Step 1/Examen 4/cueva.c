#include <stdio.h>
#include <stdbool.h>

#define MAXN 2000010 

typedef struct {
	int id, next;
} node;

typedef struct {
	int id, parent;
	bool firstTime;
} _stack;

int start[MAXN];
node nodes[MAXN];
int nextNode = 1;

int preorderID[MAXN];
int rangeStart[MAXN];
int rangeEnd[MAXN];

_stack stack[MAXN];
int nextStack;

#define push(a) stack[nextStack++] = (a)
#define pop(a) (stack[--nextStack])
#define stackIsNotEmpty (nextStack)

#define addEdge(a,b) nodes[nextNode].next = start[a]; nodes[nextNode].id = b; start[a] = nextNode++

int N, Q;

void preorder(void){
	int nextID = 0, i;
        _stack curr = {.id = 1, .parent = -1, .firstTime = true}, next;

	push(curr);

	while (stackIsNotEmpty){
		curr = pop();

		if (curr.firstTime){
			curr.firstTime = false;
			push(curr);

			preorderID[curr.id] = nextID;
			rangeStart[nextID] = nextID++;

			next.parent = curr.id;
			next.firstTime = true;
			for (i = start[curr.id]; i; i = nodes[i].next){
				if (nodes[i].id == curr.parent) continue;
				next.id = nodes[i].id;
				push(next);
			}
		} else {
			rangeEnd[preorderID[curr.id]] = nextID-1;
		}
	}
}

int main(void){
	int i, a, b;

	scanf("%d %d", &N, &Q);

	for (i = 1; i < N; i++){
		scanf("%d %d", &a, &b);
		addEdge(a,b);
		addEdge(b,a);
	}

	preorder();

	while (Q--){
		scanf("%d %d", &a, &b);
		printf("%d\n", !(rangeStart[preorderID[a]] <= preorderID[b] && rangeEnd[preorderID[a]] >= preorderID[b]));
	}

	return 0;
}

