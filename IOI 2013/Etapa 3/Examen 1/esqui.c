#include <stdio.h>

#define MAXT 10500
#define MAXN MAXT
#define MAXLEVEL 110
#define MAXS MAXLEVEL

typedef struct {
	int level, duration;
} track;

int trackCmp(const void *ap, const void *bp){
	if (((track *)ap)->level == ((track *)ap)->level)
		return ((track *)ap)->duration - ((track *)bp)->duration;
	return ((track *)ap)->level - ((track *)bp)->level;
}

typedef struct {
	int time, duration, level;
} class;

int classCmp(const void *ap, const void *bp){
	return ((class *)ap)->time - ((class *)bp)->time;
}

int classAtTime[MAXT];
class classes[MAXS];
track tracks[MAXN];
int dp[MAXT][MAXLEVEL];

int durationOfTrackByLevel[MAXLEVEL];

int T, N, S;

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i, j, k;

	scanf("%d %d %d", &T, &S, &N);

	for (i = 1; i <= S; i++)
		scanf("%d %d %d", &classes[i].time, &classes[i].duration, &classes[i].level);

	for (i = 1; i <= N; i++)
		scanf("%d %d", &tracks[i].level, &tracks[i].duration);

	qsort(classes+1, S, sizeof(classes[0]), classCmp);
	qsort(tracks+1, N, sizeof(tracks[0]), trackCmp);

	for (i = 1; i <= S; i++)
		if (classAtTime[classes[i].time] == 0)
			classAtTime[classes[i].time] = i;

	for (i = 1; i <= N; i++)
		for (j = tracks[i].level; j < MAXLEVEL; j++)
			if (durationOfTrackByLevel[j] == 0 || durationOfTrackByLevel[j] > tracks[i].duration)
				durationOfTrackByLevel[j] = tracks[i].duration;

	for (i = 2; i < MAXLEVEL; i++)
		if (durationOfTrackByLevel[i-1] != 0 && durationOfTrackByLevel[i-1] < durationOfTrackByLevel[i])
			durationOfTrackByLevel[i] = durationOfTrackByLevel[i-1];

	for (i = T; i >= 0; i--){
		for (j = 1; j < MAXLEVEL; j++){
			dp[i][j] = dp[i+1][j];

			if (durationOfTrackByLevel[j] > 0 && i + durationOfTrackByLevel[j] <= T)
				dp[i][j] = max(dp[i][j], dp[i + durationOfTrackByLevel[j]][j] + 1);

			for (k = classAtTime[i]; classes[k].time == i; k++)
				if (i + classes[k].duration <= T)
					dp[i][j] = max(dp[i][j], dp[i + classes[k].duration][classes[k].level]);
		}
	}

	printf("%d\n", dp[0][1]);

	return 0;
}