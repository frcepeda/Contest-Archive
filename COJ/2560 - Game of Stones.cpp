#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 1000000007
#define MAXN 1010

int N;

bool v[MAXN][MAXN][2];
unsigned int dp[MAXN][MAXN][2];

unsigned int f(int i, int j, bool z){
	if (i == 0) return z;
	if (i < j) return 0;
	if (v[i][j][z]) return dp[i][j][z];
	v[i][j][z] = true;

	dp[i][j][z] = f(i, j+1, z);
	if (i >= j)
		dp[i][j][z] = (dp[i][j][z] + f(i-j, j, (z + j+1) % 2)) % MOD;

	return dp[i][j][z];
}

int main(){
	scanf("%d", &N);
	printf("%u\n", f(N, 1, 0));
}
