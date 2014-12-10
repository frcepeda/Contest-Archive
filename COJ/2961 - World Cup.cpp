#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 22

typedef long long ll;

ll fact[MAXN] = {1};
ll choose[MAXN][MAXN];
int N, P, K, q;

int main(){
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i;
    for (int i = 0; i < MAXN; i++){
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++)
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
    }

    while (scanf("%d", &N), N){
        long long up = 0, bot = 0;

        scanf("%d %d %d", &P, &K, &q);

        for (int i = K+1; i <= N-q; i++){
            long long e = choose[i-1][K] * choose[N-1-K-q][i-1-K] * fact[i-1-K] * choose[N-i][q] * fact[N-i-q];

            bot += e;
            if (i <= P) up += e;
        }

ll g = __gcd(bot, up);
            bot /= g;
            up /= g;

        printf("%lld/%lld\n", up, bot);
    }
}
