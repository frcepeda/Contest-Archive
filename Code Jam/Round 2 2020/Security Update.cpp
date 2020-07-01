#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
    int node, idx;
    edge(int n, int i):node(n),idx(i){}
};

const int maxc = 110;
const int maxd = 1010;
const int INF = 1000000;

int T, C, D, X[maxc];
vector<edge> adj[maxc];
int visit[maxc], latency[maxd];

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d %d", &C, &D);

        for (int i = 1; i <= C; i++){
            adj[i].clear();
            visit[i] = INF;
        }
        visit[1] = 0;

        vector<int> count, fixed;

        for (int i = 2; i <= C; i++){
            scanf("%d", &X[i]);
            if (X[i] < 0)
                count.push_back(i);
            else
                fixed.push_back(i);
        }

        for (int i = 1; i <= D; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }

        sort(count.begin(), count.end(), [=](int a, int b){ return X[a] > X[b]; });
        sort(fixed.begin(), fixed.end(), [=](int a, int b){ return X[a] < X[b]; });

        for (int ci = 0, fi = 0, sofar = 1, latest = 0; ci < count.size() || fi < fixed.size(); ){
            if (ci < count.size() && sofar == -X[count[ci]]){
                int cj = ci;
                int maxLatency = latest;

                for (; cj < count.size() && X[count[ci]] == X[count[cj]]; cj++){
                    for (auto e: adj[count[cj]]){
                        if (visit[e.node] != INF){
                            maxLatency = max(maxLatency, visit[e.node]);
                        }
                    }
                }

                maxLatency++;
                latest = maxLatency;

                for (; ci < cj; ci++){
                    visit[count[ci]] = maxLatency;
                    for (auto e: adj[count[ci]]){
                        if (visit[e.node] != INF){
                            latency[e.idx] = maxLatency - visit[e.node];
                        }
                    }
                    sofar++;
                }
            }

            if (fi < fixed.size() && (ci >= count.size() || sofar != -X[count[ci]])){
                visit[fixed[fi]] = X[fixed[fi]];

                latest = max(latest, X[fixed[fi]]);

                for (auto e: adj[fixed[fi]]){
                    if (visit[e.node] != INF){
                        int prop = visit[fixed[fi]] - visit[e.node];
                        latency[e.idx] = prop <= 0 ? INF : prop;
                    }
                }

                fi++; sofar++;
            }
        }

        printf("Case #%d:", t);
        for (int i = 1; i <= D; i++)
            printf(" %d", latency[i] ? latency[i] : INF);
        printf("\n");
    }
}
