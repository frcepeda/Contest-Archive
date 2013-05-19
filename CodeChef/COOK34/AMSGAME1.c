#include <stdio.h>

int T, N;

int gcd(int a, int b){
	int c;
	while (b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void){
	int i, ans;

	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);
		scanf("%d", &ans);
		N--;
		while (N--){
			scanf("%d", &i);
			ans = gcd(ans, i);
		}
		printf("%d\n", ans);
	}

	return 0;
}
