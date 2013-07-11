#include <stdio.h>

#define N 99
#define MOD 1000

int lcm[100];

int main(void){
	int i, j;

	for (i = 3; i <= N; i += 2){
		int n = i;

		for (j = 3; j <= N; j += 2){
			int count = 0;

			while (n % j == 0){
				n /= j;
				count++;
			}

			if (lcm[j] < count)
				lcm[j] = count;
		}
	}

	int ans = 1;

	for (i = 3; i <= N; i += 2)
		for (j = lcm[i]; j > 0; j--)
			ans = (ans * i) % MOD;

	printf("%d\n", ans);

	return 0;
}
