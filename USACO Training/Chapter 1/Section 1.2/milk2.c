/*
    ID: frceped1
    LANG: C
    TASK: milk2
 */

#include <stdio.h>
#include <stdlib.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("milk2.in", "r", stdin); freopen("milk2.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXNUM 5000

typedef struct {
	int start, end;
} Interval;

Interval intervals[MAXNUM];

int intervalCompare(const void *a, const void *b){
	int aV = ((Interval *)a)->start;
	int bV = ((Interval *)b)->start;
	if (aV > bV) return 1;
	else if (bV > aV) return -1;
	else return 0;
}

int main(void){
	int count, i;
	int lastEnd = 0, lastStart = 0;
	int maxYes = 0, maxNo = 0;
	int start, end;
	openFiles();

	scanf("%d", &count);
	for (i = 0; i < count; i++)
		scanf("%d %d", &intervals[i].start, &intervals[i].end);

	qsort(intervals, count, sizeof(Interval), intervalCompare);

	lastStart = intervals[0].start;
	lastEnd = intervals[0].end; 

	for (i = 1; i < count; i++){
		start = intervals[i].start;
		end = intervals[i].end;

		if (start > lastStart && end < lastEnd) continue;

		if (start - lastEnd <= 0){
			lastEnd = end;
		} else {
			int tot = lastEnd - lastStart;
			if (maxYes < tot)
				maxYes = tot;

			int totNo = start - lastEnd;
			if (maxNo < totNo)
				maxNo = totNo;

			lastStart = start;
			lastEnd = end;
		}
	}

	int tot = lastEnd - lastStart;

	if (maxYes < tot)
		maxYes = tot;

	printf("%d %d\n", maxYes, maxNo);

	return 0;
}
