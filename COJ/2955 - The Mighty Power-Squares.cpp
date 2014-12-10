#include <cstdio>
#include <algorithm>

using namespace std;

int t, a, b;

int main(){
    scanf("%d", &t);

    while (t--){
        scanf("%d %d", &a, &b);

        long long ans = 0;
        int l = a;

        for (int i = 0; i <= 16; i++){
            long long int hi = min((long long)b+1, 1LL<<(2*(i+1)));

            if (hi - l > 0)
                ans += ((long long)(hi - l)) * (1LL<<i);

            l = max(hi, (long long)a);
        }

        printf("%lld\n", ans);
    }
}
