// Accepted
#include <stdio.h>

int f(int n){
	if (n < 1) return 0;
	n = (n+1)/2;
	return n * n;
}

int main(void){
	int T, t, a, b;
	
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", t, f(b) - f(a-1));
	}

	return 0;
}
