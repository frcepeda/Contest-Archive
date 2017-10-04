#include <cstdio>
#include <algorithm>

using namespace std;

int n, p;

const int maxn = 1000100;
int dp[maxn];

int main(){
	scanf("%d %d", &n, &p);

	dp[1] = 0;

	for (int i = 2; i <= n; i++)
		dp[i] = (p + dp[i-1] + (dp[i-1] >= i)) % i;

	printf("%d\n", dp[n]+1);
}
