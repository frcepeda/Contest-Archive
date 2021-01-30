#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int maxn = 33, maxb = 17;
int T, N, M;
vector<int> adj[maxn], wins[maxn];
ll ways[maxn][maxn];
bool v[maxn];

void dfs(int x, vector<int> &comp) {
    if (v[x]) return;
    v[x] = true;
    comp.push_back(x);

    for (auto y: adj[x]){
        dfs(y, comp);
    }
}

ll dp[1<<maxb];

pair<ll,int> go(int x) {
    vector<int> comp;
    int uncomp[maxn];

    dfs(x, comp);

    for (int i = 0; i < comp.size(); i++){
        uncomp[comp[i]] = i;
    }

    dp[0] = 1;

    for (int i = 1; i < (1<<comp.size()); i++) {
        dp[i] = 0;
        for (int j = 0; j < comp.size(); j++){
            if ((i & (1<<j)) == 0) continue;

            bool dead = false;

            for (auto k: wins[comp[j]]) {
                if (i & (1<<uncomp[k])) {
                    dead = true;
                    break;
                }
            }

            if (!dead) {
                dp[i] = (dp[i] + dp[i^(1<<j)]) % mod;
            }
        }
    }

    return make_pair(dp[(1<<comp.size())-1], (int)comp.size());
}

int main() {
    for (int i = 0; i < maxn; i++){
        for (int j = 0; j < maxn; j++){
            if (i == 0 || j == 0){
                ways[i][j] = 1;
                continue;
            }
            ways[i][j] = (ways[i-1][j] + ways[i][j-1]) % mod;
        }
    }

    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++){
            adj[i].clear();
            wins[i].clear();
            v[i] = false;
        }

        for (int i = 0; i < M; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            wins[v].push_back(u);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ll ans = 1, len = 0;

        for (int i = 1; i <= N; i++){
            if (!v[i]) {
                pair<ll,int> comp = go(i);
                ans = ans * comp.first % mod * ways[len][comp.second] % mod;
                len += comp.second;
            }
        }

        printf("%lld\n", ans);
    }
}
