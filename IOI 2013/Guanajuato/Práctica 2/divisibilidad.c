#include <stdio.h>

#define MAXN 20

int answer[MAXN];

long long int findMultipleWithDigits(int P, int len){
	long long int test;
	long long int lo = 1, hi = 500000000000000001, mid;
	long long int ans = hi;
	while (lo < hi){
		int l = 0;
		mid = (lo + hi) / 2;
		test = P * mid;
		while (test){
			l++;
			test /= 10;
		}
		if (l >= len){
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return P * hi;
}

int main(void){
	int N, P, acc, i, j;
	long long int num;

	scanf("%d %d", &N, &P);
	answer[0] = 1;

	for (i = 1; i < N; i++){
		num = findMultipleWithDigits(P, i+1);
		acc = 0;

		for (j = 0; j < i; j++){
			acc += (num % 10) * answer[j];
			num /= 10;
		}
		acc %= P;

		for (j = 0; j < P; j++)
			if ((acc + j * num) % P == 0)
				break;

		answer[i] = j;
	}

	for (i = N-1; i >= 0; i--)
		printf("%d%c", answer[i], i != 0 ? ' ' : '\n');
	
	return 0;
}
