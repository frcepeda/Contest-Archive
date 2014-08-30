#include <stdio.h>
#include <math.h>

int N;

int main(void){
	int i, j, acc, ans = 0;

	scanf("%d", &N);

	for (acc = i = j = 1; i <= N; i++){
		acc -= i-1;
		for (; acc < N; j++)
			acc += j+1;
		if (acc == N) ans++;
	}

	printf("%d\n", ans);

	return 0;
}
