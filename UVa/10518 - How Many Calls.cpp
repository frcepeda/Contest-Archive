#include <cstdio>
using namespace std;

unsigned long long N, B;

const int A[3][3] = {{1,1,1},{1,0,0},{0,0,1}};

void mult(int a[3][3], int b[3][3]){
	int i, j, k;
	int c[3][3] = {{0}};
	
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				c[i][j] += a[i][k] * b[k][j];
				
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			a[i][j] = c[i][j] % B;
}

int main() {
	unsigned long long n, b;
	
	for (int t = 1; scanf("%llu %llu", &n, &b), (n || b); t++){
		N = n; B = b;
		
		if (n <= 1){
			printf("Case %d: %d %d %d\n", t, N, b, 1 % b);
			continue;
		}
		
		int B[3][3];
		
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				B[i][j] = A[i][j];
		
		int m[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
		int i, j, k;
		
		for (n--; n; n /= 2){
			if (n % 2)
				mult(m, B);
			mult(B, B);
		}
		
		printf("Case %d: %llu %llu %d\n", t, N, b, (m[0][0] + m[0][1] + m[0][2]) % b);
	}
}
