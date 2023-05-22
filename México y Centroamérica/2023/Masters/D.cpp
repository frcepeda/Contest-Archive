#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int maxn = 100010;
int r, c, k;
int g[maxn];

int main() {
    scanf("%d %d %d", &r, &c, &k);
    k = min(k, r);
    for (int i = 0; i < c; i++) {
        int x;
        scanf("%d", &x);
        g[x-1]++;
    }
    sort(g, g+r);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += g[r-1-i];
    }
    printf("%d\n", ans);
}