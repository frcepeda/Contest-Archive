#include <cstdio>
#include <algorithm>

using namespace std;

int T, X;
double dp[5010];

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d", &X);
		dp[X] = 0;

		for (int i = X-1; i >= 0; i--){
			dp[i] = 0;
			for (int j = 1; j <= min(X-i, 10); j++)
				dp[i] += dp[i+j] + 1;
			dp[i] /= min(X-i, 10);
		}

		printf("%.8lf\n", dp[0]);
	}
}
