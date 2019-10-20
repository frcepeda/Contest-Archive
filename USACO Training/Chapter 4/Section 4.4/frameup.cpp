/*
    ID: frceped1
    LANG: C++
    TASK: frameup
 */

#include <algorithm>
#include <cstdio>

using namespace std;

#if false
	#define openFiles()
#else
	#define openFiles() freopen("frameup.in", "r", stdin); freopen("frameup.out", "w", stdout)
#endif

#define fst first
#define snd second
#define mp make_pair

const int MAXH = 33;
const int MAXK = 27;
int K, W, H;
char target[MAXH][MAXH];
char p[MAXK];

bool edge[MAXH][MAXH];

int r[MAXK], R[MAXK], c[MAXK], C[MAXK];

void draw(){
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			target[i][j] = '.';

	for (int k = 0; k < K; k++){
		int x = p[k] - 'A';
		for (int i = r[x]; i <= R[x]; i++)
			target[i][c[x]] = target[i][C[x]] = p[k];
		for (int j = c[x]; j <= C[x]; j++)
			target[r[x]][j] = target[R[x]][j] = p[k];
	}
}

int deg[MAXK];
bool used[MAXK];
char ans[MAXK];

void go(int idx){
	if (idx == K){
		printf("%s\n", ans);
		return;
	}

	for (int xx = 0; xx < K; xx++){
		int x = p[xx] - 'A';
		if (!used[x] && !deg[x]){
			used[x] = true;

			for (int i = 0; i < MAXK; i++)
				deg[i] -= edge[x][i];

			ans[idx] = p[xx];
			go(idx + 1);

			for (int i = 0; i < MAXK; i++)
				deg[i] += edge[x][i];

			used[x] = false;
		}
	}
}

int main(){
	openFiles();

	for (int i = 0; i < MAXK; i++)
		r[i] = c[i] = 100;

	scanf("%d %d", &H, &W);

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++){
			scanf(" %c", &target[i][j]);

			if (target[i][j] == '.') continue;

			int idx = target[i][j] - 'A';

			if (r[idx] > H)
				p[K++] = target[i][j];

			r[idx] = min(r[idx], i);
			c[idx] = min(c[idx], j);
			R[idx] = max(R[idx], i);
			C[idx] = max(C[idx], j);
		}

	sort(p, p + K);

	for (int k = 0; k < K; k++){
		int x = p[k] - 'A';
		for (int i = r[x]; i <= R[x]; i++)
			edge[x][target[i][c[x]] - 'A'] = edge[x][target[i][C[x]] - 'A'] = true;
		for (int j = c[x]; j <= C[x]; j++)
			edge[x][target[r[x]][j] - 'A'] = edge[x][target[R[x]][j] - 'A'] = true;
	}

	for (int k = 0; k < K; k++)
		edge[p[k] - 'A'][p[k] - 'A'] = false;

	for (int k = 0; k < MAXK; k++)
		for (int i = 0; i < MAXK; i++)
			deg[k] += edge[i][k];

	go(0);
}
