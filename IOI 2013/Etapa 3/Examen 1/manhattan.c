#include <stdio.h>

#define MAXN 1000000

#define dist(a,b) (abs(a[0]-b[0])+abs(a[1]-b[1])+abs(a[2]-b[2])+abs(a[3]-b[3]))

int N;
int coord[MAXN][4];

int answer;

int abs(int a){
	if (a < 0)
		return -a;
	return a;
}

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d %d %d %d", &coord[i][0], &coord[i][1], &coord[i][2], &coord[i][3]);

	for (i = 0; i < N; i++)
		for (j = i+1; j < N; j++)
			answer = max(answer, dist(coord[i], coord[j]));

	printf("%d\n", answer);

	return 0;
}