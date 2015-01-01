#include <cstdio>
using namespace std;

long long p, q, n;

int A[2][2];

void mult(long long a[2][2], long long b[2][2]){
	int i, j, k;
	long long c[2][2] = {{0}};
	
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			for (k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];
				
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			a[i][j] = c[i][j];
}

int main() {
	long long n, b;
	
	A[1][0] = 1; A[1][1] = 0;
	
	while (scanf("%llu %llu %llu", &p, &q, &n) == 3){
		A[0][0] = p;
		A[0][1] = -q;
		
		if (n == 0){
			printf("2\n");
			continue;
		}
		
		long long B[2][2];
		
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				B[i][j] = A[i][j];
		
		long long m[2][2] = {{1,0},{0,1}};
		
		for (n--; n; n /= 2){
			if (n % 2)
				mult(m, B);
			mult(B, B);
		}
		
		printf("%lld\n", m[0][0] * p + m[0][1] * 2);
	}
}
