/*
    ID: frceped1
    LANG: C
    TASK: concom
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("concom.in", "r", stdin); freopen("concom.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

int intCmp(const void *ap, const void *bp){
	if (*(int *)ap > *(int *)bp)
		return 1;
	else if (*(int *)ap < *(int *)bp)
		return -1;
	return 0;
}

#define MAXN 20000
#define MAXCOMP 101

typedef struct {
	int id, percentage, next;
} node;

node nodes[MAXN];
int nextNode = 1;
int start[MAXCOMP];

int queue[MAXN];
int qs, qe;

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)
#define resetQueue() qs = qe = 0

bool visited[MAXCOMP];
int accum[MAXCOMP];

int controls[MAXCOMP];
int controlCount;

void try(int s){
	int curr, i, next;

	for (i = 1; i <= MAXCOMP; i++){
		accum[i] = 0;
		visited[i] = false;
	}
	accum[s] = 100;
	controlCount = 0;

	push(s);

	while (queueIsNotEmpty){
		curr = pop();

		if (visited[curr])
			continue;

		visited[curr] = true;
		controls[controlCount++] = curr;

		for (next = start[curr]; next != 0; next = nodes[next].next){
			accum[nodes[next].id] += nodes[next].percentage;
			if (accum[nodes[next].id] > 50)
				push(nodes[next].id);
		}
	}

	qsort(controls+1, controlCount-1, sizeof(int), intCmp);

	for (i = 1; i < controlCount; i++)
		printf("%d %d\n", s, controls[i]);
}

int main(void){
	openFiles();

	int i, j, k, num;

	scanf("%d", &num);

	while (num--){
		scanf("%d %d %d", &i, &j, &k);
		nodes[nextNode].id = j;
		nodes[nextNode].percentage = k;
		nodes[nextNode].next = start[i];
		start[i] = nextNode++;
	}

	for (i = 1; i < MAXCOMP; i++)
		if (start[i])
			try(i);

	return 0;
}
