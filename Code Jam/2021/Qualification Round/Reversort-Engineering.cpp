#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int T, N, C;

int reversort(vector<int> &v) {
    int ans = 0;
    for (int i = 0; i < N-1; i++){
        int x = find(v.begin(), v.end(), i+1) - (v.begin() + i) + 1;
        reverse(v.begin()+i, v.begin()+i+x);
        ans += x;
    }
    return ans;
}

bool go(vector<int> &v, int c) {
    if (c < N-1) return false;
    c -= N-1;

    int L = 0, R = N-1;
    bool rightIsNoop = false;

    for (int i = 1; i <= N; i++) {
        if (R-L <= c) {
            c -= R-L;

            if (rightIsNoop) {
                v[L++] = i;
            } else {
                v[R--] = i;
            }

            rightIsNoop = !rightIsNoop;
        } else {
            if (rightIsNoop) {
                v[R--] = i;
            } else {
                v[L++] = i;
            }
        }
    }

    return c == 0;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        printf("Case #%d:", t);
        
        scanf("%d %d", &N, &C);

        vector<int> v(N);

        if (go(v, C)) {
            for (int i = 0; i < N; i++)
                printf(" %d", v[i]);
            printf("\n");

#if DBG
        assert(reversort(v) == C);
#endif
        } else {
            printf(" IMPOSSIBLE\n");
        }
    }
}
