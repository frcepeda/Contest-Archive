#include <cstdio>

using namespace std;

#define MOD 1000000007
#define MAXN 3010

int choose[MAXN][MAXN];
int T, N;

int main(){
    scanf("%d", &T);

    for (int i = 0; i < MAXN; i++){
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++)
            choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % MOD;
    }

    while (T--){
        scanf("%d", &N);
        int k;
        for (k = 0; (1<<k) <= N; k++);
        k--;
        printf("%lld\n", (choose[1<<k][1 + N - (1<<k)] - 1 + MOD) % MOD);
    }
}
