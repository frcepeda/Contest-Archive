// 1/11 points
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define UPLOAD 1

#if UPLOAD
    #define openFiles() freopen("lazy.in", "r", stdin); freopen("lazy.out", "w", stdout)
#else
    #define openFiles()
#endif

// USACO upload macros

#define MAXN 100100

#define fst first
#define snd second
#define mp make_pair

typedef pair<int,int> pii;

int N, K, ans;
pair<pii, int> grass[MAXN];
multiset<pii> curr;

int main(){
    int i, j;

    openFiles();

    scanf("%d %d", &N, &K);
    K *= 2;

    for (i = 0; i < N; i++){
        int a, b;
        scanf("%d %d %d", &grass[i].snd, &a, &b);
        grass[i].fst.fst = a+b;
        grass[i].fst.snd = a-b;
    }

    sort(grass, grass + N);

    for (i = j = 0; j < N; j++){
        for (; grass[j].fst.fst - grass[i].fst.fst > K; i++)
            curr.erase(curr.find(mp(grass[i].fst.snd, grass[i].snd)));
        curr.insert(mp(grass[j].fst.snd, grass[j].snd));

        int acc = 0;
        for (multiset<pii>::iterator a = curr.begin(), b = curr.begin(); b != curr.end(); b++){
            for (; b->fst - a->fst > K; a++)
                acc -= a->snd;
            acc += b->snd;
            ans = max(ans, acc);
        }
    }

    printf("%d\n", ans);
}
