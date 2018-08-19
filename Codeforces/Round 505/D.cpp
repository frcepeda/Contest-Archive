#pragma GCC optimize ("O3")

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<bool> vb;

const int maxn = 701;
int n, a[maxn];
bool can[maxn][maxn], v[2][maxn][maxn], dp[2][maxn][maxn];

bool f(int l, int r, bool d){
	if (l > r) return true;
	if (v[d][l][r]) return dp[d][l][r];
	v[d][l][r] = true;

	int j = d ? r+1 : l-1;

	for (int i = l; i <= r; i++)
		if (can[i][j] && f(l, i-1, 1) && f(i+1, r, 0))
			return dp[d][l][r] = true;

	return false;
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			can[i][j] = __gcd(a[i], a[j]) > 1;

	bool works = false;
	for (int i = 0; i < n && !works; i++)
		works = f(0, i-1, 1) && f(i+1, n-1, 0);

	printf("%s\n", works ? "Yes" : "No");
}
