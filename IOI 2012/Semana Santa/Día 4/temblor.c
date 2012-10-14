#include <stdio.h>

#define MAXANSWER 200
#define MAXQUEUE 500000
#define MAXMAP 4

#define canGoNorth(a) (!(a & 1))
#define canGoEast(a)  (!(a & 2))
#define canGoSouth(a) (!(a & 4))
#define canGoWest(a)  (!(a & 8))

int map[MAXMAP][MAXMAP];
int state[MAXMAP][MAXMAP];

int width, height;

void bitsToState(int bits){
	int i,j;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			state[j][i] = bits & (1 << ((i*MAXMAP)+j)) ? 1 : 0;
}

int stateToBits(void){
	int i,j;
	int bits = 0;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			if (state[j][i])
				bits |= 1 << ((i*MAXMAP)+j);
	return bits;
}

char answer[MAXANSWER];

typedef struct {
	int parent, state;
	char movement;
} step;

step makeStep(int p, int s, int m){
	step a = {p,s,m};
	return a;
}

int visited[1<<16];
step queue[MAXQUEUE];
int qs, qe;

#define queueIsNotEmpty (qs < qe)

void push(step s){
	queue[qe++] = s;
}

step pop(void){
	return queue[qs++];
}

void north(void){
	int i,j;
	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			if (state[j][i] && canGoNorth(map[j][i])){
				state[j][i] = 0;
				if (i > 0){
					state[j][i-1] = 1;
				}
			}
		}
	}
}

void south(void){
	int i,j;
	for (i = height-1; i >= 0; i--){
		for (j = 0; j < width; j++){
			if (state[j][i] && canGoSouth(map[j][i])){
				state[j][i] = 0;
				if (i+1 < height){
					state[j][i+1] = 1;
				}
			}
		}
	}
}

void east(void){
	int i,j;
	for (i = 0; i < height; i++){
		for (j = width-1; j >= 0; j--){
			if (state[j][i] && canGoEast(map[j][i])){
				state[j][i] = 0;
				if (j+1 < width){
					state[j+1][i] = 1;
				}
			}
		}
	}
}

void west(void){
	int i,j;
	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			if (state[j][i] && canGoWest(map[j][i])){
				state[j][i] = 0;
				if (j > 0){
					state[j-1][i] = 1;
				}
			}
		}
	}
}

int search(int start){
	push(makeStep(-1,start,'W'));

	while (queueIsNotEmpty){
		step curr = pop();
		if (!curr.state) return qs-1;
		if (visited[curr.state]) continue;
		visited[curr.state] = 1;

		bitsToState(curr.state);
		north();
		push(makeStep(qs-1, stateToBits(), 'N'));

		bitsToState(curr.state);
		south();
		push(makeStep(qs-1, stateToBits(), 'S'));

		bitsToState(curr.state);
		east();
		push(makeStep(qs-1, stateToBits(), 'E'));

		bitsToState(curr.state);
		west();
		push(makeStep(qs-1, stateToBits(), 'O'));

	}
}

void print(int idx){
	if (queue[idx].parent == -1) return;
	print(queue[idx].parent);
	bitsToState(queue[idx].state);
	printf("%c", queue[idx].movement);
}

int main(void){
	int i,j;

	scanf("%d %d", &height, &width);

	int startstate = 0;
	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			scanf("%d", &map[j][i]);
			startstate |= 1 << ((i*MAXMAP)+j);
		}
	}

	print(search(startstate));
	printf("\n");

	return 0;
}

