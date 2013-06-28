#include <stdio.h>

int r, g, b, ans;

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i;

	scanf("%d %d %d", &r, &g, &b);

	ans = r/3 + g/3 + b/3;

	for (i = 1; i <= 3; i++)
		if (r >= i && g >= i && b >= i)
			ans = max(ans, i + (r-i)/3 + (g-i)/3 + (b-i)/3);

	printf("%d\n", ans);

	return 0;
}
