#include <stdio.h>

#define MAXN 100010

#define LLD "%lld"
//#define LLD "%I64d"

long long int sequence[MAXN];
unsigned long long int acc;
int min, N, X;

int main(void){
	int i;

	scanf("%d %d", &N, &X);
	X--;

	for (i = 0; i < N; i++){
		scanf(LLD, &sequence[i]);
		if (sequence[i] <= sequence[min])
			min = i;
	}

	if (sequence[X] == sequence[min])
		min = X;

	for (i = 0; i < N; i++){
		if (i == min) continue;
		sequence[i] -= sequence[min];
	}
	acc = sequence[min] * N;
	sequence[min] = 0;

	for (i = min; i != X; i = i != N-1 ? i + 1 : 0){
		sequence[i]--;
		acc++;
	}
	sequence[i]--;
	acc++;

	sequence[min] += acc;

	for (i = 0; i < N; i++)
		printf(LLD"%c", sequence[i], i != N-1 ? ' ' : '\n');

	return 0;
}
