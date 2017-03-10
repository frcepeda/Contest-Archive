#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;

#define MAXJ 5100

int J, B, C, N, S;
vector<pii> adj[MAXJ];
int X[MAXJ], Y[MAXJ], Z[MAXJ];

void dijkstra(int s, int *v){
	while (!q.empty()) q.pop();

	fill(v+1, v+1+J, 1<<30);
	v[s] = 0;
	q.push(mp(0,s));

	while (!q.empty()){
		int d, curr;
		tie(d, curr) = q.top(); q.pop();

		for (auto z: adj[curr])
			if (v[z.fst] > d + z.snd){
				v[z.fst] = d + z.snd;
				q.push(mp(v[z.fst], z.fst));
			}
	}
}

int main(){
	while (true){
		scanf("%d %d %d %d %d", &J, &B, &C, &N, &S);

		if (J == -1 && B == -1 && C == -1 && N == -1 && S == -1)
			break;

		for (int i = 1; i <= J; i++)
			adj[i].clear();

		for (int i = 0; i < S; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(mp(b,c));
			adj[b].push_back(mp(a,c));
		}

		dijkstra(B, X);
		dijkstra(C, Y);
		dijkstra(N, Z);

		int ans = 0;
		for (int i = 1; i <= J; i++)
			if (X[C] == X[i] + Y[i] &&
			    X[N] == X[i] + Z[i])
				ans = max(ans, X[i]);

		printf("%d %d %d\n", ans, X[C] - ans, X[N] - ans);
	}
}
