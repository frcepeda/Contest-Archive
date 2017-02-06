#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 16;
const int maxs = 16*17/2 + 1;
int n;
int dp[1<<maxn][maxs], dq[1<<maxn][maxs];
bool t[maxn];
int r[maxn], b[maxn], cr[1<<maxn], cb[1<<maxn], ct[1<<maxn];

int lg2(int x){
	int r = -1;
	for (; x; r++, x /= 2);
	return r;
}

int main(){
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		char tmp[2];
		scanf("%[RB] %d %d", tmp, &r[i], &b[i]);
		t[i] = tmp[0] == 'B';
	}

	for (int k = 1; k < (1 << n); k++){
		int i = lg2(k&-k);
		cr[k] = r[i] + cr[k^(1<<i)];
		cb[k] = b[i] + cb[k^(1<<i)];
		ct[k] = t[i] + ct[k^(1<<i)];
	}

	for (int k = 0; k < (1<<n); k++)
		for (int sr = 0; sr < maxs; sr++)

	for (int k = (1<<n)-1; k >= 0; k--){
		for (int sr = 0; sr < maxs; sr++){
			int sb = dq[k][sr];

			int R = cr[k] - sr;
			int B = cb[k] - sb;

			int B = ct[k];
			int A = __builtin_popcount(k) - B;

			for (int i = 0; i < n; i++){
				if (k & (1<<i)) continue;

				int svr = min(A, r[i]);
				int svb = min(B, b[i]);

				dp[k][sr] = min(
					dp[k][sr],
					max(
						max(0, r[i] - svr - R),
						max(0, b[i] - svb - B)
					) + dp[k^(1<<i)][sr + svr]
				);
			}
		}
	}

	printf("%d\n", dp[0][0]);
}
