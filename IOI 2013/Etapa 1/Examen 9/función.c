#include <stdio.h>
#include <stdbool.h>

#define MAXN 100010
#define MAXVAL 1050010
#define MAXBITS 20

unsigned int numbers[MAXN];
unsigned int bitCount[MAXN][20];

int nexti[MAXN][20];
bool used[MAXVAL];

int N;

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i, j, answer = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &numbers[i]);

	for (j = 0; j < MAXBITS; j++)
		if (numbers[0] & (1<<j))
			bitCount[0][j] = 1;

	for (i = 1; i < N; i++){
		for (j = 0; j < MAXBITS; j++){
			bitCount[i][j] = bitCount[i-1][j];
			if (numbers[i] & (1<<j))
				bitCount[i][j]++;
		}
	}

	for (j = 0; j < MAXBITS; j++){
		int next = N;
		bitCount[N][j] = bitCount[N-1][j] + 1;
		for (i = N-1; i >= 0; i--){
			if (bitCount[i][j] + 2 == bitCount[next][j])
				next = i+1;
			nexti[i][j] = next;
		}
	}

	for (i = 0; i < N; i++){
		unsigned int acc = 0, k;
		for (j = i; j < N;){
			acc |= numbers[j];
			if (!used[acc]) answer++;
			used[acc] = true;

			j = N;
			for (k = 0; k < MAXBITS; k++)
				if (!(acc & (1<<k)))
					j = min(j, nexti[i][k]);
		}
	}

	printf("%d\n", answer);

	return 0;
}
