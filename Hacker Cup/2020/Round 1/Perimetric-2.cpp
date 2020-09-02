#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define fst first
#define snd second

const int maxn = 1000010;
const int maxw = 22;
const ll mod = 1000000007;
int T, N, K;
ll AL, AW, AH, BL, BW, BH, CL, CW, CH, DL, DW, DH;
ll L[maxn], W[maxn], H[maxn];

int main(){
    scanf("%d", &T);

    map<ll, ll> s;

    for (int t = 1; t <= T; t++){
        s.clear();

        scanf("%d %d", &N, &K);

        for (int i = 0; i < K; i++)
            scanf("%lld", &L[i]);
        scanf("%lld %lld %lld %lld", &AL, &BL, &CL, &DL);
        for (int i = K; i < N; i++)
            L[i] = (AL * L[i-2] + BL * L[i-1] + CL) % DL + 1;

        for (int i = 0; i < K; i++)
            scanf("%lld", &W[i]);
        scanf("%lld %lld %lld %lld", &AW, &BW, &CW, &DW);
        for (int i = K; i < N; i++)
            W[i] = (AW * W[i-2] + BW * W[i-1] + CW) % DW + 1;

        for (int i = 0; i < K; i++)
            scanf("%lld", &H[i]);
        scanf("%lld %lld %lld %lld", &AH, &BH, &CH, &DH);
        for (int i = K; i < N; i++)
            H[i] = (AH * H[i-2] + BH * H[i-1] + CH) % DH + 1;

        ll lastp = 0, ans = 1;

        for (int i = 0; i < N; i++){
            ll empty = W[i];
            bool freeLeft = true, freeRight = true;

            auto r = L[i] + W[i];
            auto it = s.lower_bound(r);

            int oldCount = s.size();

            if (it != s.end() && r == it->fst)
                freeRight = false;
            
            while (it != s.begin()){
                --it;

                auto R = it->fst + it->snd;

                if (R <= L[i]){
                    freeLeft &= R < L[i];
                    break;
                }

                empty -= min(r, R) - max(L[i], it->fst);
                freeRight = false;

                if (L[i] < it->fst){
                    if (r < R) {
                        s[r] = max(s[r], R - r);
                    }
                    it = s.erase(it);
                } else {
                    freeLeft = false;
                    break;
                }
            }

            if (!freeLeft){
                it->snd = max(it->snd, r - it->fst);
            } else {
                s[L[i]] = W[i];
                it = s.find(L[i]);
            }

            auto nn = s.find(r);
            if (nn != s.end()){
                it->snd += nn->second;
                s.erase(nn);
            }

            int newCount = s.size();

            lastp = (lastp + 2 * H[i] * (newCount - oldCount)) % mod + mod;
            lastp = (lastp + 2 * empty) % mod;
            //fprintf(stderr, "%d: %lld\n", i, lastp);
            ans = (ans * lastp) % mod;
        }

        printf("Case #%d: %lld\n", t, ans % mod);
    }
}
