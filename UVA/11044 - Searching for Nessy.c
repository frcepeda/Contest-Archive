#include <stdio.h>

int f(int n){
	return n/3 + (n%3 != 0);
}

int main(void) {
	int k, n, m;
	scanf("%d", &k);
	while (k--){
		scanf("%d %d", &n, &m);
		printf("%d\n", f(n-2)*f(m-2));
	}
	return 0;
}
