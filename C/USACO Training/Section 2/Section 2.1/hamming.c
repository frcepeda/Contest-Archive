/*
    ID: frceped1
    LANG: C
    TASK: hamming
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("hamming.in", "r"); out = fopen("hamming.out", "w")
	#define getchar() fgetc(in)
	#define putchar(c) fputc(c, out)
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

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

	read("%d %d %d", &neededAnswers, &length, &minDifference);
	
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
		print("%d%s", answers[i], (i+1) % 10 && i != answerCount-1 ? " " : "\n");

	return 0;
}
