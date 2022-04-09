#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

constexpr int maxn = 1000100;
int T, N, F[maxn], P[maxn];
vector<int> adj[maxn];

pll dfs(int x) {
    if (adj[x].empty()) {
        return {F[x], 0};
    }

    vector<pll> all;

    for (auto ch: adj[x]){
        all.push_back(dfs(ch));
    }

    partial_sort(all.begin(), all.begin() + 1, all.end());

    pll ret = all[0];
    ret.first = max(ret.first, (long long)F[x]);

    for (int i = 1; i < all.size(); i++){
        ret.second += all[i].first + all[i].second;
    }

    return ret;
}

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d", &N);

        adj[0].clear();
        for (int i = 1; i <= N; i++){
            scanf("%d", &F[i]);
            adj[i].clear();
        }

        for (int i = 1; i <= N; i++){
            scanf("%d", &P[i]);
            adj[P[i]].push_back(i);
        }

        auto ret = dfs(0);

        printf("Case #%d: %lld\n", t, ret.first + ret.second);
    }
}
