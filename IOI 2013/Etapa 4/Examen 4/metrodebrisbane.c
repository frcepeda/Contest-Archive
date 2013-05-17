#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN (1000010)
#define MAXTREE (MAXN*4)

int N;
long long int dp[MAXN];
int cost[MAXN];

long long int min(long long int a, long long int b){
	return a < b ? a : b;
}

int lg(int a){
	int ret = -1;
	while (a){
		a >>= 1;
		ret++;
	}
	return ret;
}

long long int _min[MAXN];
int mins, mine;

void insert(long long int a){
	while (mins != mine && _min[mine-1] > a)
		mine--;
	_min[mine++] = a;
}

void delete(long long int a){
	if (_min[mins] == a)
		mins++;
}

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &cost[i]);

	dp[0] = cost[0];
	dp[1] = dp[0] + cost[1];

	int last = 0;
	for (i = 2; i < N; i++){
		int l = lg(i);

		if (i == (1<<l)){
			last = mins = mine = 0;
			for (j = 0; j <= (i - (1<<(l-1)) - 1); j++)
				insert(dp[j]);
		} else {
			insert(dp[last+(1<<(l-1))]);
			delete(dp[last++]);
		}

		dp[i] = /*query(0, 0, N-1, i - (1<<l), i - (1<<(l-1)) - 1)*/ _min[mins] + cost[i];
	}

	printf("%lld\n", dp[N-1]);

	return 0;
}
