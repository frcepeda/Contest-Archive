// 100/100 points
#include <stdio.h>

typedef unsigned long long int ulli;

ulli x;
ulli dp[2] = {1,0};

int main(void){
	scanf("%llu", &x);

	for (; x; x /= 2){
		if (x % 2 == 0)
			dp[1] += dp[0];
		else
			dp[0] += dp[1];
	}

	printf("%llu\n", dp[0]);

	return 0;
}
