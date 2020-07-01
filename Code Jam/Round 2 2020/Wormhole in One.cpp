#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

struct PT { 
  ll x, y; 
  PT() {}
  PT(ll x, ll y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (ll c)     const { return PT(x*c,   y*c  ); }
  PT operator / (ll c)     const { return PT(x/c,   y/c  ); }
};

bool operator < (const PT &a, const PT &b) { return make_pair(a.x, a.y) < make_pair(b.x, b.y); }
ll dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
ll dist2(PT p, PT q)   { return dot(p-q,p-q); }
ll cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

const int maxn = 10;
int T, N;
PT P[maxn];
int link[maxn];
int v[maxn], vv[maxn];

int count(int x, PT dir){
    if (x == 0 || vv[x])
        return 0;

    int ret = !v[x];
    v[x] = vv[x] = 1;

    if (!link[x]) return ret;

    x = link[x];

    if (!v[x]){
        ret++;
        v[x] = 1;
    }

    int nn = 0;
    ll dd = 0;
    for (int i = 1; i <= N; i++){
        if (i == x) continue;
        if (cross(P[i] - P[x], dir)) continue;
        auto d = dot(P[i] - P[x], dir);
        if (d < 0) continue;
        if (nn == 0 || d < dd){
            dd = d;
            nn = i;
        }
    }

    return ret + count(nn, dir);
}

int best(){
    int b = 1;

    for (int i = 1; i <= N; i++){
        for (int j = i+1; j <= N; j++){
            for (int k = 1; k <= N; k++){
                for (int q = 1; q <= N; q++) v[q] = vv[q] = 0;
                b = max(b, count(k, P[j] - P[i]));
            }
        }
    }

    return b;
}

int go(int x){
    if (x > N)
        return best();
    int b = go(x+1);

    for (int i = x+1; i <= N; i++){
        if (link[x] || link[i]) continue;
        link[x] = i;
        link[i] = x;
        b = max(b, go(x+1));
        link[x] = link[i] = 0;
    }

    return b;
}

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d", &N);

        for (int i = 1; i <= N; i++)
            scanf("%lld %lld", &P[i].x, &P[i].y);

        printf("Case #%d: %d\n", t, go(1));
    }
}
