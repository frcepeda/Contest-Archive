#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <strings.h>
#include <assert.h>

#define MAXNODES 100
#define MAXN 20

typedef struct {
	int a, b;
	int outgoing;
	int next[1000];
} node;

bool startcandidate[MAXNODES];
int where[MAXN][MAXN];
node nodes[MAXNODES];
int nextNode = 1;

int N;

bool visited[MAXNODES];

void findsequence(int node){
	visited[node] = true;

	if (node == 0)
		return;

	int i;
	for (i = 0; i < nodes[node].outgoing; i++){
		if (!visited[nodes[node].next[i]]){
			nodes[node].next[0] = nodes[node].next[i];
			findsequence(nodes[node].next[0]);
		}
	}
	nodes[node].outgoing = 1;
}

int main(void){
	int i, j, a, b;

	scanf("%d", &N);

	for (i = 2; i <= N; i++){
		char tmp[110];
		int prev = 0;

		scanf("%s", tmp);
		for (j = strlen(tmp)-1; j >= 0; j--){
			if (isdigit(tmp[j])){
				if (i < tmp[j] - '0'){
					a = i;
					b = tmp[j] - '0';
				} else {
					a = tmp[j] - '0';
					b = i;
				}

				int node = where[a][b];

				if (!node){
					where[a][b] = nextNode++;
					node = where[a][b];

					nodes[node].a = a;
					nodes[node].b = b;
					nodes[node].outgoing = 1;

					startcandidate[node] = true;
				} else {
					nodes[node].outgoing++;
				}

				startcandidate[prev] = false;
				nodes[node].next[nodes[node].outgoing-1] = prev;

				prev = node;
			}
		}
	}

	int start = -1;
	for (i = 1; i < nextNode; i++){
		if (startcandidate[i]){
			findsequence(i);
			start = i;
		}
	}

	assert(start != -1);
	return 0;

	int curr = start;

	for (; curr != 0; curr = nodes[curr].next[0]){
		if (nodes[curr].a == 1)
			printf("%d", nodes[curr].b);
	}
	printf("\n");

	return 0;
}

