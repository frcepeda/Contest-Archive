#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

#define MAXK 1500

int n, m, k;
short card[MAXK];
double dp[MAXK];

int main(){
	int i, j;

	while (scanf("%d %d", &n, &m) != EOF){
		for (i = 0; i < MAXK; i++)
			card[i] = 0;

		while (n--){
			char s[5];
			scanf("%s", s);
			if (isalpha(s[0]))
				card[m] = 10 + (s[0] == 'A');
			else
				card[m] = atoi(s);
			k = m;
			m += card[m];
		}

		/*
		for (i = 1; i <= k; i++)
			printf("%hd ", card[i]);
		putchar('\n');
		*/

		dp[k] = 1;
		for (i = k-1; i >= 1; i--){
			if (!card[i]){
				dp[i] = 0;
				for (j = 2; j <= 9 && i+j <= k; j++)
					dp[i] += dp[i+j];
				if (i+10 <= k)
					dp[i] += 4 * dp[i+10];
				if (i+11 <= k)
					dp[i] += dp[i+11];
				dp[i] /= 13;
			} else {
				dp[i] = 1;
			}
		}

		for (i = 2; i <= min(10,k); i++)
			dp[1] += dp[i];

		printf("%.15lf\n", dp[1] / 10);
	}
}
