#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 100100;
ll n, p, q, r, a[maxn];
ll dp[maxn][3];

int main(){
	cin >> n >> p >> q >> r;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	dp[0][0] = p * a[0];
	for (int i = 1; i < n; i++)
		dp[i][0] = max(dp[i-1][0], p * a[i]);

	dp[0][1] = q * a[0] + dp[0][0];
	for (int i = 1; i < n; i++)
		dp[i][1] = max(dp[i-1][1], q * a[i] + dp[i][0]);

	dp[0][2] = r * a[0] + dp[0][1];
	for (int i = 1; i < n; i++)
		dp[i][2] = max(dp[i-1][2], r * a[i] + dp[i][1]);

	cout << dp[n-1][2] << endl;
}
