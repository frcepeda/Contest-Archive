#include <stdio.h>
#include <stdbool.h>

#define MAXN 21

unsigned long long int dp[1<<MAXN];

unsigned int likes[MAXN];
unsigned short bitCount[1<<MAXN];
int c, n;

short count(unsigned int a){
	short ans = 0;
	for (; a; ans++, a -= a & -a);
	return ans;
}

int main(void){
	int i, j, k;

	for (i = 0; i < (1<<MAXN); i++)
		bitCount[i] = count(i);

	scanf("%d", &c);

	while (c--){
		scanf("%d", &n);

		for (i = 0; i < (1<<n); i++)
			dp[i] = 0;
		dp[(1<<n)-1] = 1;

		for (i = 0; i < n; i++){
			likes[i] = 0;
			for (j = 0; j < n; j++){
				scanf("%d", &k);
				likes[i] |= k<<j;
			}
		}

		for (j = (1<<n) - 2; j >= 0; j--)
			for (i = bitCount[j], k = 0; k < n; k++)
				if (!(j & (1<<k)) && (likes[i] & (1<<k)))
					dp[j] += dp[j | (1<<k)];

		printf("%llu\n", dp[0]);
	}

	return 0;
}
