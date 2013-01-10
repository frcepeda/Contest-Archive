#include <stdio.h>

#define MAXN 260

int MIN[MAXN][MAXN];
int MAX[MAXN][MAXN];

int queue[MAXN*2];
int qs, qe;

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int tmp[MAXN];

int N, B, K;

int lessEqualThan(int a, int b){
	return a <= b;
}

int greaterEqualThan(int a, int b){
	return a >= b;
}

void getMaxMin(int arr[MAXN][MAXN], int row, int (*f)(int, int)){
	int i;
	qs = qe = 0;

	for (i = 0; i < B; i++){
		for (; qs < qe; qe--)
			if (f(tmp[i], queue[qe-1]))
				break;
		queue[qe++] = tmp[i];
	}
	arr[row][0] = queue[0];

	for (; i < N; i++){
		if (queue[qs] == tmp[i-B]) qs++;

		for (; qs < qe; qe--)
			if (f(tmp[i], queue[qe-1]))
				break;
		queue[qe++] = tmp[i];

		arr[row][i-B+1] = queue[qs];
	}
}

int query(int arr[MAXN][MAXN], int row, int col, int ret, int (*f)(int, int)){
	int i;
	for (i = 0; i < B; i++)
		ret = f(ret, arr[i+row][col]);
	return ret;
}

int main(void){
	int i, j;

	scanf("%d %d %d", &N, &B, &K);

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf("%d", &tmp[j]);
		}
		getMaxMin(MAX, i, lessEqualThan);
		getMaxMin(MIN, i, greaterEqualThan);
	}

	while (K--){
		int row, col;
		scanf("%d %d", &row, &col);
		printf("%d\n", query(MAX, row-1, col-1, 0, max) - query(MIN, row-1, col-1, 1<<20, min));
	}

	return 0;
}
