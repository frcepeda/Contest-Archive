#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 300;
int A, B;

const int maxa = maxn, maxb = maxn;
bool adj[maxa][maxb];
int pairA[maxa], pairB[maxb];
const int NIL = maxn-1;

namespace matching {
	const int INF = 1<<29;

	int queue[maxa];
	int qs, qe;

	int dist[maxa];

	bool bfs(){
		qs = qe = 0;
		
		for (int i = 0; i < A; i++){
			if (pairA[i] == NIL){
				dist[i] = 0;
				queue[qe++] = i;
			} else dist[i] = INF;
		}

		dist[NIL] = INF;

		while (qs < qe){
			int curr = queue[qs++];
			if (dist[curr] < dist[NIL])
				for (int i = 0; i < B; i++)
					if (adj[curr][i] && dist[pairB[i]] == INF){
						dist[pairB[i]] = dist[curr] + 1;
						queue[qe++] = pairB[i];
					}
		}

		return dist[NIL] < INF;
	}

	bool dfs(int x){
		if (x == NIL) return true;

		for (int i = 0; i < B; i++)
			if (adj[x][i] && dist[pairB[i]] == dist[x] + 1 &&
			    dfs(pairB[i])){
				pairB[i] = x;
				pairA[x] = i;
				return true;
			}

		dist[x] = INF;
		return false;
	}

	int matching(){
		int size = 0;

		fill(pairA, pairA + maxa, NIL);
		fill(pairB, pairB + maxb, NIL);

		while (bfs())
			for (int i = 0; i < A; i++)
				if (pairA[i] == NIL && dfs(i))
					size++;

		return size;
	}
}

int main(){
	scanf("%d", &B);
	char s[maxn];
	scanf("%s", s);
	A = strlen(s);

	for (int j = 0; j < B; j++){
		char t[10];
		scanf("%s", t);

		for (int i = 0; i < A; i++)
			for (int k = 0; t[k] != '\0'; k++)
				adj[i][j] |= t[k] == s[i];
	}

	if (matching::matching() == A){
		printf("YES\n");
		for (int i = 0; i < A; i++)
			printf("%d\n", pairA[i]+1);
	} else printf("NO\n");
}
