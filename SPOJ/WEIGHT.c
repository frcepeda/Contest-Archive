#include <stdio.h>

#define MAXN 1000100

int seq[MAXN];
int N, T;

int main(void){
	scanf("%d", &T);

	while (T--){
		int i;
		long long int acc = 0, answer = 0;

		scanf("%d", &N);

		for (i = 0; i < N; i++)
			scanf("%d", &seq[i]);

		for (i = N-1; i >= 0; i--){
			acc += seq[i];
			answer += acc;

			if (acc <= 0 && i > 0){
				answer += acc;
				acc = 0;
			}
		}

		printf("%lld\n", answer);
	}

	return 0;
}
