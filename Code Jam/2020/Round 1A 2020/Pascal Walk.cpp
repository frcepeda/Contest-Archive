#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>

#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int T;
ll N;

const int maxs = 65;
ll pascal[maxs][maxs];

vector<pii> moves;
set<pii> visited;

int dr[6] = {-1, -1, 0, 0, 1, 1};
int dc[6] = {-1, 0, -1, 1, 0, 1};

bool go(int r, int c, ll rem){
    if (rem < pascal[r][c])
        return false;
    
    rem -= pascal[r][c];

    moves.emplace_back(r, c);
    visited.emplace(r, c);

    if (rem == 0) return true;

    vector<pair<ll, pii>> valid;

    for (int k = 0; k < 6; k++){
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr < 0 || nr >= maxs) continue;
        if (nc < 0 || nc > nr) continue;
        if (visited.find(pii(nr, nc)) != visited.end()) continue;
        if (pascal[nr][nc] > rem) continue;

        valid.emplace_back(pascal[nr][nc], pii(nr, nc));
    }

    sort(valid.begin(), valid.end(), greater<pair<ll,pii>>());

    for (auto m: valid)
        if (go(m.snd.fst, m.snd.snd, rem))
            return true;

    moves.pop_back();
    visited.erase(pii(r, c));
    return false;
}

int main(){
    for (int i = 0; i < maxs; i++){
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
    }

#ifndef DBG
    scanf("%d", &T);
#endif

#ifndef DBG
    for (int t = 1; t <= T; t++){
        scanf("%lld", &N);
#else
    int t = 0;
    while (true){
        t++;
        N = rand() % 1000000000 + 1;
#endif

        moves.clear();
        visited.clear();

        assert(go(0, 0, N));
        assert(moves.size() <= 500);

        ll acc = 0;
#ifndef DBG
        printf("Case #%d:\n", t);
#endif
        for (auto m: moves){
            acc += pascal[m.fst][m.snd];

#ifndef DBG
            printf("%d %d\n", m.fst+1, m.snd+1);
            fprintf(stderr, "acc: %lld (+%lld)\n", acc, pascal[m.fst][m.snd]);
#endif
        }
#ifdef DBG
        fprintf(stderr, "OK: %lld\n", N);
#endif

        assert(acc == N);
    }
}