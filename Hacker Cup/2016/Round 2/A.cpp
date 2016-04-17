#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100010
#define MAXC 256

int T, N;
int dp1[MAXN][MAXC], dp2[MAXN][MAXC];
char A[MAXN], B[MAXN];
int ll[MAXN], rr[MAXN];

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		cin >> N >> (A+1) >> (B+1);

		fill(dp1[N+1], dp1[N+1]+MAXC, 0);

		for (int i = 1; i <= N; i++){
			for (int j = 'A'; j <= 'Z'; j++){
				if (j == B[i])
					dp1[i][j] = dp1[i-1][j];
				else
					dp1[i][j] = 1 + dp1[i-1][B[i]];
			}
		}

		for (int i = N; i >= 1; i--){
			for (int j = 'A'; j <= 'Z'; j++){
				if (j == B[i])
					dp2[i][j] = dp2[i+1][j];
				else
					dp2[i][j] = 1 + dp2[i+1][B[i]];
			}
		}

		rr[0] = rr[N+1] = 0;
		for (int i = 1; i <= N; i++){
			if (A[i] == B[i])
				ll[i] = ll[i-1];
			else
				ll[i] = dp1[i][B[i]] + 1;
		}

		for (int i = N; i >= 1; i--){
			if (A[i] == B[i])
				rr[i] = rr[i+1];
			else
				rr[i] = dp2[i][B[i]] + 1;
		}

		int ans = 1<<30;
		for (int i = 1; i <= N+1; i++)
			ans = min(ans, max(ll[i-1], rr[i]));

		cout << "Case #" << t << ": " << ans << endl;
	}
}
