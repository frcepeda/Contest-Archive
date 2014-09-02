#include <stdio.h>

#define MAXN (1<<21)

int cnt[MAXN] = {1};
int N;

int main(void){
	int acc = 0, i, x, ans = 0;

	scanf("%d", &N);

	while (N--){
		scanf("%d", &x);
		acc ^= x;
		ans += cnt[acc];
		cnt[acc]++;
	}

	printf("%d\n", ans);

	return 0;
}
