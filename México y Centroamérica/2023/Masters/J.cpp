#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

constexpr int maxn = 50, maxf = 21;
int N, K, F;
int popcount[1<<maxf];
std::bitset<maxn> D[maxf], G[1<<maxf];

int main() {
    scanf("%d %d %d", &N, &K, &F);

    for (int i = 0; i < F; i++){
        int fi, x;
        scanf("%d", &fi);
        while (fi--) {
            scanf("%d", &x);
            D[i].set(x-1);
        }
        G[1<<i] = D[i];
    }

    int ans = 0;
    for (long long i = 1; i < (1<<F); i++) {
        popcount[i] = 1 + popcount[i^(i&-i)];
        G[i] = G[i&-i] | G[i^(i&-i)];
        if (N - G[i].count() >= K)
            ans = max(ans, popcount[i]);
    }

    printf("%d\n", ans);
}