#include <cstdio>
#include <algorithm>

using namespace std;

int T, S;

const int maxs = 255;

bool m[maxs][maxs], n[maxs][maxs], v[maxs][maxs];

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int dfs(int i, int j, bool write = false){
	if (i < 0 || j < 0 || i >= S || j >= S) return 0;
	if (!m[i][j] || v[i][j]) return 0;

	if (write) n[i][j] = true;
	v[i][j] = true;

	int ret = 1;

	for (int k = 0; k < 4; k++){
		int nr = i + dr[k];
		int nc = j + dc[k];

		ret += dfs(nr, nc, write);
	}

	return ret;
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d", &S);

		for (int i = 0; i < S; i++){
			char tmp[maxs];
			scanf("%s", tmp);
			for (int j = 0; j < S; j++){
				m[i][j] = tmp[j] == 'X';
				n[i][j] = v[i][j] = false;
			}
		}

		for (int i = 0; i < S; i++)
			for (int j = 0; j < S; j++)
				if (m[i][j]) {
					int size = dfs(i, j);
					fprintf(stderr, "%d\n", size);
					if (size > 10) dfs(i, j, true);
				}

		printf("%d\n", S);
		for (int i = 0; i < S; i++){
			for (int j = 0; j < S; j++)
				printf("%d", int(n[i][j] ^ n[0][0]));
			printf("\n");
		}
	}
}
