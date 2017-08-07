#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1010;

int T, t, N;

typedef long long ll;

const ll mod = 1000000007;

bool a[maxn];
ll dp[maxn][maxn];
int v[maxn][maxn];

ll f(int i, int j){
	if (j < i) return 1;
	if (i == j) return !a[i];

	if (v[i][j] == t) return dp[i][j];

	v[i][j] = t;
	dp[i][j] = 0;

	if (!a[i])
		return dp[i][j] = f(i+1, j);

	for (int k = i+1; k <= j; k++)
		dp[i][j] = (dp[i][j] + f(i+1, k) * f(k+1, j)) % mod;

	return dp[i][j];
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

	for (t = 1; t <= T; t++){
		cin >> N;

		for (int i = 0; i < N; i++){
			string t;
			cin >> t;
			a[i] = t == "f";
		}

		cout << f(0, N-1) % mod << endl;
		cerr << t << endl;
	}
}
