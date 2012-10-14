/*
    ID: frceped1
    LANG: C
    TASK: milk3
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("milk3.in", "r", stdin); freopen("milk3.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXMILK 21

int maxA, maxB, maxC;
int answers[MAXMILK];
int visited[MAXMILK][MAXMILK][MAXMILK];

#define toFull(n,l) (max##l - n) 

void search(int a, int b, int c){
	if (visited[a][b][c]) return;
	visited[a][b][c] = 1;

	if (a == 0) answers[c] = 1;
	
	if (a){
		// A -> B
		if (a <= toFull(b,B))
			search(0,b+a,c);
		else
			search(a-toFull(b,B),maxB,c);

		// A -> C
		if (a <= toFull(c,C))
			search(0,b,c+a);
		else
			search(a-toFull(c,C),b,maxC);
	}

	if (b){
		// B -> A
		if (b <= toFull(a,A))
			search(a+b,0,c);
		else
			search(maxA,b-toFull(a,A),c);

		// B -> C
		if (b <= toFull(c,C))
			search(a,0,c+b);
		else
			search(a,b-toFull(c,C),maxC);
	}

	if (c){
		// C -> A
		if (c <= toFull(a,A))
			search(a+c,b,0);
		else
			search(maxA,b,c-toFull(a,A));

		// C -> B
		if (c <= toFull(b,B))
			search(a,b+c,0);
		else
			search(a,maxB,c-toFull(b,B));
	}
}

int main(void){
	openFiles();
	int i;

	scanf("%d %d %d", &maxA, &maxB, &maxC);

	search(0,0,maxC);
	
	int before = 0;
	for (i = 0; i < MAXMILK; i++){
		if (answers[i]){
			if (before)
				printf(" %d", i);
			else {
				printf("%d", i);
				before = 1;
			}
		}
	}
	printf("\n");

	return 0;
}
