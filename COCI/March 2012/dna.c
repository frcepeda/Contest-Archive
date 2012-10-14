#include <stdio.h>

#define MAXSEQUENCE 1000000

int length;
char dna[MAXSEQUENCE];
int dp[MAXSEQUENCE][2];

int min(int a, int b){
	return a < b ? a : b;
}

const char ab[] = {'A', 'B', '\0'};

int main(int argc, const char * argv[])
{
	int i;
	scanf("%d%*[ \n\r]", &length);
	for (i = 0; i < length; i++) {
		dna[i] = getchar();
	}
	dp[0][0] = dna[0] == 'A' ? 0 : 1;
	dp[0][1] = dna[0] == 'B' ? 0 : 1;
	for (i = 1; i < length; i++) {
		int AorB;
		for (AorB = 0; AorB <= 1; AorB++) {
			int keep = dp[i-1][AorB] + (dna[i] == ab[AorB] ? 0 : 1);
			int change = dp[i-1][!AorB] + 1 + (dna[i] == ab[!AorB] ? 0 : 1);
			dp[i][AorB] = min(keep, change);
		}
	}
	printf("%d\n", dp[length-1][0]);
	return 0;
}
