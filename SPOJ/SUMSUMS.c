#include <stdio.h>

/*

Explanation:

Define vector V as {C_0, C_1, ..., C_{N-1}}^T.
Now, we can simulate one step of the algorithm with the transformation
matrix M, which is obtained by taking the identity matrix and switching
all 0s for 1s and vice versa.

Therefore, the values of the cows at step k is M^k * V.

However, computing M^k naively would take O(N^3 lg k) time, which will
not run in the alloted time.

It's easy to notice that M^k consists of only two values, henceforth
x and y, x being the value that is in the main diagonal and y in the
rest of the cells.

We can also think of x as the times cow i at step k has C_i, and y as
the times it has C_j for all j != i. Therefore, at step k+1, cow i will
have C_i (N-1)*y times, and C_j x + (N-2)*y times. This suggests making
a new transformation matrix to compute the values of x and y efficiently.

*/

#define MOD 98765431
#define MAXN 50010

typedef struct {
	long long int m00, m01, m10, m11;
} mat;

mat matMult(mat a, mat b){
	mat m = {
		.m00 = (a.m00 * b.m00 + a.m01 * b.m10) % MOD,
		.m01 = (a.m00 * b.m01 + a.m01 * b.m11) % MOD,
		.m10 = (a.m10 * b.m00 + a.m11 * b.m10) % MOD,
		.m11 = (a.m10 * b.m01 + a.m11 * b.m11) % MOD,
	};
	return m;
}

mat matExp(mat a, int p){
	mat ans = {.m00 = 1, .m01 = 0, .m10 = 0, .m11 = 1};
	mat base = a;

	for (; p; p >>= 1){
		if (p % 2 == 1)
			ans = matMult(ans, base);
		base = matMult(base, base);
	}

	return ans;
}

int N, T;
int C[MAXN];

long long int x, y;
long long int sum;
int diff;

int main(void){
	int i;

	scanf("%d %d", &N, &T);

	for (i = 0; i < N; i++)
		scanf("%d", &C[i]);

	mat transform = {.m00 = 0, .m01 = N-1, .m10 = 1, .m11 = N-2};
	transform = matExp(transform, T);

	x = transform.m00;
	y = transform.m10;

	diff = y - x;

	for (i = 0; i < N; i++)
		sum = (sum + C[i] * y) % MOD;

	for (i = 0; i < N; i++)
		printf("%lld\n", (sum - ((C[i] * diff) % MOD) + MOD) % MOD);

	return 0;
}
