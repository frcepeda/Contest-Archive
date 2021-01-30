#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 105;
int T, N;
int dp[maxn][maxn];
char str[maxn][4];
bool adj[maxn][maxn];
bool v[maxn][maxn];

int f(int l, int r) {
    if (r - l + 1 <= 2) return 0;
    if (v[l][r]) return dp[l][r];
    v[l][r] = true;

    dp[l][r] = max(f(l+1,r), f(l,r-1));

    for (int k = l; k < r; k++){
        dp[l][r] = max(dp[l][r], f(l,k) + f(k,r));
    }

    for (int k = l+1; k < r; k++){
        if (adj[l][r]){
            dp[l][r] = max(dp[l][r], f(l,k-1) + f(k+1,r) + 1);
        }
    }

    return dp[l][r];
}

int main () {
    scanf("%d", &T);
    
    while (T--){
        scanf("%d", &N);

        for (int i = 0; i < N; i++){
            scanf("%s", str[i]);
            sort(str[i], str[i]+3);
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                v[i][j] = false;
                if (i == j) continue;
                int sym = 0;
                for (int a = 0; a < 3; a++){
                    for (int b = 0; b < 3; b++){
                        sym += str[i][a] == str[j][b];
                    }
                }
                adj[i][j] = sym >= 2;
            }
        }

        printf("%d\n", f(0, N-1));
    }
}
