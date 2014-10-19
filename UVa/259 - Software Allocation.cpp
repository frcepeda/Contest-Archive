#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 15
#define MAXA 15
#define MAXB 15
#define A n
#define B 10
#define INF (1<<29)

int n;
int pair_A[MAXN], pair_B[MAXN];
bool adj[MAXN][MAXN];
char prog[MAXN];

#define NIL 12

int queue[MAXN];
int qs, qe;
#define resetQueue() qs = qe = 0
#define queueNotEmpty (qs < qe)
#define push(x) queue[qe++] = x
#define pop() queue[qs++]

int dist[MAXA];

bool matching_BFS(){
	resetQueue();

	for (int i = 0; i < A; i++){
		if (pair_A[i] == NIL){
			dist[i] = 0;
			push(i);
		} else {
			dist[i] = INF;
		}
	}

	dist[NIL] = INF;

	while (queueNotEmpty){
		int curr = pop();
		if (dist[curr] < dist[NIL])
			for (int i = 0; i < B; i++)
				if (adj[curr][i] && dist[pair_B[i]] == INF){
					dist[pair_B[i]] = dist[curr] + 1;
					push(pair_B[i]);
				}
	}

	return dist[NIL] < INF;
}

bool matching_DFS(int x){
	if (x == NIL) return true;

	for (int i = 0; i < B; i++)
		if (adj[x][i] && dist[pair_B[i]] == dist[x] + 1 && matching_DFS(pair_B[i])){
			pair_B[i] = x;
			pair_A[x] = i;
			return true;
		}

	dist[x] = INF;
	return false;
}

int matching(void){
	int size = 0;

	fill(pair_A, pair_A + MAXA, NIL);
	fill(pair_B, pair_B + MAXB, NIL);

	while (matching_BFS())
		for (int i = 0; i < A; i++)
			if (pair_A[i] == NIL && matching_DFS(i))
				size++;

	return size;
}

char inp[1000];

int main(){
	int i, j;

	prog[NIL] = '_';

	while (true){
		bool ded = false;
		n = 0;

		for (i = 0; i < MAXN; i++)
			fill(adj[i], adj[i] + MAXN, false);

		while (gets(inp) != NULL && strlen(inp) > 2){
			if (n + inp[1] - '0' > 10) ded = true;

			if (!ded){
				for (i = n; i < n + inp[1] - '0'; i++)
					prog[i] = inp[0];

				for (i = 3; inp[i] != ';'; i++)
					for (j = n; j < n + inp[1] - '0'; j++)
						adj[j][inp[i] - '0'] = true;
			}

			n += inp[1] - '0';
		}

		if (n == 0) break;

		if (!ded && matching() == n){
			for (i = 0; i < 10; i++)
				putchar(prog[pair_B[i]]);
			putchar('\n');
		} else printf("!\n");
	}
}
