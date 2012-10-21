#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <strings.h>
#include <assert.h>

#define MAXNODES 2000
#define MAXN 10

typedef struct {
	int a, b;
	int outgoing;
	int next[2];
} node;

typedef struct {
	int thing, next;
} list;

list answer[110];
int nextlist = 1;

bool startcandidate[MAXNODES];
int where[MAXN][MAXN][100];
node nodes[MAXNODES];
int nextNode = 1;

int N;

bool visited[MAXNODES];

void findsequence(int node){
	visited[node] = true;

	if (node == 0)
		return;

	int i;
	for (i = 0; i < nodes[node].outgoing; i++)
		if (!visited[nodes[node].next[i]])
			findsequence(nodes[node].next[0] = nodes[node].next[i]);

	nodes[node].outgoing = 1;
}

int main(void){
	int i, j, a, b;

	scanf("%d", &N);

	for (i = 2; i <= N; i++){
		char tmp[110];
		int counts[MAXN] = {0};
		int prev = 0;

		scanf("%s", tmp);
		for (j = strlen(tmp)-1; j >= 0; j--){
			if (isdigit(tmp[j])){
				tmp[j] -= '0';
				if (i < tmp[j]){
					a = i;
					b = tmp[j];
				} else {
					a = tmp[j];
					b = i;
				}

				int node = where[a][b][counts[tmp[j]]];

				if (!node){
					node = where[a][b][counts[tmp[j]]] = nextNode++;

					nodes[node].a = a;
					nodes[node].b = b;

					startcandidate[node] = true;
				}

				startcandidate[prev] = false;
				nodes[node].next[nodes[node].outgoing++] = prev;

				prev = node;

				counts[tmp[j]]++;
			}
		}
	}

	int start = -1;
	int possibilities[100];
	int posnum = 0;
	for (i = 1; i < nextNode; i++){
		if (startcandidate[i]){
			findsequence(i);
			possibilities[posnum++] = i;
		}
	}

	int currlist = 0;
	for (i = posnum-1; i >= 0; i--){
		int curr = possibilities[i];
		for (; curr != 0; curr = nodes[curr].next[0]){
			if (nodes[curr].a == 1){
				printf("%d", nodes[curr].b);
			}
		}
	}
	printf("\n");

	return 0;
}

