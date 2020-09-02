#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const int maxw = 22;
const ll mod = 1000000007;
int T, N, K, W;
ll AL, AH, BL, BH, CL, CH, DL, DH;
ll L[maxn], H[maxn];

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d %d %d", &N, &K, &W);

        for (int i = 0; i < K; i++)
            scanf("%lld", &L[i]);
        scanf("%lld %lld %lld %lld", &AL, &BL, &CL, &DL);
        for (int i = K; i < N; i++)
            L[i] = (AL * L[i-2] + BL * L[i-1] + CL) % DL + 1;
        for (int i = 0; i < K; i++)
            scanf("%lld", &H[i]);
        scanf("%lld %lld %lld %lld", &AH, &BH, &CH, &DH);
        for (int i = K; i < N; i++)
            H[i] = (AH * H[i-2] + BH * H[i-1] + CH) % DH + 1;

        ll lastp = (2*W + 2*H[0]) % mod;
        ll ans = lastp;

        for (int j, i = 1; i < N; i++){
            ll tall = 0, deep = W;

            for (j = i-1; j >= 0 && L[i]-L[j] <= W; j--){
                tall = max(tall, H[j]);
                deep = min(deep, L[i] - L[j]);
            }

            lastp = (lastp + 2 * (max(0LL, H[i] - tall) + deep)) % mod;
            //fprintf(stderr, "%d: %lld\n", i, lastp);
            ans = (ans * lastp) % mod;
        }

        printf("Case #%d: %lld\n", t, ans % mod);
    }
}
