#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 17
#define MAXK 6
#define pop __builtin_popcount
#define inv(x,u) ((~(x)) & u)

int t, T, N, K;
bool W[MAXN][MAXN];
int v[MAXN][1<<MAXN];
bool dp1[MAXN][1<<MAXN];
bool dp2[MAXK][MAXN][1<<MAXN];
bool dp3[MAXK][MAXN];

int placing(int p){
	if (p == K) return 1;
	return 1 + (1<<(K-p-1));
}

int lg(int z){
	int r;
	for (r = 0; z >= (1<<r); r++);
	return r;
}

bool f(int i, int m){
	if (v[i][m] == t)
		return dp1[i][m];

	v[i][m] = t;

	if (!(m & (1<<i))) return dp1[i][m] = false;
	if (m == (1<<i)) return dp1[i][m] = true;

	int two_k = pop(m);

	for (int w = 0; w < N; w++){
		if (!W[i][w]) continue;
		for (int j = m&-m; j; j = (j - m) & m){
			if (pop(j) != two_k / 2 || (j & (1<<w)) || !(j & (1<<i)))
				continue;
			if (f(i,j) && f(w, inv(j,m)))
				return dp1[i][m] = true;
		}
	}

	return dp1[i][m] = false;
}

int main(){
	cin >> T;

	for (t = 1; t <= T; t++){
		cout << "Case #" << t << ":\n";

		cin >> N;
		K = lg(N);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> W[i][j];

		for (int k = 1; k <= K; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < (1<<N); j++)
					dp2[k][i][j] = false;

		for (int i = 0; i < N; i++)
			for (int j = 1; j < (1<<N); j++){
				int k = pop(j);
				if (k & (k-1)) continue;
				if (f(i,j))
					dp2[lg(k)][i][j] = true;
			}

		for (int k = 1; k <= K; k++)
		for (int i = 0; i < N; i++)
		for (int j = 1; j < (1<<N); j++)
		if (dp2[k][i][j])
			for (int l = 0; l < N; l++)
				dp2[k][i][j|(1<<l)] = true;

		for (int i = 0; i < N; i++){
			for (int k = 1; k < K; k++){
				dp3[k][i] = false;

				for (int w = 0; w < N && !dp3[k][i]; w++)
					if (W[w][i])
						for (int j = 1; j < (1<<N) && !dp3[k][i]; j++)
							if (dp2[k][i][j] && dp2[k][w][inv(j,(1<<N)-1)])
								dp3[k][i] = true;
			}

			dp3[K][i] = f(i,(1<<N)-1);
		}

		for (int i = 0; i < N; i++){
			int l = 5, h = 0;
			for (int k = 1; k <= K; k++)
				if (dp3[k][i]){
					h = max(h, k);
					l = min(l, k);
				}
			cout << placing(h) << ' ' << placing(l) << endl;
		}
	}
}
