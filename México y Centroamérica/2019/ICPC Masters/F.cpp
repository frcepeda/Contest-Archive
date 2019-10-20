#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;

int main(){
    scanf("%d", &N);

    while (N--){
        char s[100];

        scanf("%s", s);
        ll pquot, prem = 1;

        int x;
        for (x = strlen(s)-1; x >= 0 && s[x] != '.'; x--)
            prem *= 10;
        if (x < 0) prem = 1;

        auto loc = remove_if(s, s + strlen(s), [](char c){ return !isdigit(c); });
        *loc = '\0';

        sscanf(s, "%lld", &pquot);
        
        ll coeff[8] = {0};

        for (int i = 0; i < 8; i++){
            if (prem == 0) continue;

            coeff[i] = pquot / prem;
            ll rem = pquot % prem;
            pquot = prem;
            prem = rem;
        }

        for (int i = 0; i < 8; i++)
            printf("%lld%c", coeff[i], i < 7 ? ' ' : '\n');
        
        pair<ll,ll> p = make_pair(coeff[7], 1);
        for (int i = 6; i >= 0; i--){
            swap(p.first, p.second);

            if (p.second){
                p.first += coeff[i] * p.second;

                ll q = __gcd(p.first, p.second);
                p.first /= q;
                p.second /= q;
            } else {
                p.first = coeff[i];
                p.second = 1;
            }
        }

        printf("%lld/%lld\n", p.first, p.second);
    }
}
