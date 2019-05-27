#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 310;
int T, N;
ll C[maxn], J[maxn];

int sgn(ll x) { return x == 0 ? 0 : x < 0 ? -1 : 1; }

int main(){
    scanf("%d", &T);

    vector<pair<ll,ll>> lines;

    for (int t = 1; t <= T; t++){
        lines.clear();

        scanf("%d", &N);

        for (int i = 0; i < N; i++)
            scanf("%lld %lld", &C[i], &J[i]);

        for (int i = 0; i < N; i++)
            for (int j = i+1; j < N; j++){
                ll x = C[i] - C[j];
                ll y = J[i] - J[j];

                if (sgn(x) * sgn(y) >= 0) continue;

                ll d = __gcd(x, y);

                x /= d;
                y /= d;

                if (x < 0) {
                    x = -x;
                    y = -y;
                }

                lines.emplace_back(x, y);
            }
        
        sort(lines.begin(), lines.end());
        ll steps = unique(lines.begin(), lines.end()) - lines.begin();

        printf("Case #%d: %lld\n", t, 1 + steps);
    }
}
