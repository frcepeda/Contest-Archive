/*
    ID: frceped1
    LANG: C
    TASK: clocks
 */

#include <stdio.h>
#include <strings.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("clocks.in", "r"); out = fopen("clocks.out", "w")
	#define getchar() fgetc(in)
	#define putchar(c) fputc(c, out)
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

#define CLOCKNUM 9
#define MOVENUM 9
#define STATENUM 4
#define MAXQUEUE 500000

typedef struct {
	int parent;
	short move;
	short clocks[CLOCKNUM];
} step;

short clocks[CLOCKNUM];

short moves[MOVENUM][CLOCKNUM] = { 
	{1,1,0,1,1},
	{1,1,1},
	{0,1,1,0,1,1},
	{1,0,0,1,0,0,1},
	{0,1,0,1,1,1,0,1},
	{0,0,1,0,0,1,0,0,1},
	{0,0,0,1,1,0,1,1},
	{0,0,0,0,0,0,1,1,1},
	{0,0,0,0,1,1,0,1,1}
};

short visited[4][4][4][4][4][4][4][4][4];
#define c(s,i) s.clocks[i]
#define getVisited(s) visited[c(s,0)][c(s,1)][c(s,2)][c(s,3)][c(s,4)][c(s,5)][c(s,6)][c(s,7)][c(s,8)]
#define isEnd(s) (!c(s,0) && !c(s,1) && !c(s,2) && !c(s,3) && !c(s,4) && !c(s,5) && !c(s,6) && !c(s,7) && !c(s,8))

step queue[MAXQUEUE];
int qs, qe;
#define queueIsNotEmpty qs < qe
step start = {-1,-1,{0}};

void push(step s){
	queue[qe++] = s;
}

step pop(void){
	return queue[qs++];
}

step search(void){
	push(start);

	getVisited(start) = 1;
	
	while (queueIsNotEmpty){
		step curr = pop();

		if (isEnd(curr)) return curr;

		int i, j;
		for (i = 0; i < MOVENUM; i++){
			step next = curr;
			next.parent = qs-1; // popped index
			next.move = i+1;
			for (j = 0; j < CLOCKNUM; j++){
				next.clocks[j] += moves[i][j];
				next.clocks[j] %= STATENUM;
			}
			if (!getVisited(next)){
				push(next);
				getVisited(next) = 1;
			}
		}
	}
}

void reconstruct(step s, short first){
	if (s.parent == -1) return;
	reconstruct(queue[s.parent], 0);
	print("%d%c", s.move, first ? '\n' : ' ');
}

int main(void){
	openFiles();
	int i;

	for (i = 0; i < CLOCKNUM; i++){
		read("%hd", &start.clocks[i]);
		start.clocks[i] /= 3; // scale the statuses
		start.clocks[i] %= STATENUM;
	}

	reconstruct(search(), 1);

	return 0;
}
