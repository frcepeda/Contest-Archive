#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1000100;
int T, N;
ull B[maxn], b = 3, L[maxn], R[maxn];
char str[maxn];

bool works(int k) {
    for (int i = 1; i+k <= N+1; i++) {
        int x = i, y = i+k-1;

        ull HL = L[y] - L[x-1] * B[k];
        ull HR = R[x] - R[y+1] * B[k];

        if (HL == HR) {
            return true;
        }
    }

    return false;
}

int main() {
    B[0] = 1;
    for (int i = 1; i < maxn; i++) {
        B[i] = B[i-1] * b;
    }

    scanf("%d", &T);

    while (T--) {
        scanf("%s", str+1);
        N = strlen(str+1);

        L[0] = L[N+1] = R[0] = R[N+1] = 0;

        for (int i = 1; i <= N; i++) {
            L[i] = b * L[i-1] + (str[i] == '+');
        }

        for (int i = N; i >= 1; i--) {
            R[i] = b * R[i+1] + (str[i] == '+');
        }

        int lo = 0, hi = N/2+1, mid;

        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (!works(mid*2))
                hi = mid;
            else
                lo = mid + 1;
        }

        printf("%d\n", max(0, hi-1) * 2);
    }
}
