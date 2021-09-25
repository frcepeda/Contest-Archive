#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1000100;
int T, N;
int p[maxn], dp[maxn];

vector<int> divisors(int x) {
    vector<int> v;
    v.reserve(300);

    for (int i = 2; i <= x/i; i++) {
        if (x % i == 0) {
            v.push_back(i);
            if (i != x/i) v.push_back(x/i);
        }
    }

    sort(v.begin(), v.end());

    return v;
}

int f(int x) {
    if (x <= 2 || dp[x]) return dp[x];

    dp[x] = 1;

    for (auto y: divisors(x-1)) {
        dp[x] = max(dp[x], f((x-1)/y) + 1);
    }

    return dp[x];
}

int main(){
    /*
    p[0] = p[1] = 1;

    for (int i = 2; i < maxn; i++)
        p[i] = i;

    for (int i = 2; i < maxn; i++){
        if (p[i] != i) continue;
        for (int j = 2*i; j < maxn; j += i) {
            p[j] = min(p[j], i);
        }
    }
    */

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);

        int ans = 1;

        for (auto x: divisors(N)) {
            if (x < 3 || N/x < 3) continue;
            ans = max(ans, f(x) + 1);
        }

        printf("Case #%d: %d\n", t, ans);
    }
}
