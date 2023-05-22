#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

constexpr int maxn = 1000100, maxk = 1010;
int v[maxn], m[maxk];

int F(int x) {
    int f = 0;
    //fprintf(stderr, "F(%d) = ", x);
    for (; x; x /= 10)
        f += (x % 10)*(x % 10);
    //fprintf(stderr, "%d\n", f);
    return f;
}

int k;
int dfs(int x, int best) {
    if (v[x] == k) return best;
    v[x] = k;
    const auto fx = F(x);
    return dfs(fx, min(best, fx));
};

int main() {
    long long ans = 0;

    for (k = 1; k < maxk; k++) {
        m[k] = dfs(k, k);
    }

    int A, B;
    scanf("%d %d", &A, &B);
    for (int i = A; i <= B; i++) {
        const auto fi = F(i);
        assert(fi < maxk);
        ans += min(m[fi], i);
    }
    printf("%lld\n", ans);
}