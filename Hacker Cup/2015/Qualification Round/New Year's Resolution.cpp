#include <cstdio>
#include <algorithm>

#define MAXN 21

using namespace std;

int T, N, G[3];
unsigned F[1<<MAXN][3];

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		int i, j;
		bool works = false;
		
		scanf("%d %d %d", &G[0], &G[1], &G[2]);
		scanf("%d", &N);

		for (i = 0; i < N; i++)
			for (j = 0; j < 3; j++)
				scanf("%d", &F[1<<i][j]);

		for (i = 1; i < (1<<N) && !works; i++){
			bool workedHere = true;
			int l = i & -i;

			for (j = 0; j < 3; j++){
				F[i][j] = F[i^l][j] + F[l][j];
				workedHere &= F[i][j] == G[j];
			}

			works = workedHere;
		}

		printf("Case #%d: %s\n", t, works ? "yes" : "no");
	}
}
