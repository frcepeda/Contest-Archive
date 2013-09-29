#include <stdio.h>

#define MAXN 100100

int BIT[MAXN];
unsigned long long int N, ordered;

int query(int idx){
	int ans = 0;
	for (; idx; idx -= idx&-idx)
		ans += BIT[idx];
	return ans;
}

int update(int idx, int diff){
	for (; idx < MAXN; idx += idx&-idx)
		BIT[idx] += diff;
}

int main(void){
	int i, a;

	scanf("%llu", &N);

	for (i = 0; i < N; i++){
		scanf("%d", &a);
		ordered += query(a);
		update(a+1, 1);
	}

	printf("%llu\n", N*(N-1)/2 - ordered);

	return 0;
}
