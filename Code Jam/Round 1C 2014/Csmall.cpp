#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, M, K;
bool grid[25][25];
bool vis[25][25];
int mem[25][25];

int dfs(int i, int j){
	if (i < 0 || i >= N || j < 0 || j >= M) return 0;

	if (vis[i][j]) return mem[i][j];
	vis[i][j] = true;
	mem[i][j] = 1;

	if (grid[i][j]) return mem[i][j] = 1;

	return mem[i][j] = (dfs(i-1,j) && dfs(i+1,j) && dfs(i,j-1) && dfs(i,j+1));
}

bool check(int bits){
	int i, j, enc = 0;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++){
			grid[i][j] = !!(bits & (1<<(i*M + j)));
			vis[i][j] = false;
		}

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (dfs(i,j))
				enc++;

	return enc >= K;
}

int main(){
	int t, i;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int minimum = 9871293;

		scanf("%d %d %d", &N, &M, &K);

		for (i = 0; i < (1<<(N*M)); i++)
			if (__builtin_popcount(i) < minimum && check(i))
				minimum = __builtin_popcount(i);

		printf("Case #%d: %d\n", t, minimum);
	}
}
