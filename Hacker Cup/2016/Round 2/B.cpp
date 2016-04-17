#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

#define MAXN 3010

using namespace std;

int T, N, K;
long double p[MAXN], q[MAXN], choose[MAXN][MAXN], dp[MAXN], E[MAXN];

int main(){
	cin >> T;

	for (int i = 0; i < MAXN; i++){
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; j++)
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
	}

	p[0] = q[0] = 1;
	for (int t = 1; t <= T; t++){
		cin >> N >> K >> p[1];

		q[1] = 1 - p[1];
		for (int i = 2; i <= N; i++){
			p[i] = p[i-1] * p[1];
			q[i] = q[i-1] * q[1];
		}

		E[0] = 0;
		for (int i = 1; i <= N; i++){
			E[i] = 0;
			for (int j = K; j <= i; j++)
				E[i] += choose[i][j] * p[j] * q[i-j];
		}

		for (int i = 1; i <= N; i++){
			dp[i] = 0;
			for (int j = 1; j <= i; j++)
				dp[i] = max(dp[i], E[j] + dp[i-j]);
		}

		cout << "Case #" << t << ": " << setprecision(10) << dp[N] << endl;
	}
}
