/*
    ID: frceped1
    LANG: C
    TASK: TASKNAME
 */

#include <stdio.h>

#define UPLOAD 0

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("TASKNAME.in", "r"); out = fopen("TASKNAME.out", "w")
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

int main(void){
	openFiles();
	return 0;
}
