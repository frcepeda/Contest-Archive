#include <stdio.h>
#include <strings.h>

#define MOD 1000000007
#define MAXN 100100

char str[MAXN];
unsigned long long int twoPower[MAXN];
unsigned long long int twoAcc;
unsigned long long int ans;
int k, n;

unsigned long long int power(unsigned long long int x, int y){
	unsigned long long int result = 1;

	for (; y; y /= 2){
		if (y % 2 == 1)
			result = (result * x) % MOD;
		x = (x * x) % MOD;
	}

	return result;
}

int main(void){
	int i;

	scanf("%s", str);
	scanf("%d", &k);

	n = strlen(str);

	twoPower[0] = 1;
	for (i = 1; i <= n; i++)
		twoPower[i] = (twoPower[i-1] * 2) % MOD;

	twoAcc = ((power(twoPower[n],k) - 1) * power(twoPower[n]-1, MOD-2)) % MOD;

	for (i = 0; str[i]; i++)
		if (str[i] == '0' || str[i] == '5')
			ans = (ans + (twoPower[i] * twoAcc)) % MOD;

	printf("%llu\n", ans);

	return 0;
}
