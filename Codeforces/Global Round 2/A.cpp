#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 300300;
int n, c[maxn];

int main(){
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    int l;
    for (int i = n-2; i >= 0; i--)
        if (c[i] != c[i+1]){
            l = i;
            break;
        }

    int ans = 0;

    for (int i = 0; i < n-1; i++){
        if (c[i] != c[n-1])
            ans = max(ans, n-1-i);
        if (c[i] == c[n-1] && l > i)
            ans = max(ans, l-i);
    }

    printf("%d\n", ans);
}
