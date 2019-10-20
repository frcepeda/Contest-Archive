#include <algorithm>
#include <cassert>
#include <cstdio>

using namespace std;

typedef long long ll;

const int maxn = 2010;
const int mod = 1000000007;
int n;
ll dp[maxn][maxn][2];
bool v[maxn][maxn][2];

ll f(int r, int c, bool p){
    if (r == 0 && c == 0) return 0;
    if (r == 0) assert(false);
    if (v[r][c][p]) return dp[r][c][p];
    v[r][c][p] = true;

    bool L = r-1 >= c+1;
    bool R = c > 0;

    if (L && R){
        dp[r][c][p] = f(r-1, c+1, false) + f(r-1, c-1, false);
        if (!p) {
            dp[r][c][p] = max(dp[r][c][p], 1 + f(r-1, c+1, true) + f(r-1, c-1, false));
            dp[r][c][p] = max(dp[r][c][p], 1 + f(r-1, c+1, false) + f(r-1, c-1, true));
        }
    } else if (L) {
        dp[r][c][p] = f(r-1, c+1, false);
        if (!p)
            dp[r][c][p] = max(dp[r][c][p], 1 + f(r-1, c+1, true));
    } else {
        dp[r][c][p] = f(r-1, c-1, false);
        if (!p)
            dp[r][c][p] = max(dp[r][c][p], 1 + f(r-1, c-1, true));
    }

    return dp[r][c][p];
}

int main(){
    scanf("%d", &n);
    n *= 2;

    printf("%lld\n", f(n, 0, false));
}
