#include <stdio.h>

int n, m;

int main(void){
	int i;

	scanf("%d %d", &n, &m);

	printf("%d\n", n + m - 1);

	for (i = 1; i <= m; i++)
		printf("1 %d\n", i);

	for (i = 2; i <= n; i++)
		printf("%d 1\n", i);

	return 0;
}
