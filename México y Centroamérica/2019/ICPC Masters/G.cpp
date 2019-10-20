#include <cstdio>
#include <algorithm>

using namespace std;

typedef __int128 ll;

const int maxn = 20100;
const ll mod = 3038000027;

int T, N, M, K, C, G;
ll fact[maxn];
int A[maxn], B[maxn];
int p[maxn];

ll modexp(__int128 x, __int128 e){
    __int128 ret = 1;

    for (; e; e /= 2){
        if (e % 2)
            ret = (ret * x) % mod;
        x = (x * x) % mod;
    }

    return ret;
}

ll inv(ll x){
    return modexp(x, mod-2);
}

int main(){
    scanf("%d", &T);

    fact[0] = 1;
    for (int i = 1; i < maxn; i++)
        fact[i] = (fact[i-1] * i) % mod;

    p[0] = p[1] = 1;
    for (int i = 2; i < maxn; i++){
        if (p[i]) continue;
        for (int j = i*i; j < maxn; j += i)
            if (!p[j])
                p[j] = i;
        p[i] = i;
    }

    while (T--){
        scanf("%d %d %d %d", &N, &K, &C, &G);
        M = N - G;

        if (C == 1){
            if (G == N) printf("1 0\n");
            else printf("0 0\n");
            continue;
        }

        if (M > K){
            printf("0 0\n");
            continue;
        }

        fill(A, A + maxn, 0);
        fill(B, B + maxn, 0);

        // ll up = (fact[K] * modexp(C-1, M)) % mod;
        // K!
        for (int i = 2; i <= K; i++)
            for (int x = i; x != 1; x /= p[x])
                A[p[x]]++;
        // (C-1)^M
        for (int x = C-1; x != 1; x /= p[x])
            A[p[x]] += M;

        // ll down = (((fact[M] * fact[K-M]) % mod) * modexp(C, K)) % mod;
        // M!
        for (int i = 2; i <= M; i++)
            for (int x = i; x != 1; x /= p[x])
                B[p[x]]++;
        // (K-M)!
        for (int i = 2; i <= K-M; i++)
            for (int x = i; x != 1; x /= p[x])
                B[p[x]]++;
        // C^K
        for (int x = C; x != 1; x /= p[x])
            B[p[x]] += K;
        
        ll up = 1;
        for (int i = 2; i < maxn; i++)
            up = (up * modexp(i, A[i] - min(A[i], B[i]))) % mod;

        ll down = 1;
        for (int i = 2; i < maxn; i++)
            down = (down * modexp(i, B[i] - min(A[i], B[i]))) % mod;

        printf("%lld %lld\n", (long long) up, (long long) down);
    }
}
