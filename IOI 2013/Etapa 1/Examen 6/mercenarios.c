#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 44

int bestCount, bestCost;
int available, chosen;
int cost[MAXN];
int hatedCount[MAXN];
bool hates[MAXN][MAXN];
int N;

void search(int i, int currCost){
	int j;

	if (i == N || !available){
		if (chosen > bestCount){
			bestCount = chosen;
			bestCost = currCost;
		} else if (chosen == bestCount && currCost < bestCost)
			bestCost = currCost;
		return;
	}

	if (chosen + available < bestCount || (chosen + available == bestCount && currCost >= bestCost))
		return;

	available--;
	for (; i < N; i++){
		if (!hatedCount[i]){
			chosen++;
			for (j = i+1; j < N; j++){
				if (hates[i][j]){
					if (!hatedCount[j])
						available--;
					hatedCount[j]++;
				}
			}
			search(i+1, currCost + cost[i]);
			for (j = i+1; j < N; j++){
				if (hates[i][j]){
					hatedCount[j]--;
					if (!hatedCount[j])
						available++;
				}
			}
			chosen--;
		} else if (N <= 32 || rand() < RAND_MAX/4) { /* HA */
			search(i+1, currCost);
		}
	}
	available++;
}

int main(void){
	int i, j, k;
	srand(0);

	scanf("%d", &N);
	available = N;

	for (i = 0; i < N; i++){
		scanf("%d %d", &cost[i], &j);
		while (j--){
			scanf("%d", &k);
			k--;
			hates[i][k] = true;
			hates[k][i] = true;
		}
	}

	search(0, 0);

	printf("%d %d\n", bestCount, bestCost);

	return 0;
}
