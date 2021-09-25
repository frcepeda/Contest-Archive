#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200100;

int t, n, p, k, x, y;
char s[maxn];
int dp[maxn];

int main(){
    scanf("%d", &t);

    while (t--){
        scanf("%d %d %d", &n, &p, &k);
        scanf("%s", s);
        scanf("%d %d", &x, &y);

        for (int i = n-1; i >= 0; i--){
            dp[i] = (s[i] == '0') + dp[i+k];
        }

        long long ans = 1LL<<62;

        for (long long d = 0; n-d >= p; d++){
            ans = min(ans, d*y + x*dp[d+p-1]);
        }

        printf("%lld\n", ans);
    }
}
