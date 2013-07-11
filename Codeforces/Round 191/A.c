#include <stdio.h>

int sum[110];
int N, ans = -10000;

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}

	for (i = 1; i <= N; i++)
		for (j = i; j <= N; j++)
			ans = max(ans, ((j - i + 1) - (sum[j] - sum[i-1])) - (sum[j] - sum[i-1]));

	printf("%d\n", sum[N] + ans);

	return 0;
}
