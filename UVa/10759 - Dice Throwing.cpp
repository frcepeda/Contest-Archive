// Accepted

/*
Just count the ways to throw the dice so the condition is satisfied.
dp[n][x] is (first) the number of ways to throw n dice so their sum is x.
After the second pass, it is the number of ways to throw n dice so their sum is at least x.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 30
#define MAXX 200

typedef unsigned long long ull;

int n, x;
ull sixtothe[MAXN] = {1};
ull dp[MAXN][MAXX];

int main() {
	int i, j, k;
	
	for (i = 1; i < MAXN; i++) sixtothe[i] = 6 * sixtothe[i-1];
	
	dp[0][0] = 1;
	
	for (i = 1; i < MAXN; i++)
		for (j = 0; j < MAXX; j++)
			for (k = 1; k <= 6 && j - k >= 0; k++)
				dp[i][j] += dp[i-1][j-k];
				
	for (i = 0; i < MAXN; i++)
		for (j = MAXX-2; j >= 0; j--)
			dp[i][j] += dp[i][j+1];
	
	while (scanf("%d %d", &n, &x), (n || x)){
		ull num = dp[n][x];
		ull den = sixtothe[n];
		
		ull g = __gcd(num, den);
		
		if (num == 0)
			printf("0\n");
		else if (num == den)
			printf("1\n");
		else
			printf("%llu/%llu\n", num/g, den/g);
	}
}
