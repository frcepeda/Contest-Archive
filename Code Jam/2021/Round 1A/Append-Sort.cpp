#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

int T, N;

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        int ans = 0;

        scanf("%d", &N);

        long long last;

        scanf("%lld", &last);

        for (N--; N; N--) {
            long long curr, fact = 1;

            scanf("%lld", &curr);

            if (last < curr) {
                last = curr;
                continue;
            }

            while (last >= curr * fact) {
                ans++;
                fact *= 10;
            }

            long long delta = last - curr * fact / 10;

            if (delta+1 < fact / 10) {
                ans--;
                last = last + 1;
            } else {
                last = curr * fact;
            }
        }

        printf("Case #%d: %d\n", t, ans);
    }
}
