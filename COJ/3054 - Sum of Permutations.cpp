#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000100

int T, N;
long long dp[MAXN];

int main(){
	dp[1] = 1;
	for (int i = 2; i < MAXN; i++)
		dp[i] = (1 + i * dp[i-1]) % 1000003;

	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}
}
