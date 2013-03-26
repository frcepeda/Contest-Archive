#include <stdio.h>

#define MAXN 31

unsigned long long int ways[MAXN][MAXN];
int H, W;

int main(void){
	int i, j;

	scanf("%d %d", &H, &W);
	H++, W++;

	for (i = 1; i <= W; i++)
		ways[1][i] = 1;

	for (i = 1; i <= H; i++)
		ways[i][1] = 1;

	for (i = 2; i <= H; i++)
		for (j = 2; j <= W; j++)
			ways[i][j] = ways[i-1][j] + ways[i][j-1];

	printf("%llu\n", ways[H][W]);

	return 0;
}
