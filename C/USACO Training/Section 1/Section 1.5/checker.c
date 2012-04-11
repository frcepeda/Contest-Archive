/*
    ID: frceped1
    LANG: C
    TASK: checker
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("checker.in", "r"); out = fopen("checker.out", "w")
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

#define MAXNUM 13

typedef struct {
	int val, i;
} pair;

int pairCmp(const void *ap, const void *bp){
	int a = ((pair *)ap)->val;
	int b = ((pair *)bp)->val;
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}

int used[MAXNUM];
int size;
int remaining = 3; // solutions left to print
int answer;

void printAnswer(void){
	int i;
	pair willSort[MAXNUM];

	for (i = 0; i < size; i++){
		willSort[i].val = used[i];
		willSort[i].i = i;
	}

	qsort(willSort, size, sizeof(pair), pairCmp);

	for (i = 0; i < size; i++)
		print("%s%d", i ? " " : "", willSort[i].i + 1);
	print("\n");
}

int canUse(int row, int column){
	if (used[row]) return 0;
	int i;
	for (i = 0; i < size; i++)
		if (used[i])
			if (abs(used[i]-column) == abs(i-row))
				return 0;
	return 1;
}

void backtrack(int column){
	int row;

	if (column > size){
		if (remaining){
			printAnswer();
			remaining--;
		}
		answer++;
		return;
	}

	for (row = 0; row < size; row++){
		if (canUse(row,column)){
			used[row] = column;
			backtrack(column+1);
			used[row] = 0;
		}
	}
}

void trickyTrick(void){
	int row;
	for (row = 0; row < 6; row++){
		used[row] = 1;
		backtrack(2);
		used[row] = 0;
	}
	answer *= 2;
	used[row] = 1;
	backtrack(2);
}

int main(void){
	openFiles();
	int i;

	read("%d", &size);

	if (size < 13)
		backtrack(1);
	else
		trickyTrick();

	print("%d\n", answer);

	return 0;
}
