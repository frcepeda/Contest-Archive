#include <stdio.h>

#define MAXN 1000

int n, k, x, t;
int coefficients[MAXN];

int main(void){
	int i;

	while (scanf("%d", &n), n != -1){
		for (i = n; i >= 0; i--)
			scanf("%d", &coefficients[i]);

		scanf("%d", &k);

		printf("Case %d:\n", ++t);
		while (k--){
			long long int answer = 0;
			long long int base = 1;
			scanf("%d", &x);

			for (i = 0; i <= n; i++){
				answer += coefficients[i] * base;
				base *= x;
			}

			printf("%lld\n", answer);
		}
	}

	return 0;
}
