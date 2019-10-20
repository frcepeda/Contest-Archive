#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1010;
int n, h, a[maxn];

bool fits(int k){
    vector<int> v(a, a+k);
    sort(v.begin(), v.end());

    int rem = h;
    for (int i = k-1; i >= 0 && rem >= 0; i -= 2)
        rem -= v[i];
    
    return rem >= 0;
}

int main(){
    scanf("%d %d", &n, &h);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int lo = 0, hi = n+1, mid;
    while (lo < hi){
        mid = (lo + hi) / 2;
        if (!fits(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    printf("%d\n", hi-1);
}
