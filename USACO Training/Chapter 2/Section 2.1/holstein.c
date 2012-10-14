/*
    ID: frceped1
    LANG: C
    TASK: holstein
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("holstein.in", "r", stdin); freopen("holstein.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXVITAMINS 25
#define MAXFEEDS 15

int vitaminsContained[MAXFEEDS][MAXVITAMINS];
int required[MAXVITAMINS];

int feedCount;
int vitaminCount;

int answer = (1<<MAXFEEDS)-1;

int bitCount(int n){
	int count = 0;

	for (; n; n -= n & (-n), count++);

	return count;
}

int main(void){
	openFiles();

	int i, j, mask;

	scanf("%d", &vitaminCount);

	for (i = 0; i < vitaminCount; i++)
		scanf("%d", &required[i]);

	scanf("%d", &feedCount);

	for (i = 0; i < feedCount; i++)
		for (j = 0; j < vitaminCount; j++)
			scanf("%d", &vitaminsContained[i][j]);

	for (mask = 1; mask < (1<<feedCount); mask++){
		int temp = mask;

		int gotVitamins[MAXVITAMINS];

		memset(gotVitamins, 0, sizeof(gotVitamins));

		do {
			temp -= i = temp & (-temp);
			int feed = -1;
			for (; i; i >>= 1, feed++);

			for (j = 0; j < vitaminCount; j++)
				gotVitamins[j] += vitaminsContained[feed][j];
		} while (temp);

		int valid = 1;

		for (i = 0; i < vitaminCount; i++){
			if (gotVitamins[i] < required[i]){
				valid = 0;
				break;
			}
		}

		if (valid && bitCount(mask) < bitCount(answer)){
			answer = mask;
		}
	}

	j = bitCount(answer);
	printf("%d ", j);

	do {
		answer -= i = answer & (-answer);
		int feed = 0;
		for (; i; i >>= 1, feed++);

		printf("%d%c", feed, answer ? ' ' : '\n');
	} while (answer);

	return 0;
}
