#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

const int maxn = 110;
int n;
int a[maxn], acc[maxn];
ll dp[maxn][maxn];

int main(){
    while (scanf("%d", &n) != EOF){
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        for (int i = 1; i <= n; i++){
            acc[i] = acc[i-1] + a[i];
            dp[i][i] = 0;
        }

        for (int i = n; i >= 1; i--)
            for (int j = i+1; j <= n; j++){
                dp[i][j] = LONG_LONG_MAX;
                for (int l = i; l < j; l++){
                    ll kl = (acc[l] - acc[i-1]) % 100;
                    ll kr = (acc[j] - acc[l]) % 100;
                    dp[i][j] = min(dp[i][j], dp[i][l] + dp[l+1][j] + kl * kr);
                }
            }
        
        printf("%lld\n", dp[1][n]);
    }
}
