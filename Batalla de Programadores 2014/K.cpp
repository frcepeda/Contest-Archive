#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXC 100100

int C, N;
int acc[MAXC], acc2[MAXC];

int main(void){
	int i, j;

	scanf("%d %d", &C, &N);

	for (i = 0; i < N; i++){
		scanf("%d", &j);
		acc[j] = 1;
	}

	N = C / N;
	for (i = j = 0; i < N; i++)
		j += acc[i];

	acc2[0] = j;
	for (i = 1; i < C; i++){
		j += acc[(i+N-1)%C] - acc[(i+C-1)%C];
		acc2[i] = j;
	}

	for (i = 0; i < N; i++){
		for (j = 0; j < C/N; j++)
			if (acc2[i + N * j] != 1)
				break;
		if (j == C/N) break;
	}

	printf("%c\n", i < N ? 'S' : 'N');
}
