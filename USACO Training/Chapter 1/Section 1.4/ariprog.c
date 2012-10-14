/*
    ID: frceped1
    LANG: C
    TASK: ariprog
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("ariprog.in", "r", stdin); freopen("ariprog.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXBISQUARE 250*250+250*250+1
#define MAXANSWERS 100000

typedef struct {
	int start, diff;
} answer;

int answerCmp(const void *ap, const void *bp){
	answer a = *(answer *)ap;
	answer b = *(answer *)bp;
	if (a.diff > b.diff) return 1;
	if (b.diff > a.diff) return -1;
	if (a.start > b.start) return 1;
	if (b.start > a.start) return -1;
	return 0;
}

answer answers[MAXANSWERS];
int nextAnswer;

void add(int i, int j){
	answers[nextAnswer].start = i;
	answers[nextAnswer].diff = j;
	nextAnswer++;
}

int isBisquare[MAXBISQUARE];

int main(void){
	openFiles();

	int maxM, wantedlength;
	scanf("%d %d", &wantedlength, &maxM);

	int i,j;
	for (i = 0; i <= maxM; i++)
		for (j = 0; j <= maxM; j++)
			isBisquare[i*i + j*j] = 1;

	for (i = 0; i < MAXBISQUARE / wantedlength; i++){
		if (!isBisquare[i]) continue;
		for (j = 1; j < 3000; j++){ // Yes, it's a magic number but IDC.
			int length = wantedlength; 
			int curr = i;
			int found = 1;
			while (length-- && curr < MAXBISQUARE){				
				if (!isBisquare[curr]){
					found = 0;
					break;
				}
				curr += j;
			}
			if (found && curr < MAXBISQUARE)
				add(i,j);
		}
	}

	qsort(answers, nextAnswer, sizeof(answer), answerCmp);

	for (i = 0; i < nextAnswer; i++)
		printf("%d %d\n", answers[i].start, answers[i].diff);

	if (!nextAnswer)
		printf("NONE\n");

	return 0;
}
