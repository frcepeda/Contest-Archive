#include <stdio.h>
#include <strings.h>

#define MAXN 15
#define MAXSIZE 102

#define false 0
#define true 1
#define unvisited 2

int min(int a, int b){
	return a < b ? a : b;
}

int n;
int parts[MAXN];
char dp[MAXSIZE][1<<MAXN];
int total;
int sum[1<<MAXN];

char f(int width, unsigned int unused){
	unsigned int i, height = sum[unused] / width;

	if (dp[width][unused] != unvisited)
		return dp[width][unused];
	else if ((unused & (unused - 1)) == 0)
		return dp[width][unused] = true;

	dp[width][unused] = false;
	for (i = (unused - 1) & unused; i && !dp[width][unused]; i = (i - 1) & unused){
		unsigned int j = unused ^ i;
		if (sum[i] % width == 0)
			dp[width][unused] |= f(width, i) & f(width, j);
		if (!dp[width][unused] && sum[i] % height == 0)
			dp[width][unused] |= f(height, i) & f(height, j);
	}

	return dp[width][unused];
}

int main(void){
	int c, i;

	for (c = 1; scanf("%d", &n), n != 0; c++){
		int x, y;
		total = 0;

		scanf("%d %d", &x, &y);

		for (i = 0; i < n; i++){
			scanf("%d", &parts[i]);
			total += parts[i];
			sum[1<<i] = parts[i];
		}

		for (i = 1; i < 1<<n; i++){
			int lastBit = i & -i;
			sum[i] = sum[lastBit] + sum[i ^ lastBit];
		}

		memset(dp, unvisited, sizeof(dp));

		printf("Case %d: ", c);

		if (x * y != total || !f(min(x,y), (1<<n)-1))
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}
