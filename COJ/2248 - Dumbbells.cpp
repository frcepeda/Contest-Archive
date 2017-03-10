#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define fst first
#define snd second
#define mp make_pair

typedef pair<int,int> pii;

#define MAXN 4010

int N, K;
short cnt[MAXN], dp[MAXN][MAXN];
pii a[MAXN];
vector<int> v[MAXN], z;

int main(){
	int i, j;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++){
		scanf("%d %d", &a[i].fst, &a[i].snd);
		cnt[a[i].fst]++;
		v[a[i].fst].push_back(a[i].snd);
	}

	for (i = 1; i <= 4001; i++)
		dp[i][0] = 20000;

	for (i = 4000; i >= 1; i--)
		for (j = 1; j <= K; j++)
			dp[i][j] = max(dp[i+1][j], min(cnt[i], dp[i+1][j-1]));

	int t = dp[1][K];

	for (int i = 1; i <= 4000; i++){
		if (cnt[i] >= t){
			sort(v[i].begin(), v[i].end(), greater<int>());
			int w = 0;
			for (int j = 0; j < t; j++)
				w += v[i][j];
			z.push_back(w);
		}
	}

	int s = 0;
	sort(z.begin(), z.end(), greater<int>());
	for (int i = 0; i < K; i++)
		s += z[i];

	printf("%d %d\n", t, s);
}
