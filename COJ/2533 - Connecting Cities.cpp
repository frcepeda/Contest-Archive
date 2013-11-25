// Accepted
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 2010
#define MAXM 50100

#define fst first
#define snd second

int T, N, M, C;

int _set[MAXN];
typedef pair< int, pair<int,int> > edge;
edge edges[MAXM];

int id(int x){
	if (_set[x] == x)
		return x;
	return _set[x] = id(_set[x]);
}

void join(int a, int b){
	_set[id(a)] = id(b);
}

int main(){
	int i;
	scanf("%d", &T);

	while (T--){
		scanf("%d %d %d", &N, &M, &C);

		for (i = 0; i < N; i++)
			_set[i] = i;

		for (i = 0; i < M; i++){
			scanf("%d %d %d", &edges[i].snd.fst, &edges[i].snd.snd, &edges[i].fst);
			edges[i].snd.fst--; edges[i].snd.snd--;
		}
		
		sort(edges, edges+M);

		long long ans = N * (long long)C;
		long long soFar = 0;
		int components = N;

		for (i = 0; i < M; i++){
			int a = id(edges[i].snd.fst);
			int b = id(edges[i].snd.snd);
			if (a != b){
				soFar += edges[i].fst;
				join(a,b);
				components--;
				ans = min(ans, soFar + components * C);
			}
		}

		if (components == 1)
			ans = min(ans, soFar);

		printf("%lld\n", ans);
	}
}
