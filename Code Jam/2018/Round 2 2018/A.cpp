#include <cstdio>
#include <algorithm>

using namespace std;

const int maxc = 110;
int C;
int B[maxc], to[maxc];

char g[maxc][maxc];

int works(){
	int last = 0, curr = 0;

	if (B[0] == 0 || B[C-1] == 0) return -1;

	for (int i = 0; i < C; i++){
		for (; i - last >= B[curr]; curr++)
			last = i;
		to[i] = curr;
	}

	int ans = 1;

	for (int i = 0; i < C; i++)
		ans = max(ans, abs(i - to[i]) + 1);

	return ans;
}

int main(){
	int T;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d", &C);

		for (int i = 0; i < C; i++)
			scanf("%d", &B[i]);

		int ans = works();

		printf("Case #%d: ", t);

		if (ans >= 1){
			printf("%d\n", ans);
			
			for (int i = 0; i < C; i++){
				for (int j = 0; j < C; j++)
					g[i][j] = '.';
				g[i][C] = '\0';
			}

			for (int i = 0; i < C; i++){
				if (to[i] == i) continue;

				if (i < to[i])
					for (int j = i; j < to[i]; j++)
						g[abs(j - to[i])][j] = '\\';
				else
					for (int j = i; j > to[i]; j--)
						g[abs(j - to[i])][j] = '/';
			}

			for (int i = ans-1; i >= 0; i--)
				printf("%s\n", g[i]);
		} else printf("IMPOSSIBLE\n");
	}
}
