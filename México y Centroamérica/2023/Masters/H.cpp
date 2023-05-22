#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct squery {
    int i, l, r;
};

constexpr int maxn = 101010;
int N, M, Q;
ll a[maxn], b[maxn], c[maxn], curr[maxn], BIT[maxn];
ll ans[maxn];
vector<squery> queries[maxn];

void update(int i, int x) {
    for (; i < maxn; i += i&-i)
        BIT[i] += x;
}

ll query(int i) {
    ll ret = 0;
    for (; i; i -= i&-i)
        ret += BIT[i];
    return ret;
}

int main() {
    scanf("%d %d %d", &N, &M, &Q);

    for (int i = 1; i <= N; i++)
        scanf("%lld", &c[i]);
    
    for (int i = 1; i <= M; i++) {
        scanf("%lld %lld", &b[i], &a[i]);
    }

    for (int i = 1; i <= Q; i++) {
        int d, l, r;
        scanf("%d %d %d", &d, &l, &r);
        squery q{.i = i, .l = l, .r = r};
        queries[d].push_back(q);
    }

    for (int i = 1; i <= M; i++) {
        auto newVal = min(curr[b[i]] + a[i], c[b[i]]);
        auto delta = newVal - curr[b[i]];
        curr[b[i]] = newVal;
        update(b[i], delta);
        for (const auto q: queries[i]) {
            ans[q.i] = query(q.r) - query(q.l-1);
        }
    }

    for (int i = 1; i <= Q; i++) {
        printf("%lld\n", ans[i]);
    }
}