#include <cstdio>
#include <algorithm>

using namespace std;

#define fst first
#define snd second
#define mp make_pair

pair<int,int> P[20];
int ans[1<<16];
int dp[50000000];

int N, K;

int main(){
	scanf("%d %d", &K, &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &P[i].fst, &P[i].snd);

	for (int i = 1; i < (1<<N); i++){
		int mx = 1<<30, my = 1<<30, Mx = 0, My = 0;
		for (int j = 0; j < N; j++)
			if (i & (1<<j)){
				mx = min(mx, P[j].fst);
				Mx = max(Mx, P[j].fst);
				my = min(my, P[j].snd);
				My = max(My, P[j].snd);
			}
		ans[i] = 2*(4*K + (Mx - mx) + (My - my));
	}

	for (int i = 1; i < (1<<N); i++){
		dp[i] = 1<<30;
		for (int j = i&-i; j; j = (j - i) & i)
			dp[i] = min(dp[i], ans[j] + dp[i ^ j]);
	}

	printf("%d\n", dp[(1<<N)-1]);
}
