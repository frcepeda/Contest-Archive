#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "grader.h"
#include "decoder.h"

typedef struct {
	int node, distance;
} state;

static state makeState(int node, int distance){
	state s = {node, distance};
	return s;
}

static unsigned long long int decodeBits(int amount){
	unsigned long long int buffer = 0, reverse = 0;
	int i;
	for (i = 0; i < amount; i++){
		buffer <<= 1;
		buffer += decode_bit();
	}
	for (i = 0; i < amount; i++){
		reverse <<= 1;
		reverse += buffer & 1;
		buffer >>= 1;
	}
	return reverse;
}

#define MAXCITIES 1000
#define MAXHUBS 36

#define MAXPERBYTE 5
#define INFINITY (1<<25)

static int parent[MAXCITIES];

static int getCase(void){
	static int buffer = 0;
	static int remaining = -1;
	if (remaining <= 0){
		buffer = decodeBits(8);
		remaining = MAXPERBYTE;
	}

	int answer = buffer % 3;
	buffer /= 3;
	
	remaining--;

	return answer - 1;
}

static int cases[MAXHUBS][MAXCITIES];
static int distances[MAXHUBS][MAXCITIES];

static void calculateDistance(int i){
	if (!i) return;
	if (!distances[0][parent[i]])
		calculateDistance(parent[i]);
	distances[0][i] = distances[0][parent[i]] + 1;
}

static bool adjacent[MAXCITIES][MAXCITIES];
static bool visited[MAXCITIES];

static state queue[MAXCITIES];
static int qs, qe;
#define push(a) queue[qe++] = (a)
#define pop() queue[qs++]

static void bfs(int nv, int nh){
	int i;

	qs = qe = 0;
	visited[0] = true;
	push(makeState(0, 0));

	while (qs < qe){
		state curr = pop();
		if (curr.node != 0){
			for (i = 0; i < nh; i++){
				distances[i][curr.node] = distances[i][parent[curr.node]] + cases[i][curr.node];
				assert(distances[i][curr.node] >= 0);
			}
		}
		for (i = 0; i < nv; i++){
			if (!adjacent[curr.node][i] || visited[i])
				continue;
			visited[i] = true;
			push(makeState(i, curr.distance + 1));
		}
	}
}

void decode(int nv, int nh) {
	int i, j;

	for (i = 0; i < nv; i++){
		parent[i] = (int)decodeBits(10);
		//adjacent[i][parent[i]] = true; // Only go down the tree.
		adjacent[parent[i]][i] = true;
	}

	for (i = 0; i < nh; i++){
		for (j = 0; j < nv; j++){
			cases[i][j] = getCase();
		}
	}

	for (i = 1; i < nv; i++){
		if (!distances[0][i])
			calculateDistance(i);
	}

	for (i = 0; i < nh; i++){
		distances[i][0] = distances[0][i];
	}

	bfs(nv, nh);
	
	for (i = 0; i < nh; i++){
		for (j = 0; j < nv; j++){
			hops(i,j,distances[i][j]);
		}
	}
}

