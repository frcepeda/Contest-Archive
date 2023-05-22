#include <cstdio>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    ll N;
    scanf("%lld", &N);

    ll lo = 0, hi = 1000001, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (mid * (mid + 1) >= N)
            hi = mid;
        else
            lo = mid + 1;
    }
    
    ll a = hi-1;

    ll ans;

    if (N - (a*(a+1) + 1) < (a+1)*(a+2) - N) {
        ans = 2*a + 1;
    } else {
        ans = 2*a + 2;
    }

    printf("%lld\n", ans);
}