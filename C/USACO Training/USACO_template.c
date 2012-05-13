/*
    ID: frceped1
    LANG: C
    TASK: TASKNAME
 */

#include <stdio.h>

#define UPLOAD 0

#if UPLOAD
	#define openFiles() freopen("TASKNAME.in", "r", stdin); freopen("TASKNAME.out", "w", stdout)
#else
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

int main(void){
	openFiles();
	return 0;
}
