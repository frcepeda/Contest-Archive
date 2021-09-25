#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

ll modexp(ll x, ll e) {
    ll r = 1;

    for (; e; e /= 2) {
        if (e % 2) r = (r * x) % mod;
        x = (x * x) % mod;
    }

    return r;
}

ll inv(ll x) {
    return modexp(x, mod-2);
}

const int maxn = 100007;
ll fact[maxn], invfact[maxn];

ll choose(int n, int k) {
    return fact[n] * invfact[k] % mod * invfact[n-k] % mod;
}

int T, N;
int v[maxn];

ll go(int s, int e) {
    if (s >= e) return 1;

    ll ret = 1;

    int i = e, last = e;

    while (s < i) {
        int delta = v[i] - v[i-1];

        if (delta == 1) {
            i++;
            continue;
        }

        int sz = 0;

        for (; i - sz >= s; sz++)
            if (v[i-sz] == v[i]-1)
                break;
        sz--;

        int av = last - i + sz;

        ret = (ret * choose(av, sz)) % mod;
        ret = (ret * go(i-sz, i-1)) % mod;

        i -= sz + 1;
        last = i;
    }

    return ret;
}

int main(){
    fact[0] = invfact[0] = fact[1] = invfact[1] = 1;

    for (int i = 2; i < maxn; i++){
        fact[i] = fact[i-1] * i;
        invfact[i] = inv(fact[i]);
    }

    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        ll ans = 0;

        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &v[i]);
        }

        printf("Case #%d: %lld\n", t, go(0, N-1));
    }
}
