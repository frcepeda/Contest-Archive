#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#define MAXNUM 200005
#define MAXREGIONS 25005
#define MAXPRECALC 60

typedef struct {
	int a, b;
} pair;

typedef struct {
	int region, count;
} sort;

int regionCmp(const void *ap, const void *bp){
	return ((sort *)bp)->count - ((sort *)ap)->count;
}

typedef struct {
	int node, next;
	bool isEnd;
} reg;

typedef struct {
	int node, next;
} node;

sort sortedRegions[MAXREGIONS];

int parent[MAXNUM];

node tree[MAXNUM];
int start[MAXNUM];
int nextNode = 1;
int region[MAXNUM];

reg regions[MAXNUM*2];
int nextRegion = 1;
int startRegion[MAXNUM];

int nodeCount, regionCount;

int id[MAXREGIONS];
int nextID = 1;

int count[MAXNUM];

static pair thing[MAXNUM];

int cache[MAXPRECALC+1][MAXREGIONS];
int cache2[MAXREGIONS][MAXPRECALC+1];

int flipList(int curr, int r){
	int next = regions[curr].next;
	regions[curr].next = 0;

	while (next) {
		if (!regions[curr].isEnd){
			sortedRegions[r].count++;
		}

		int temp = regions[next].next;
		regions[next].next = curr;
		curr = next;
		next = temp;
	}
	if (!regions[curr].isEnd){
		sortedRegions[r].count++;
	}

	return curr;
}

void preorder(void){
#define push(a) thing[nextStack++] = (a)
#define pop() thing[--nextStack]
#define stackIsNotEmpty nextStack
	static int nextStack;

	int nextIndex = 0;

	regions[nextRegion].node = nextIndex++;
	regions[nextRegion].isEnd = false;
	regions[nextRegion].next = startRegion[region[1]];

	startRegion[region[1]] = nextRegion++;

	thing[nextStack].a = 1;
	thing[nextStack++].b = start[1];

	while (stackIsNotEmpty){
		pair curr = thing[nextStack-1];

		if (curr.b != 0){
			regions[nextRegion].node = nextIndex++;
			regions[nextRegion].isEnd = false;
			regions[nextRegion].next = startRegion[region[tree[curr.b].node]];

			startRegion[region[tree[curr.b].node]] = nextRegion++;

			thing[nextStack-1].b = tree[curr.b].next;

			thing[nextStack].b = start[tree[curr.b].node];
			thing[nextStack++].a = tree[curr.b].node;
		} else {
			regions[nextRegion].node = nextIndex++;
			regions[nextRegion].isEnd = true;
			regions[nextRegion].next = startRegion[region[curr.a]];

			startRegion[region[curr.a]] = nextRegion++;
			nextStack--;
		}
	}
#undef push(a)
#undef pop()
#undef peek()
#undef stackIsNotEmpty
}

void bfs(int reg, int id){
#define push(a) thing[qe++] = (a)
#define pop() thing[qs++]
#define queueIsNotEmpty (qs < qe)
#define queue thing
	static int qs, qe;
	int i;

	qs = qe = 0;

	thing[qe].a=1;
	thing[qe++].b=region[1] == reg ? 1 : 0;

	while (qs < qe){

		int child;
		for (child = start[thing[qs].a]; child; child = tree[child].next){
			pair next;
			next.a = tree[child].node;
			next.b=thing[qs].b;
			if (region[next.a] == reg)
				next.b++;
			cache[id][region[next.a]] += thing[qs].b;
			push(next);
		}
		qs++;
	}

	memset(count, 0, sizeof(count));

	for (i = qe - 1; i >= 0; i--){
		if (region[queue[i].a] == reg){
			count[parent[queue[i].a]] += count[queue[i].a] + 1;
		} else {
			cache2[region[queue[i].a]][id] += count[queue[i].a];
			count[parent[queue[i].a]] += count[queue[i].a];
		}
	}
#undef push(a)
#undef pop()
#undef queueIsNotEmpty
}

int query(int a, int b){
	int answer = 0, count = 0;

	int ra = startRegion[a];
	int rb = startRegion[b];

	while (ra && rb){
		while (rb && regions[rb].isEnd)
			rb = regions[rb].next;

		while (ra && regions[ra].node <= regions[rb].node){
			if (regions[ra].isEnd)
				count--;
			else
				count++;
			ra = regions[ra].next;
		}

		if (rb){
			answer += count;
			rb = regions[rb].next;
		}
	}

	return answer;
}

int main(void){
	int i, queries;

	scanf("%d %d %d", &nodeCount, &regionCount, &queries);

	scanf("%d", &region[1]);
	for (i = 2; i <= nodeCount; i++)
		scanf("%d %d", &parent[i], &region[i]);

	for (i = nodeCount; i > 1; i--){
		tree[nextNode].next = start[parent[i]];
		start[parent[i]] = nextNode;
		tree[nextNode++].node = i;
	}

	preorder();

	for (i = 1; i <= regionCount; i++){
		startRegion[i] = flipList(startRegion[i], i);
		sortedRegions[i].region = i;
	}

	qsort(sortedRegions+1, regionCount, sizeof(sort), regionCmp);

	for (i = 1; i <= nodeCount && i < MAXPRECALC; i++){
		id[sortedRegions[i].region] = nextID++;
		bfs(sortedRegions[i].region, id[sortedRegions[i].region]);
	}

	while (queries--){
		int a, b;
		scanf("%d %d", &a, &b);

		if (id[a]){
			printf("%d\n", cache[id[a]][b]);
		} else if (id[b]){
			printf("%d\n", cache2[a][id[b]]);
		} else {
			printf("%d\n", query(a, b));
		}

		
	}

	return 0;
}