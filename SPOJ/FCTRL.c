#include <stdio.h>

int N, T;

int main(void){
	scanf("%d", &T);

	while (T--){
		long long int two = 0, five = 0;
		int tmp;

		scanf("%d", &N);

		for (tmp = N; tmp; tmp /= 2)
			two += tmp / 2;

		for (tmp = N; tmp; tmp /= 5)
			five += tmp / 5;

		printf("%lld\n", two < five ? two : five);
	}

	return 0;
}
