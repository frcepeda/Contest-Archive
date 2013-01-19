#include <stdio.h>

#define MAXVAL 10000010
#define MAXN 1000010

int count[MAXVAL];
int sequence[MAXN];

int *sameRight = count;
int *sameLeft = count + MAXN;

int N, K;

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i, j, k, tmp = MAXVAL;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++){
		scanf("%d", &j);
		count[j + 5000000]++;
	}

	for (i = j = 0; i < MAXVAL; i++){
		while (count[i]--)
			sequence[j++] = i;
		count[i] = 0;
	}

	for (i = 2; i < N; i++)
		if (sequence[i] - sequence[i-1] == sequence[i-1] - sequence[i-2])
			sameLeft[i] = sameLeft[i-1] + 1;

	for (i = N-3; i >= 0; i--)
		if (sequence[i] - sequence[i+1] == sequence[i+1] - sequence[i+2])
			sameRight[i] = sameRight[i+1] + 1;

	i = 0; j--;

	while (K--){
		if (sequence[i+1] - sequence[i] > sequence[j] - sequence[j-1]){
			i++;
		} else if (sequence[i+1] - sequence[i] < sequence[j] - sequence[j-1]) {
			j--;
		} else {
			int a = min(K+1, sameRight[i]+1);
			int b = min(K+1, sameLeft[i]+1);

			if (a < b){
				i += a;
				K -= a - 1;
			} else if (a > b){
				j -= b;
				K -= b - 1;
			} else {
				if (sequence[i+a+1] - sequence[i+a] >= sequence[j-b] - sequence[j-b-1]){
					i += a;
					K -= a - 1;
				} else if (sequence[i+a+1] - sequence[i+a] < sequence[j-b] - sequence[j-b-1]) {
					j -= b;
					K -= b - 1;
				}
			}
		}
	}

	for (k = i; k < j; k++)
		if (sequence[k+1] - sequence[k] < tmp)
			tmp = sequence[k+1] - sequence[k];

	printf("%d\n", sequence[j] - sequence[i] + tmp);

	return 0;
}
