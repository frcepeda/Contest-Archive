#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 100010;
int n, root;
vector<int> adj[maxn];

bool foundType[2];
int maxans;

bool dfs(int x, int p, bool b){
    bool isLeaf = true;
    bool foundLeaf = false;

    for (auto y: adj[x]){
        if (y == p) continue;
        isLeaf = false;

        bool ret = dfs(y, x, !b);

        if (!ret) maxans++;
        else if (!foundLeaf){
            maxans++;
            foundLeaf = true;
        }
    }

    if (isLeaf)
        foundType[b] = true;

    return isLeaf;
}

int main(){
    scanf("%d", &n);

    for (int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (root = 1; adj[root].size() <= 1; root++);

    fprintf(stderr, "root: %d\n", root);

    dfs(root, 0, 0);

    printf("%d %d\n", foundType[0] && foundType[1] ? 3 : 1, maxans);
}