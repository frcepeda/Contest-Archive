#include <stdio.h>

#define MAXN 2000200

typedef struct {
	int node, next;
	unsigned cost;
} edge;

int N, M;
edge tree[MAXN];
int start[MAXN], nextNode = 1;
unsigned xor[MAXN];

void addEdge(unsigned a, unsigned b, unsigned c){
	tree[nextNode].node = b;
	tree[nextNode].cost = c;
	tree[nextNode].next = start[a];
	start[a] = nextNode++;
}

int f(int n, int p){
	int i;
	for (i = start[n]; i; i = tree[i].next){
		if (tree[i].node == p) continue;
		xor[tree[i].node] = xor[n] ^ tree[i].cost;
		f(tree[i].node, n);
	}
}

int main(void){
	int i;

	scanf("%d %d", &N, &M);
	for (i = 1; i < N; i++){
		unsigned int a, b, c;
		scanf("%u %u %u", &a, &b, &c);
		addEdge(a, b, c);
		addEdge(b, a, c);
	}

	f(1, 0);

	while (M--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%u\n", xor[a] ^ xor[b]);
	}

	return 0;
}
