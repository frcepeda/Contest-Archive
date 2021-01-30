#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 105;
int N, R, t[maxn];
vector<int> adj[maxn], deltas;
bool v[maxn];

const int OFF = 100*100;
int dp[maxn][2*OFF+10];
bool vdp[maxn][2*OFF+10];

int dfs(int x, int color) {
    if (v[x]) return 0;
    v[x] = true;

    int ret = color * t[x];

    for (auto y: adj[x]) {
        if (v[y]) continue;
        ret += dfs(y, -color);
    }

    return ret;
}

int f(int x, int d) {
    if (x == deltas.size()) return abs(d);

    auto &ans = dp[x][d+OFF];

    if (vdp[x][d+OFF]) return ans;
    vdp[x][d+OFF] = true;

    ans = min(f(x+1, d + deltas[x]), f(x+1, d - deltas[x]));

    return ans;
}

int main(){
    scanf("%d %d", &N, &R);

    for (int i = 1; i <= N; i++){
        scanf("%d", &t[i]);
    }

    for (int i = 0; i < R; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++){
        if (!v[i]) {
            deltas.push_back(dfs(i, 1));
        }
    }

    printf("%d\n", f(0,0));
}
