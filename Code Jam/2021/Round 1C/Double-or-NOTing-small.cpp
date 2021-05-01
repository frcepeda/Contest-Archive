#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const int maxv = 1<<20;

int f(int x){
    if (x == 0) return 1;
    int y = 1;
    for (; y <= x; y *= 2);
    return (~x) & (y-1);
}

int go(int S, int E){
    int v[maxv] = {0};
    deque<int> p;

    v[S] = 1;
    p.push_back(S);

    while (!p.empty()) {
        int x = p.front(); p.pop_front();

        if (x == E) return v[x] - 1;

        if (2*x < maxv && !v[2*x]) {
            v[2*x] = v[x] + 1;
            p.push_back(2*x);
        }

        int fx = f(x);

        if (fx < maxv && !v[fx]) {
            v[fx] = v[x] + 1;
            p.push_back(fx);
        }
    }

    return -1;
}

int bin(char *c) {
    int ret = 0;
    for (; *c != '\0'; c++) {
        ret = 2*ret + *c - '0';
    }
    return ret;
}

int main(){
    int T, S, E;

    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        printf("Case #%d: ", t);

        char SS[10], EE[10];
        
        scanf("%s %s", SS, EE);

        auto ans = go(bin(SS), bin(EE));

        if (ans < 0) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }
}
