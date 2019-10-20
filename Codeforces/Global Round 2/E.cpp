#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

int main(){
    ll ans = 0, rem = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        ll curr;
        scanf("%lld", &curr);

        ll can2 = min(curr/2, rem);
        ans += can2;
        curr -= can2 * 2;
        rem -= can2;

        ans += curr / 3;
        curr %= 3;

        rem += curr;
    }

    printf("%lld\n", ans);
}
