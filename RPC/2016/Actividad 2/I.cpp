#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXS 1400

int T, S, F, L;
long double dp[MAXS][MAXS];

int main(){
	cin >> T;

	while (T--){
		cin >> S >> F >> L;

		dp[0][L-1] = 1;
		for (int i = 0; i < L-1; i++)
			dp[0][i] = 0;

		for (int i = 1; i < S; i++){
			dp[i][L-1] = 1;
			for (int j = 0; j < L-1; j++)
				dp[i][j] = dp[i-1][j+1]/2 + dp[i-1][0]/2;
		}

		long double p = dp[S-1][0] * pow(2,S-1) / (pow(2,S-1)-1);
		long double ans = p;

		for (int i = 2; i <= F; i++)
			ans += (1 - ans) * p;

		cout << fixed << setprecision(5) << ans << endl;
	}
}
