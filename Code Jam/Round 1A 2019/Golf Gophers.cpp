#include <cstdio>
#include <algorithm>
#include <tuple>

using namespace std;

typedef long long ll;

int T, N, M;

ll a[8], m[8];
int mods[] = {3, 5, 7, 11, 13, 16, 17};

int rem(int k){
    for (int i = 0; i < 18; i++)
        printf("%d%c", k, i+1 < 18 ? ' ' : '\n');
    fflush(stdout);
    
    int sum = 0, x;
    for (int i = 0; i < 18; i++){
        scanf("%d", &x);
        sum += x;
    }
    
    return sum % k;
}

int main(){
    scanf("%d %d %d", &T, &N, &M);

    for (int t = 1; t <= T; t++){
        for (int i = 0; i < 7; i++){
            a[i] = rem(mods[i]);
            m[i] = mods[i];
        }
        
        for (int i = 1; i < 7; i++){
            ll s = 0, t = 1, r = m[i];
            ll o_s = 1, o_t = 0, o_r = m[i-1];

            while (r != 0){
                ll q = o_r / r;
                tie(o_r, r) = make_pair(r, o_r - q * r);
                tie(o_s, s) = make_pair(s, o_s - q * s);
                tie(o_t, t) = make_pair(t, o_t - q * t);
            }

            a[i] = a[i-1] * o_t * m[i] + a[i] * o_s * m[i-1];
            m[i] = m[i] * m[i-1];
            a[i] = ((a[i] % m[i]) + m[i]) % m[i];
        }
        
        printf("%lld\n", a[6]);
        fflush(stdout);

        scanf("%*d");
    }
}
