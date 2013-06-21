#include <stdio.h>

#define MAXB 32

int a, b, n;

unsigned int choose[MAXB][MAXB];

unsigned int f(int x){
	unsigned int ans = 0, len = 0, acc = 0, i;
	char num[MAXB];

	while (x){
		num[len++] = x % 2;
		x /= 2;
	}

	for (i = len-1; i > 0; i--){
		if (num[i]){
			if (acc <= n)
				ans += choose[i][n-acc];
			acc++;
		}
	}

	if (acc == n)
		ans++;

	return ans;
}

int main(void){
	int i, j;

	for (i = 0; i < MAXB; i++){
		choose[i][0] = choose[i][i] = 1;
		for (j = 1; j < i; j++)
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
	}

	scanf("%d %d %d", &a, &b, &n);

	printf("%u\n", f(b) - (a > 1 ? f(a-1) : 0));

	return 0;
}
