#include <stdio.h>
#include <math.h>

#define MAXFACTORS 500

int min(int a, int b){
	return a < b ? a : b;
}

struct {
	long long int factor, times;
} factors[MAXFACTORS];
int factorCount;

long long int N, Ndivisors = 1;

int case1(long long int K){
	int i, answer = 1;

	for (i = 0; i < factorCount; i++){
		int count = 0;
		while (K % factors[i].factor == 0){
			K /= factors[i].factor;
			count++;
		}
		answer *= min(factors[i].times, count) + 1;
	}

	return answer;
}

int case2(long long int K){
	int i, answer = 1;

	for (i = 0; i < factorCount; i++){
		int count = 0;

		while (count <= factors[i].times && K % factors[i].factor == 0){
			count++;
			K /= factors[i].factor;
		}

		if (count > factors[i].times)
			return 0;

		answer *= factors[i].times - count + 1;
	}

	return K == 1 ? answer : 0;
}

int case3(long long int K){
	return Ndivisors - case2(K);
}

int main(void){
	int Q, i;

	scanf("%lld %d", &N, &Q);

	int lim = sqrt(N);
	for (i = 2; i <= lim; i++){
		if (N % i == 0){
			factors[factorCount].factor = i;
			while (N % i == 0){
				factors[factorCount].times++;
				N /= i;
			}
			Ndivisors *= factors[factorCount++].times + 1;
		}
	}

	if (N > 1){
		factors[factorCount].factor = N;
		factors[factorCount++].times++;
	}

	while (Q--){
		long long int K;
		int T, answer;

		scanf("%d %lld", &T, &K);

		switch (T){
			case 1:
				answer = case1(K);
				break;
			case 2:
				answer = case2(K);
				break;
			case 3:
				answer = case3(K);
				break;
		}

		printf("%d\n", answer);
	}

	return 0;
}
