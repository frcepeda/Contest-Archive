#include <stdbool.h>
#include <assert.h>
#include <strings.h>
#include <stdio.h>
#include "grader.h"
#include "encoder.h"

static unsigned long long int threeTothe[41] = {
	1ULL, 3ULL, 9ULL, 27ULL, 81ULL, 243ULL, 729ULL, 2187ULL, 6561ULL,
	19683ULL, 59049ULL, 177147ULL, 531441ULL, 1594323ULL, 4782969ULL,
	14348907ULL, 43046721ULL, 129140163ULL, 387420489ULL, 1162261467ULL,
	3486784401ULL, 10460353203ULL, 31381059609ULL, 94143178827ULL,
	282429536481ULL, 847288609443ULL, 2541865828329ULL, 7625597484987ULL,
	22876792454961ULL, 68630377364883ULL, 205891132094649ULL, 617673396283947ULL,
	1853020188851841ULL, 5559060566555523ULL, 16677181699666568ULL, 50031545098999704ULL,
	150094635296999136ULL, 450283905890997380ULL, 1350851717672992000ULL,
	4052555153018976300ULL, 12157665459056929000ULL, 
};

static void encodeBits(unsigned long long int buffer, int amount){
	unsigned int bit;
	while (amount--){
		bit = buffer & 1;
		buffer >>= 1;
		encode_bit(bit);
	}
}

#define MAXCITIES 2000
#define MAXHUBS 50 

#define MAXPERBYTE 5
#define INFINITY (1<<25)

typedef struct {
	int node, distance;
} state;

static state makeState(int node, int distance){
	state s = {node, distance};
	return s;
}

static bool adjacent[MAXCITIES][MAXCITIES];

static int bestDistances[MAXHUBS][MAXCITIES];
static int parent[MAXCITIES];

static int cases[MAXHUBS][MAXCITIES];

static bool visited[MAXCITIES];

static state queue[MAXCITIES];
static int qs, qe;
#define push(a) queue[qe++] = (a)
#define pop() queue[qs++]

static int min(int a, int b) {
	return a < b ? a : b;
}

static void bfs(int start, int nv, int buildTree){
	int i;

	memset(visited, false, sizeof(visited));

	qs = qe = 0;
	visited[start] = true;
	push(makeState(start, 0));

	while (qs < qe){
		state curr = pop();
		bestDistances[start][curr.node] = curr.distance;
		for (i = 0; i < nv; i++){
			if (!adjacent[curr.node][i] || visited[i])
				continue;
			if (buildTree)
				parent[i] = curr.node;
			visited[i] = true;
			push(makeState(i, curr.distance + 1));
		}
	}
}

void encode(int nv, int nh, int ne, int *v1, int *v2){
	int i, j, k;

	for (i = 0; i < ne; i++){
		adjacent[v1[i]][v2[i]] = true;
		adjacent[v2[i]][v1[i]] = true;
	}

	bfs(0, nv, true);
	for (i = 1; i < nh; i++){
		bfs(i, nv, false);
	}

	for (i = 0; i < nh; i++){
		for (j = 0; j < nv; j++){
			int best = bestDistances[i][j];
			int parentDistance = bestDistances[i][parent[j]];

			assert(abs(best - parentDistance) <= 1);

			cases[i][j] = best - parentDistance;
			cases[i][j]++;
		}
	}

	for (i = 0; i < nv; i++){
		encodeBits(parent[i], 10);
	}

	for (i = 0; i < nh; i++){
		for (j = 0; j < nv; j += k){
			int buffer = 0;
			for (k = 0; k < MAXPERBYTE && k + j < nv; k++){
				buffer += threeTothe[k] * cases[i][j+k];
			}
			encodeBits(buffer, 8);
		}
	}
}

