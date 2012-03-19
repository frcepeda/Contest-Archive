/*
 ID: frceped1
 LANG: C
 TASK: friday
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("friday.in", "r"); out = fopen("friday.out", "w")
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload header

int normal[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int leap[] = {31,29,31,30,31,30,31,31,30,31,30,31};
int count[7] = {1};

int isLeapYear(int year){
	return !(year % 4) && (year % 100 || !(year % 400));
}

int main(void){
	int i;
	openFiles();
	int lastYear;
	read("%d", &lastYear);
	lastYear += 1899;
	int weekday = 0;
	for (i = 1900; i <= lastYear; i++){
		int month;
		for (month = 0; month < 12; month++){
			if (isLeapYear(i)){
				weekday += leap[month];
			} else {
				weekday += normal[month];
			}
			weekday %= 7;
			count[weekday]++;
		}
	}
	count[weekday]--;
	for (i = 0; i < 7; i++){
		print("%d%c", count[i], i < 6 ? ' ' : '\n');
	}
	return 0;
}

