#include <cstdio>

using namespace std;

const int maxn = 11;

int T;
long long dp[maxn][maxn][maxn][maxn][4];

int main() {
    scanf("%d", &T);

    int t[4];
    for (t[0] = 0; t[0] < maxn; t[0]++){
        for (t[1] = 0; t[1] < maxn; t[1]++){
            for (t[2] = 0; t[2] < maxn; t[2]++){
                for (t[3] = 0; t[3] < maxn; t[3]++){
                    for (int k = 0; k < 4; k++){
                        if (t[0] + t[1] + t[2] + t[3] == 0) {
                            dp[t[0]][t[1]][t[2]][t[3]][k] = 1;
                            continue;
                        }

                        long long tmp = 0;

                        for (int x = 0; x < 4; x++){
                            if (x == k) continue;
                            if (t[x] == 0) continue;
                            t[x]--;
                            tmp += dp[t[0]][t[1]][t[2]][t[3]][x];
                            t[x]++;
                        }

                        dp[t[0]][t[1]][t[2]][t[3]][k] = tmp;
                    }
                }
            }
        }
    }

    while (T--){
        int x[4];
        for (int i = 0; i < 4; i++)
            scanf("%d", &x[i]);

        long long ans = 0;

        for (int i = 0; i < 4; i++){
            if (x[i] == 0) continue;
            x[i]--;
            ans += dp[x[0]][x[1]][x[2]][x[3]][i];
            x[i]++;
        }

        if (x[0] + x[1] + x[2] + x[3] == 0) {
            ans = 1;
        }

        printf("%lld\n", ans);
    }
}
