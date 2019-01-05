#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000100;
int T, N;
int dp[maxn];
const int MOD = 1000000007;

int main(){
	scanf("%d", &T);

	dp[0] = 1;
	for (int i = 3; i < maxn; i += 3){
		for (int j = 1; j <= 8 && i-3*j >= 0; j++)
			dp[i] = (dp[i] + dp[i-3*j]) % MOD;
	}

	while (T--){
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
}
