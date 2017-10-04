#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int n, a;
const int maxn = 10000, maxv = 20100, off = 10000;
int dp[maxn][maxv], vv[maxn][maxv], x[maxn];

int f(int i, int v){
	if (i == n) return abs(v - a);
	if (vv[i][v+off]) return dp[i][v+off];
	vv[i][v+off] = true;

	return dp[i][v+off] = min(
		f(i+1, v + x[i]),
		f(i+1, v - x[i])
	);
}

void go(int i, int v){
	if (i == n) return;

	if (f(i+1, v + x[i]) <= f(i+1, v - x[i])){
		printf("+%d", x[i]);
		go(i+1, v + x[i]);
	} else {
		printf("-%d", x[i]);
		go(i+1, v - x[i]);
	}
}

int main(){
	scanf("%d %d", &n, &a);

	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	int k = f(1, x[0]);
	printf("%d\n%d", k, x[0]);
	go(1, x[0]);
	putchar('\n');
}
