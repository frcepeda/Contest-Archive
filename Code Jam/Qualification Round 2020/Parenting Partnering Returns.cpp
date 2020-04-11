#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int T, N, S[maxn], E[maxn];
bool adj[maxn][maxn], color[maxn], visited[maxn];

bool dfs(int x, int c){
    if (visited[x])
        return color[x] == c;
    
    visited[x] = true;
    color[x] = c;

    for (int i = 0; i < N; i++){
        if (!adj[x][i]) continue;
        if (!dfs(i, !c)) return false;
    }

    return true;
}

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        printf("Case #%d: ", t);

        scanf("%d", &N);

        fill(color, color+N, false);
        fill(visited, visited+N, false);

        for (int i = 0; i < N; i++){
            scanf("%d %d", &S[i], &E[i]);
            fill(adj[i], adj[i]+N, false);
        }

        for (int i = 0; i < N; i++)
            for (int j = i+1; j < N; j++)
                if (max(S[i], S[j]) < min(E[i], E[j]))
                    adj[i][j] = adj[j][i] = true;
        
        bool works = true;

        for (int i = 0; i < N && works; i++)
            if (!visited[i])
                works &= dfs(i, false);
        
        if (works)
            for (int i = 0; i < N; i++)
                putchar(color[i] ? 'C' : 'J');
        else
            printf("IMPOSSIBLE");

        putchar('\n');
    }
}