#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 25

int dp[MAXNUM][MAXNUM];
int next[MAXNUM][MAXNUM];
int took[MAXNUM][MAXNUM];
int turns[MAXNUM];
int used[MAXNUM];
int turnnum, lastnum;
int answer;

void mark(int i, int cost){
	if (i < 0) return;
	used[took[i][cost]] = took[i][cost];
	mark(i-1, next[i][cost]);
}

int main(void) {
	int i, j, dpi, cost;

	scanf("%d %d", &lastnum, &turnnum);

	for (i = 0; i < turnnum; i++)
		scanf("%d", &turns[i]);

	for (i = 0; i < turnnum; i++){
		int dpi = 1;
		for (j = 1; j <= lastnum; j++){
			if (used[j]) continue;
			for (cost = 1; cost <= turns[i]; cost++){
				if (cost < j){
					dp[dpi][cost] = dp[dpi-1][cost];
					took[dpi][cost] = 0;
					next[dpi][cost] = cost;
				} else {
					if (dp[dpi-1][cost] > dp[dpi-1][cost-j] + 1){
						dp[dpi][cost] = dp[dpi-1][cost];
						took[dpi][cost] = 0;
						next[dpi][cost] = cost;
					} else {
						dp[dpi][cost] = dp[dpi-1][cost-j] + 1;
						took[dpi][cost] = j;
						next[dpi][cost] = cost-j;
					}
				}
			}
			dpi++;
		}

		/*for (j = 1; j < dpi; j++){
			for (cost = 1; cost <= turns[i]; cost++){
			    printf("%d ", dp[j][cost]);
			}
			printf("\n");
		}*/

		dpi--;

		if (dp[dpi][turns[i]]){
			answer += dp[dpi][turns[i]];
			used[took[dpi][turns[i]]] = took[dpi][turns[i]];
			mark(dpi-1, next[dpi][turns[i]]);
		} else break;
	}

	printf("%d\n", answer);

	return 0;
}

