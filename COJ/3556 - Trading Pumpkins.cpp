#include <cstdio>
#include <algorithm>
#include <vector>

#define fst first
#define snd second

using namespace std;

int A, M;
vector<int> C[25];
pair<int,int> dp[25][1010];
int b[25][1010];

int main(){
	scanf("%d %d", &A, &M);

	for (int i = 0; i < A; i++){
		int k, x;
		scanf("%d", &k);
		C[i].push_back(0);
		while (k--){
			scanf("%d", &x);
			C[i].push_back(x + *C[i].rbegin());
		}
	}

	for (int i = A-1; i >= 0; i--){
		for (int j = 1; j <= M; j++){
			int l = min(int(C[i].size() - 1), j);
			for (int k = 0; k <= l; k++){
				auto r = dp[i+1][j-k];
				r.fst += 10*k - C[i][k];
				r.snd -= k;
				if (r > dp[i][j]){
					dp[i][j] = r;
					b[i][j] = k;
				}
			}
		}
	}

	printf("%d %d\n", dp[0][M].fst, -dp[0][M].snd);
	for (int a = 0, m = M; a < A; a++){
		printf("%d%c", b[a][m], a < A-1 ? ' ' : '\n');
		m -= b[a][m];
	}
}
