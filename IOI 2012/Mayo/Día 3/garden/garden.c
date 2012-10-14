#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "gardenlib.h"
#include "garden.h"

#define MAXNUM 600010
#define INF 987654321

typedef struct {
	int node, next, dist;
} state;

typedef struct {
	int dist1, dist2;
} dist;

typedef struct {
	int beauty1, beauty2;
	int node1, node2;
} _temp;

typedef struct {
	int node, next;
} node;

static _temp temp[MAXNUM];

static node graph[MAXNUM];
static int nextNode = 1;
static int start[MAXNUM];

static int outgoing[MAXNUM];

static bool cycle1, cycle2;
static int cycle1Size, cycle2Size;

static dist info[MAXNUM];

static state stack[MAXNUM];
static int nextStack;

static bool visited[4][MAXNUM];

static void dfs(int a, int b, int N){
	stack[0].node = a;
	stack[0].next = start[a];
	stack[0].dist = 0;
	nextStack = 1;
	visited[0][a] = true;

	while (nextStack){
		state curr = stack[nextStack-1];

		if (curr.next){
			if (graph[curr.next].node == a) {
				cycle1 = true;
				cycle1Size = curr.dist + 1;
				stack[nextStack-1].next = graph[curr.next].next;
			} else if (!visited[0][graph[curr.next].node]){
				stack[nextStack].node = graph[curr.next].node;
				stack[nextStack].next = start[graph[curr.next].node];
				stack[nextStack].dist = curr.dist + 1;
				stack[nextStack-1].next = graph[curr.next].next;
				nextStack++;
			} else {
				stack[nextStack-1].next = graph[curr.next].next;
			}
		} else {
			info[curr.node].dist1 = curr.dist;
			visited[0][curr.node] = true;
			nextStack--;
		}
	}

	stack[0].node = b;
	stack[0].next = start[b];
	stack[0].dist = 0;
	nextStack = 1;
	visited[1][b] = true;

	while (nextStack){
		state curr = stack[nextStack-1];

		if (curr.next){
			if (graph[curr.next].node == b) {
				cycle2 = true;
				cycle2Size = curr.dist + 1;
				stack[nextStack-1].next = graph[curr.next].next;
			} else if (!visited[1][graph[curr.next].node]){
				stack[nextStack].node = graph[curr.next].node;
				stack[nextStack].next = start[graph[curr.next].node];
				stack[nextStack].dist = curr.dist + 1;
				stack[nextStack-1].next = graph[curr.next].next;
				nextStack++;
			} else {
				stack[nextStack-1].next = graph[curr.next].next;
			}
		} else {
			info[curr.node].dist2 = curr.dist;
			visited[1][curr.node] = true;
			nextStack--;
		}
	}
}

void count_routes(int N, int M, int P, int R[][2], int Q, int G[]){
	int i, j;

	for (i = 0; i < N; i++)
		temp[i].beauty1 = temp[i].beauty2 = INF;

	for (i = 0; i < N*2; i++)
		info[i].dist1 = info[i].dist2 = INF;

	for (i = 0; i < M; i++){
		if (i < temp[R[i][0]].beauty1){ 
			temp[R[i][0]].beauty1 = i; 
			temp[R[i][0]].node1 = R[i][1]; 
		} else if (i < temp[R[i][0]].beauty2) { 
			temp[R[i][0]].beauty2 = i; 
			temp[R[i][0]].node2 = R[i][1]; 
		}

		if (i < temp[R[i][1]].beauty1){ 
			temp[R[i][1]].beauty1 = i; 
			temp[R[i][1]].node1 = R[i][0]; 
		} else if (i < temp[R[i][1]].beauty2) { 
			temp[R[i][1]].beauty2 = i; 
			temp[R[i][1]].node2 = R[i][0]; 
		}
	}

	for (i = 0; i < N; i++){
		if (temp[i].beauty2 == INF){
			temp[i].beauty2 = temp[i].beauty1;
			temp[i].node2 = temp[i].node1;
		}
	}

	for (i = 0; i < N; i++){
		if (temp[temp[i].node1].beauty1 == temp[i].beauty1)
			outgoing[i] = temp[i].node1+N;
		else
			outgoing[i] = temp[i].node1;
	}

	for (i = N; i < N*2; i++){
		if (temp[temp[i-N].node2].beauty1 == temp[i-N].beauty2)
			outgoing[i] = temp[i-N].node2+N;
		else
			outgoing[i] = temp[i-N].node2;
	}

	for (i = 0; i < N*2; i++){
		graph[nextNode].node = i;
		graph[nextNode].next = start[outgoing[i]];
		start[outgoing[i]] = nextNode++;
	}

	dfs(P, P+N, N);
	
	for (i = 0; i < Q; i++){
		int ans = 0;

		for (j = 0; j < N; j++){
			int dist1 = G[i] - info[j].dist1;
			int dist2 = G[i] - info[j].dist2;

			if (dist1 == 0 || (cycle1 && dist1 >= 0 && dist1 % cycle1Size == 0))
				ans++;
			else if (dist2 == 0 || (cycle2 && dist2 >= 0 && dist2 % cycle2Size == 0))
				ans++;
		}

		answer(ans);
	}
}

