/*
    ID: frceped1
    LANG: C
    TASK: milk
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("milk.in", "r"); out = fopen("milk.out", "w")
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

#define MAXNUM 5000

typedef struct {
	int amount, cost;
} farmer;

int intCmp(int a, int b){
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}

int farmerCmp(const void *a, const void *b){
	return intCmp(((farmer *)a)->cost, ((farmer *)b)->cost);
}

farmer farmers[MAXNUM];
int farmerCount;

int getMilkUpTo(int *limit){
	static int next = 0;
	int answer;
	if (farmers[next].amount <= *limit){
		*limit -= farmers[next].amount;
		answer = farmers[next].cost * farmers[next].amount;
	} else {
		answer = farmers[next].cost * *limit;
		*limit = 0;
	}
	next++;
	return answer;

}

int main(void){
	openFiles();
	int i, num;
	int total = 0;
	
	read("%d %d", &num, &farmerCount);

	for (i = 0; i < farmerCount; i++)
		read("%d %d", &farmers[i].cost, &farmers[i].amount);

	qsort(farmers, farmerCount, sizeof(farmer), farmerCmp);

	while (num){
		total += getMilkUpTo(&num);
	}

	print("%d\n", total);

	return 0;
}
