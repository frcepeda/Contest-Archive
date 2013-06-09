#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAXN 200010
#define MAXLG 20

typedef struct {
	int next, node;
} edge;

typedef struct {
	long long int first, second;
} pair;

typedef struct {
	int first, second;
} ipair;

int min(int a, int b){
	return a < b ? a : b;
}

int lg2(int a){
	int ans = -1;
	while (a){
		a >>= 1;
		ans++;
	}
	return ans;
}

long long int modMultInv(long long int x){
	long long int ret = 1;
	int exp = MOD - 2;

	while (exp){
		if (exp & 1)
			ret = (ret * x) % MOD;
		exp >>= 1;
		x = (x * x) % MOD;
	}

	return ret;
}

edge graph[MAXN*2];
int start[MAXN], nextEdge = 1;
int parent[MAXN];
bool color[MAXN];
int height[MAXN], maxHeight;

int minIdx[MAXLG][MAXN*2];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int visitedNode[MAXN*2], visitedHeight[MAXN*2], firstOccurrence[MAXN], nextSlot;

ipair stack[MAXN];
int sti;

#define push(a) stack[sti++] = (a)
#define pop() (stack[--sti])
#define peek() (stack[sti-1])

void search(void){
	stack[0].first = 1;
	stack[0].second = start[1];
	sti++;

	while (sti){
		ipair curr = peek();

		if (curr.second == start[curr.first])
			firstOccurrence[curr.first] = nextSlot;

		visitedNode[nextSlot] = curr.first;
		visitedHeight[nextSlot] = height[curr.first];

		nextSlot++;

		if (curr.second != 0){
			ipair next;
			next.first = graph[curr.second].node;
			next.second = start[next.first];
			stack[sti-1].second = graph[curr.second].next;

			if (next.first != parent[curr.first])
				push(next);
			else nextSlot--;
		} else pop();
	}
}

void precomputeLCA(void){
	int i, j;

	search();

	for (i = 0; i < nextSlot; i++)
		minIdx[0][i] = i;

	for (j = 1; j < MAXLG; j++){
		for (i = 0; i < nextSlot; i++){
			if (visitedHeight[minIdx[j-1][i]] < visitedHeight[minIdx[j-1][min(i + (1<<(j-1)),nextSlot-1)]])
				minIdx[j][i] = minIdx[j-1][i];
			else
				minIdx[j][i] = minIdx[j-1][min(i + (1<<(j-1)), nextSlot-1)];
		}
	}
}

int lca(int a, int b){
	int l;

	a = firstOccurrence[a];
	b = firstOccurrence[b];

	if (a > b){
		l = a;
		a = b;
		b = l;
	}

	l = lg2(b - a + 1);

	if (visitedHeight[minIdx[l][a]] < visitedHeight[minIdx[l][b - (1<<l) + 1]])
		return visitedNode[minIdx[l][a]];
	else
		return visitedNode[minIdx[l][b - (1<<l) + 1]];
}

long long int twoPower[MAXN];

int N, Q;

int down[MAXN]; // root is 2^0
int up[MAXN]; // root is 2^height

int query(int a, int b){
	if (a == b)
		return color[a];

	int LCA = lca(a,b);
	long long int goingDown = down[a] - down[parent[LCA]];
	long long int goingUp = up[b] - ((up[LCA] * twoPower[height[b] - height[LCA]]) % MOD);

	while (goingDown < 0)
		goingDown += MOD;
	goingDown %= MOD;

	while (goingUp < 0)
		goingUp += MOD;
	goingUp %= MOD;

	if (height[LCA] != 0)
		goingDown = (goingDown * modMultInv(twoPower[height[LCA]])) % MOD;

	if (height[b] - height[LCA] != 0)
		goingDown = (goingDown * twoPower[height[b] - height[LCA]]) % MOD;

	return (goingDown + goingUp) % MOD;
}

int main(void){
	int i;

	scanf("%d", &N);

	for (i = 2; i <= N; i++){
		int c;
		scanf("%d %d", &parent[i], &c);
		color[i] = !!c;
		height[i] = height[parent[i]] + 1;

		if (height[i] > maxHeight)
			maxHeight = height[i];

		addEdge(i,parent[i]);
		addEdge(parent[i],i);
	}

	twoPower[0] = 1;
	for (i = 1; i <= N; i++)
		twoPower[i] = (twoPower[i-1] * 2) % MOD;

	for (i = 2; i <= N; i++)
		down[i] = (down[parent[i]] + color[i] * twoPower[height[i]]) % MOD;

	for (i = 1; i <= N; i++)
		up[i] = (up[parent[i]] * 2 + color[i]) % MOD;

	precomputeLCA();

	scanf("%d", &Q);

	while (Q--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", query(a,b));
	}

	return 0;
}
