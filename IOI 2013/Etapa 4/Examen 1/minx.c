#include <stdio.h>
#include <stdlib.h>

#define MAXTHING 100000000
#define MAXMEM 10000000
#define MAXN 60

unsigned int dp[MAXMEM];
int fall[MAXN], nums[MAXN];
int N;

int main(void){
	int i, j = 1;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	for (i = 2; i < N; i++){
		fall[i] = fall[i-1];

		while (fall[i] != 0 && nums[fall[i]+1] != nums[i])
			fall[i] = fall[fall[i]];

		if (nums[fall[i]+1] == nums[i])
			fall[i] = fall[i]+1;
	}

	int curr = 0;
	for (i = 1; i <= MAXTHING; i++){
		int nao;

		if (i < MAXMEM){
			if (i < 10)
				dp[i] = i;
			else
				dp[i] = dp[i/10] * (i % 10);
			nao = dp[i];
		} else {
			nao = dp[i/10] * (i % 10);
		}

		while (curr != 0 && nao != nums[curr])
			curr = fall[curr];

		if (nums[curr] == nao)
			curr++;

		if (curr == N){
			printf("%d\n", i - N + 1);
			return 0;
		}
	}

	return 0;
}
