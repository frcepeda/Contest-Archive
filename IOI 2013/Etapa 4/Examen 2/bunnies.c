#include <stdio.h>
#include <stdlib.h>

#define MAXT 11000000
#define MOD 1000000009

int jumps[MAXT];
int N, M;

int f(int x){
	if (x < MAXT && jumps[x])
		return jumps[x];
	else if (x == 1)
		return 0;
	else if (x % M == 0)
		return jumps[x] = f(x/M)+1;
	else
		return jumps[x] = f(x+1)+1;
}

unsigned int answer;

int main(void){
	int i;

	scanf("%d %d", &M, &N);

	for (i = 1; i < 1000000; i++)
		if (f(i) == N)
			answer++;

	printf("%u\n", answer);

	return 0;
}
