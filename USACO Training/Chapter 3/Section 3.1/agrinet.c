/*
    ID: frceped1
    LANG: C
    TASK: agrinet
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("agrinet.in", "r", stdin); freopen("agrinet.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 110

typedef struct {
	int a, b, dist;
} edge;

int edgeCmp(const void *a, const void *b){
	if (((edge *)a)->dist > ((edge *)b)->dist)
		return 1;
	else if (((edge *)a)->dist < ((edge *)b)->dist)
		return -1;
	return 0;
}

edge edges[MAXN*MAXN];
int edgeCount;

int N;

int setParent[MAXN];

int set(int a){
	if (setParent[a] == a)
		return a;
	return setParent[a] = set(setParent[a]);
}

void join(int a, int b){
	setParent[set(a)] = set(b);
}

int main(void){
	openFiles();

	int i, j, answer = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		for (j = 0; j < i; j++){
			edges[edgeCount].a = i;
			edges[edgeCount].b = j;
			scanf("%d", &edges[edgeCount++].dist);
		}
		for (; j < N; j++)
			scanf("%*d");
	}

	for (i = 0; i < N; i++)
		setParent[i] = i;

	qsort(edges, edgeCount, sizeof(edge), edgeCmp);

	for (i = 0; i < edgeCount; i++){
		if (set(edges[i].a) != set(edges[i].b)){
			answer += edges[i].dist;
			join(edges[i].a, edges[i].b);
		}
	}

	printf("%d\n", answer);

	return 0;
}
