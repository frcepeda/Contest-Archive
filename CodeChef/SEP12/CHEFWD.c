#include <stdio.h>

#define DEBUG 0

#define MOD 1000000007

long long unsigned int matrix[4][4];
const unsigned int orig[4][4] = 	{{1, 1, 1, 1},
					 {1, 0, 0, 0},
					 {0, 0, 1, 1},
					 {0, 0, 1, 0}};

unsigned long long int curr[4];
const unsigned int start[4] = {0,0,3,2};

void printmatrix(void){
#if DEBUG
	int i,j,k;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
				printf("%llu ", matrix[i][j]);
		}
		printf("\n");
	} 
	printf("\n"); // */
#endif
}

void square(){
	static long long unsigned int tmp[4][4];
	int i, j, k;

	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			tmp[i][j] = matrix[i][j];
			matrix[i][j] = 0;
		}
	}

	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			for (k = 0; k < 4; k++){
				matrix[i][j] += tmp[i][k] * tmp[k][j];
			}
			matrix[i][j] %= MOD;
		}
	}

	printmatrix();
}

void multiply(void){
	int i,j,k;

	for (j = 0; j < 4; j++)
		curr[j] = 0;

	for (j = 0; j < 4; j++)
		for (k = 0; k < 4; k++)
			curr[j] += start[k] * matrix[j][k];

	printmatrix();
}

void multiplyonce(void){
	static long long unsigned int tmp[4][4];
	int i, j, k;

	for (j = 0; j < 4; j++){
		for (i = 0; i < 4; i++){
			tmp[i][j] = matrix[i][j];
			matrix[i][j] = 0;
		}
	}

	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			for (k = 0; k < 4; k++){
				matrix[i][j] += orig[i][k] * tmp[k][j];
			}
			matrix[i][j] %= MOD;
		}
	}

	printmatrix();
}

void exponentiate(unsigned long long int N){
	int i, j;
	switch (N){
		case 0:
		case 1:
			for (i = 0; i < 4; i++)
				for (j = 0; j < 4; j++)
					matrix[i][j] = orig[i][j];
			return;
		default:
			if (N % 2 == 0){
				exponentiate(N/2);
				square();
			} else {
				exponentiate(N/2);
				square();
				multiplyonce();
			}
			return;
	}
}

int main(void){
	unsigned long long int T, N;

	scanf("%llu", &T);

	while (T--){
		scanf("%llu", &N);
		if (N < 2){
			printf("0\n");
		} else {
			exponentiate(N-1);
			multiply();
#if DEBUG
			printf("{%llu, %lld, %lld, %lld}\n", curr[0], curr[1], curr[2], curr[3]);
#endif
			printf("%llu\n", (curr[0] + curr[1]) % MOD);
		}
	}

	return 0;
}

