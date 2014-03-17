#include <stdio.h>

int T, N;

unsigned long long f(unsigned long long x){
	for (; x % 2; x /= 2);
	return x/2;
}

int main(void){
	scanf("%d", &T);

	while (T--){
		unsigned long long nim_value = 0, a;
		scanf("%d", &N);
		while (N--){
			scanf("%llu", &a);
			nim_value ^= f(a);
		}
		printf("%s\n", nim_value ? "YES" : "NO");
	}

	return 0;
}
