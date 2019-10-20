#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef __int128 ll;

const int maxn = 100100;
const ll mod = 4300000013LL;

int N, M;
ll bit[maxn], fact[maxn], usage[maxn];
map<ll, int> freq;
ll acc, cnt;

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

void upd(int i, int x){
    for (; i < maxn; i += i&-i)
        bit[i] += x;
}

ll query(int i){
    ll x = 0;
    for (; i; i -= i&-i)
        x += bit[i];
    return x;
}

int main(){
    int tests;

    fact[0] = 1;
    for (int i = 1; i < maxn; i++)
        fact[i] = (fact[i-1] * i) % mod;

    scanf("%d", &tests);

    while (tests--){
        scanf("%d %d", &N, &M);

        freq.clear();
        fill(bit, bit+1+N, 0);
        fill(usage, usage+1+N, 0);
        acc = 1;
        cnt = 0;

        while (M--){
            char q; int a, b;
            scanf(" %c", &q);

            if (q == 'Q'){
                scanf("%d %d", &a, &b);
                printf("%lld\n", (long long)(query(b) - query(a-1)));
            } else if (q == 'W'){
                printf("%lld\n", (long long) acc);
            } else {
                scanf("%d %d", &a, &b);

                acc = (acc * inv(fact[cnt])) % mod;
                acc = (acc * fact[freq[usage[a]]]) % mod;
                acc = (acc * fact[freq[usage[a] + b]]) % mod;

                if (usage[a]) freq[usage[a]]--;
                else cnt++;
                freq[usage[a] + b]++;

                acc = (acc * inv(fact[freq[usage[a] + b]])) % mod;
                acc = (acc * inv(fact[freq[usage[a]]])) % mod;
                acc = (acc * fact[cnt]) % mod;

                usage[a] += b;
                upd(a, b);
            }
        }
    }
}
