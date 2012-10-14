#include <stdio.h>

#define MAXN 10000001

int N;
int heaps[MAXN];

int reverseIntCmp(const void *ap, const void *bp){
	if (*(int *)ap > *(int *)bp)
		return -1;
	if (*(int *)ap < *(int *)bp)
		return 1;
	return 0;
}

int main(void){
	int i, oddCount = 0;
	unsigned long long int answer = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d", &heaps[i]);
		if (heaps[i] % 2)
			oddCount++;
	}

	qsort(heaps, N, sizeof(int), reverseIntCmp);

	if (oddCount > 0){
		if (oddCount % 2 == 0)
			oddCount--;

		for (i = 0; i < N; i++){
			if (heaps[i] % 2 && oddCount > 0){
				answer += heaps[i];
				oddCount--;
			} else if (heaps[i] % 2 == 0){
				answer += heaps[i];
			}
		}
	}

	printf("%llu\n", answer);

	return 0;
}

