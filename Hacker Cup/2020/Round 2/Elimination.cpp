#include <cstdio>
#include <algorithm>

using namespace std;

typedef long double ld;

const int maxn = 8010;
int T, N;
ld P, dp[maxn][maxn];

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d %Lf", &N, &P);

        printf("Case #%d:\n", t);

        for (int i = 2; i <= N; i++){
            for (int j = 1; j <= i; j++){
                int more = i-j;
                int less = j-1;

                ld bothHigher = dp[i-1][j] * more * (more-1) / i / (i-1);
                ld bothLower = dp[i-1][j-1] * less * (less-1) / i / (i-1);
                ld lowerHigher = (P * dp[i-1][j-1] + (1-P) * dp[i-1][j]) * 2 * more * less / i / (i-1);

                ld meLower = P * dp[i-1][j-1] * 2 * less / i / (i-1);
                ld meHigher = (1-P) * dp[i-1][j] * 2 * more / i / (i-1);

                dp[i][j] = 1 + bothHigher + bothLower + lowerHigher + meLower + meHigher;
            }
        }

        for (int i = 1; i <= N; i++)
            printf("%.9Lf\n", dp[N][i]);
    }
}
