#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

const int L = 400, K = 200;
bool m[L][L];
int v[33];

bool vv[L][L][8][30];

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c, int d, int x){
	if (x == n || vv[r][c][d][x]) return;
	vv[r][c][d][x] = true;

	for (int i = 0; i < v[x]; i++){
		m[r][c] = true;
		r += dr[d];
		c += dc[d];
	}

	r -= dr[d];
	c -= dc[d];

	int da = (d+1) % 8;
	dfs(r + dr[da], c + dc[da], da, x+1);
	int db = (d+7) % 8;
	dfs(r + dr[db], c + dc[db], db, x+1);
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	dfs(K, K, 0, 0);
	
	int ans = 0;

	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			ans += m[i][j];

	printf("%d\n", ans);

	/*
	for (int i = 10; i >= -0; i--){
		for (int j = -10; j < 10; j++)
			putchar(m[i+K][j+K] ? '*' : ' ');
		putchar('\n');
	}
	*/
}
