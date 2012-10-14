/*
    ID: frceped1
    LANG: C
    TASK: hamming
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("hamming.in", "r", stdin); freopen("hamming.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXANSWERS 64
#define MAXLENGTH 8
#define MAXNUM (1<<8)

int bitCount[MAXNUM+1];

int answers[MAXANSWERS];
int answerCount = 1; // 0 is the first answer

int countBits(int num){
	int answer = 0;
	for (; num; num -= (num & -num))
		answer++;
	return answer;
}

int main(void){
	openFiles();
	int i, j;

	int length, neededAnswers, minDifference;

	scanf("%d %d %d", &neededAnswers, &length, &minDifference);
	
	for (i = 0; i < MAXNUM; i++)
		bitCount[i] = countBits(i);

	neededAnswers--; // 0 is already an answer
	for (i = 1; neededAnswers; i++){
		int isValid = 1;
		for (j = 0; j < answerCount; j++){
			if (bitCount[i^answers[j]] < minDifference){
				isValid = 0;
				break;
			}
		}
		if (isValid){
			answers[answerCount++] = i;
			neededAnswers--;
		}
	}

	for (i = 0; i < answerCount; i++)
		printf("%d%s", answers[i], (i+1) % 10 && i != answerCount-1 ? " " : "\n");

	return 0;
}
