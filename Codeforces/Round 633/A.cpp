#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int t, n;
int a[maxn];

int main(){
    scanf("%d", &t);

    while (t--){
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        long long hi = a[0], ans = 0;

        for (int i = 0; i < n; i++){
            if (a[i] <= hi){
                ans = max(ans, hi - a[i]);
            } else hi = a[i];
        }

        int out = 0;
        for (; ans; ans /= 2) out++;
        
        printf("%d\n", out);
    }
}