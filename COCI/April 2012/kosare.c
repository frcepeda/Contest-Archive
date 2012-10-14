#include <stdio.h>

#define MAXBITS (1<<15)
#define MAXBOXES 105
#define MOD 1000000007

int boxes[MAXBOXES];
int boxCount, toyCount;

int dp[MAXBOXES][MAXBITS];

int main(void){
	int i, j, bits;

	scanf("%d %d", &boxCount, &toyCount);

	for (i = 1; i <= boxCount; i++){
		int count, toy;
		scanf("%d", &count);
		while (count--){
			scanf("%d", &toy);
			boxes[i] |= (1<<(toy-1));
		}
	}
	
	dp[0][0] = 1;
	for (i = 1; i <= boxCount; i++){
		for (j = 0; j < MAXBITS; j++){
			dp[i][j] += dp[i-1][j];
			dp[i][j^boxes[i]] += dp[i-1][j] + 1;
			dp[i][j^boxes[i]] %= MOD;
			dp[i][j] %= MOD;
		}
	}

	printf("%d\n", dp[boxCount][(1<<toyCount)-1]);

	return 0;
}

