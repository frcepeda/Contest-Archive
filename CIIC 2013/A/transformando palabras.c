#include <stdio.h>

#define MAXN 75

typedef struct {
	long long int m[3][3];
} mat;

const mat trans = {
	.m = {
		{1,1,1},
		{1,0,0},
		{0,1,0}
	}
};

mat matMult(mat a, mat b){
	mat c = {.m = {{0}}};
	int i, j, k;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				c.m[i][j] += a.m[i][k] * b.m[k][j];
	return c;
}

int C, N;
long long int K;
long long int stringLength[MAXN];
int right[3] = {1, 2, -1}; // A -> AB, B -> AC, C -> A

int query(int c, long long int k, int rem){
	if (rem == 0)
		return c;

	if (c == 2)
		return query(0, k, rem-1);

	long long int leftSubtree = stringLength[rem-1];

	if (k <= leftSubtree)
		return query(0, k, rem-1);
	else
		return query(right[c], k - leftSubtree, rem-1);
}

int main(void){
	int i;

	scanf("%d", &C);

	mat curr = trans;
	stringLength[0] = 1; // S0 = "A"

	for (i = 1; i < MAXN; i++, curr = matMult(curr, trans))
		stringLength[i] = curr.m[0][0] + curr.m[1][0] + curr.m[2][0];

	while (C--){
		scanf("%d %lld", &N, &K);
		printf("%c\n", query(0,K,N-1) + 'A');
	}

	return 0;
}
