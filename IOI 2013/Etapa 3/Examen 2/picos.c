#include <stdio.h>

#define MAXN 100010
#define MOD 46309

typedef struct {
	int first, second;
} pair;

int pairCmp(const void *ap, const void *bp){
	if (((pair *)ap)->first == ((pair *)bp)->first)
		return (((pair *)ap)->second - ((pair *)bp)->second);
	return (((pair *)ap)->first - ((pair *)bp)->first);
}

pair inputNumbers[MAXN];

int N;
int sequence[MAXN];

int increasing[MAXN], decreasing[MAXN];
int increasingCount[MAXN], decreasingCount[MAXN];

void update(int *BIT, int idx, int diff){
	int i;

	for (i = idx; i < MAXN; i += i & -i)
		BIT[i] = (BIT[i] + diff) % MOD;
}

int query(int *BIT, int idx){
	int ret = 0;

	for (; idx; idx -= idx & -idx)
		ret = (ret + BIT[idx]) % MOD;

	return ret;
}

int main(void){
	int i, lastNum = 1, answer = 0;
	
	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d", &inputNumbers[i].first);
		inputNumbers[i].second = i;
	}

	qsort(inputNumbers, N, sizeof(inputNumbers[0]), pairCmp);

	for (i = 0; i < N; i++){
		if (i && inputNumbers[i].first != inputNumbers[i-1].first)
			lastNum++;
		sequence[inputNumbers[i].second] = lastNum;
	}

	for (i = 0; i < N; i++){
		int possible = query(increasing, sequence[i]) + 1;
		update(increasing, sequence[i] + 1, possible);
		increasingCount[i] = possible;
	}

	for (i = N-1; i >= 0; i--){
		int possible = query(decreasing, sequence[i]) + 1;
		update(decreasing, sequence[i] + 1, possible);
		decreasingCount[i] = possible;
	}

	for (i = 0; i < N; i++)
		answer = (answer + increasingCount[i] * decreasingCount[i]) % MOD;

	printf("%d\n", answer);

	return 0;
}
