#include <cstdio>
#include <algorithm>

typedef long long ll;

constexpr ll mod = 1000000007;
ll N, D, K, S;

ll binexp(ll b, ll e) {
    ll r = 1;
    for (; e; e /= 2) {
        if (e % 2)
            r = (r * b) % mod;
        b = (b * b) % mod;
    }
    return r;
}

int main() {
    scanf("%lld %lld %lld %lld", &N, &D, &K, &S);
    if (D == 0) {
        printf("%lld\n", K % mod);
    } else {
        auto A = std::min(2*D+1, N);
        printf("%lld\n", ((binexp(A, K) - 1 + mod) % mod) * binexp(A-1, mod-2) % mod);
    }
}