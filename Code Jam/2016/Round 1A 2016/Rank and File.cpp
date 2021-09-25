#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int T, t, N, m;
int g[100][100];
vector<int> w[100];

bool dfs(int i, int k);

bool go(int i, int k, bool ns){
	for (int j = 0; j < N; j++){
		if (j < i && (g[i][j] != -1 && g[i][j] != w[k][j]))
			return false;
		else if (i > 0 && g[i-1][j] >= w[k][j])
			return false;
		g[i][j] = w[k][j];
	}

	if (ns) return dfs(i+1, k+1);

	for (int j = 0; j < N; j++){
		if (j <= i && (g[j][i] != -1 && g[j][i] != w[k+1][j]))
			return false;
		else if (i > 0 && g[j][i-1] >= w[k+1][j])
			return false;
		g[j][i] = w[k+1][j];
	}

	return dfs(i+1, k+2);
}

bool dfs(int i, int k){
	if (i == N){
		printf("Case #%d:", t);
		for (int i = 0; i < N; i++)
			printf(" %d", g[i][m]);
		printf("\n");
		return true;
	}

	sort(w + k, w + 2*N-1, [&](const vector<int> &a, const vector<int> &b){
		return a[i] < b[i];
	});

	bool ns = k+1 >= 2*N-1 || w[k][i] != w[k+1][i];
	if (ns) m = i;

	int tmp[100][100];
	for (int z = 0; z < N; z++){
		tmp[i][z] = g[i][z];
		tmp[z][i] = g[z][i];
	}
	if (go(i, k, ns)) return true;
	for (int z = 0; z < N; z++){
		g[i][z] = tmp[i][z];
		g[z][i] = tmp[z][i];
	}

	if (!ns){
		swap(w[k], w[k+1]);
	for (int z = 0; z < N; z++){
		tmp[i][z] = g[i][z];
		tmp[z][i] = g[z][i];
	}
	if (go(i, k, ns)) return true;
	for (int z = 0; z < N; z++){
		g[i][z] = tmp[i][z];
		g[z][i] = tmp[z][i];
	}
	}

	return false;
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d", &N);

		for (int i = 0; i < 2*N-1; i++){
			w[i].clear();
			for (int j = 0; j < N; j++){
				int k;
				scanf("%d", &k);
				w[i].push_back(k);
			}
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				g[i][j] = -1;

		assert(dfs(0, 0));
	}
}
