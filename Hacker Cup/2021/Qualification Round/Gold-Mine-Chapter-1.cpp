#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 55;
int T, N, C[maxn];
vector<int> adj[maxn];

int dfs(int x, int p){
    int ans = 0;

    for (auto y: adj[x]){
        if (y == p) continue;
        ans = max(ans, dfs(y, x));
    }

    return C[x] + ans;
}

int go() {
    int one = 0, two = 0;
    for (auto x: adj[1]) {
        auto d = dfs(x, 1);
        if (d > one) {
            two = one;
            one = d;
        } else if (d > two) {
            two = d;
        }
    }
    return C[1] + one + two;
}

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d", &N);

        for (int i = 1; i <= N; i++){
            adj[i].clear();
            scanf("%d", &C[i]);
        }

        for (int i = 1; i < N; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        printf("Case #%d: %d\n", t, go());
    }
}
