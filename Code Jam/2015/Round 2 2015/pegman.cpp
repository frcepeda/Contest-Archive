#include <cstdio>

using namespace std;

int T, R, C;
char m[110][110];
int v[110][110];

bool points(int i, int j){
	int x;

	if (m[i][j] == '.')
		return true;
	if (m[i][j] == '<')
		for (x = j-1; x >= 0; x--)
			if (m[i][x] != '.')
				return true;
	if (m[i][j] == '>')
		for (x = j+1; x < C; x++)
			if (m[i][x] != '.')
				return true;
	if (m[i][j] == '^')
		for (x = i-1; x >= 0; x--)
			if (m[x][j] != '.')
				return true;
	if (m[i][j] == 'v')
		for (x = i+1; x < R; x++)
			if (m[x][j] != '.')
				return true;

	return false;
}

int solve(){
	int i, j, r = 0;

	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			if (!points(i,j)){
				if (v[i][j] > 1)
					r++;
				else
					return -1;
			}

	return r;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		int ans;
		scanf("%d %d", &R, &C);

		for (int i = 0; i < R; i++)
			scanf("%s", m[i]);

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				v[i][j] = 0;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (m[i][j] != '.'){
					int x;
					for (x = 0; x < R; x++)
						v[x][j]++;
					for (x = 0; x < C; x++)
						v[i][x]++;
					v[i][j]--;
				}

		printf("Case #%d: ", t);
		if ((ans = solve()) != -1)
			printf("%d\n", ans);
		else
			printf("IMPOSSIBLE\n");
	}
}
