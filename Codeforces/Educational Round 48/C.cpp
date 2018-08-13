#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 300100;
int n, g[2][maxn];
ll sum[maxn], turn[2][maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	for (ll i = n-1; i >= 0; i--){
		sum[i] = sum[i+1] + g[0][i] + g[1][i];
		for (int j = 0; j < 2; j++)
		turn[j][i] = sum[i+1] + turn[j][i+1] + g[!j][i] * (2*(n-i) - 1);
	}

	ll ans = 0, acc = 0;
	bool w = 0;

	for (ll i = 0; i < n; i++){
		ans = max(ans, acc + turn[w][i] + sum[i] * 2*i);
		acc += g[w][i] * 2*i + g[!w][i] * (2*i + 1);
		w = !w;
	}

	cout << ans << endl;
}
