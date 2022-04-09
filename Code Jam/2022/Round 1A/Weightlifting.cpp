#include <cstdio>
#include <algorithm>
#include <vector>
#include <array>
#include <map>

using namespace std;

int T, E, W;
vector<vector<int>> X;
map<pair<int,vector<int>>,int> mem;

int dfs(int ex, const vector<int> &prev) {
    if (ex >= E) return prev.size();

    if (auto it = mem.find({ex, prev}); it != mem.end()) {
        return it->second;
    }

    int best = 1<<29;

    do {
        auto mm = mismatch(prev.begin(), prev.end(), X[ex].begin(), X[ex].end());

        int rem = prev.end() - mm.first;
        int add = X[ex].end() - mm.second;

        int me = rem + add;

        if (me < best) {
            best = min(best, me + dfs(ex+1, X[ex]));
        } else {
            sort(mm.second, X[ex].end(), greater<int>());
        }
    } while (next_permutation(X[ex].begin(), X[ex].end()));

    return mem[{ex,prev}] = best;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &E, &W);
        X.clear();

        for (int i = 0; i < E; i++){
            vector<int> v;
            for (int j = 1; j <= W; j++){
                int c;
                scanf("%d", &c);
                for (int k = 0; k < c; k++) {
                    v.push_back(j);
                }
            }
            X.push_back(std::move(v));
        }

        mem.clear();
        printf("Case #%d: %d\n", t, dfs(0, {}));
    }
}
