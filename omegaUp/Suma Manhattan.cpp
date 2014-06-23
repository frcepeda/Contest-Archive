#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 500010
#define MOD 1000000007

int N;
int points[2][MAXN];

int solve(int *p){
	int i, ret = 0;

	sort(p, p + N);

	for (i = 0; i < N; i++)
		ret = (ret + (long long)p[i] * (2*i - N + 1)) % MOD;

	return ret + (ret < 0 ? MOD : 0);
}

int main(){
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		scanf("%d %d", &points[0][i], &points[1][i]);

	printf("%d\n", (solve(points[0]) + solve(points[1])) % MOD);
}