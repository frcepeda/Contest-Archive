#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int k, n;
int a[3010];
bool v[3010][3010];
ll dp[3010][3010];

ll g(int i, ll lx, ll ly, ll rx, ll ry){
	if (i == n-1) return 0;

	return (a[i+1] - a[i]) * (lx * ry + ly * rx);
}

ll f(int i, int r){
	if (v[i][r])
		return dp[i][r];
	v[i][r] = true;

	if (i == n) return 0;

	int lx = k - r;
	int ly = i - lx;
	int rx = r;
	int ry = n - i - rx;

	dp[i][r] = 1LL<<60;

	if (rx)
		dp[i][r] = min(dp[i][r], f(i+1, r-1) + g(i, lx+1, ly, rx-1, ry));

	if (ry)
		dp[i][r] = min(dp[i][r], f(i+1, r) + g(i, lx, ly+1, rx, ry-1));

	return dp[i][r];
}

int main(){
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	cout << f(0, k) << endl;
}
