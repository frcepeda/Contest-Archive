#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 2250000
#define MAXK 21

#define parent(a) (a/2)
#define childA(a) (a*2)
#define childB(a) (a*2+1)

int max(int a, int b){
	return a > b ? a : b;
}

int N = 1, K, H;

int tree[MAXN];

bool visited[MAXN][MAXK];
int memo[MAXN][MAXK];
int f(int node, int remaining, int level){
	assert(remaining >= 1);
	if (visited[node][remaining])
		return memo[node][remaining];
	visited[node][remaining] = true;

	int answer = tree[node];
	int i;

	if (level < H){
		for (i = 1; i < remaining; i++){
			answer = max(answer, f(childA(node), i, level+1) + f(childB(node), remaining - i, level+1));
		}
	}

	return memo[node][remaining] = answer;
}

void read(int levels, int where){
	if (levels < 0)
		return;

	scanf("%d", &tree[where]);

	read(levels-1, childA(where));
	read(levels-1, childB(where));
}

int main(void) {
	scanf("%d %d", &H, &K);

	read(H, 1);

	printf("%d\n", f(1, K, 0));

	return 0;
}
