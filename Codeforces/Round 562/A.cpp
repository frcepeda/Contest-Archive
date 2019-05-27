#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 300100;
int n, m, a[maxn];

bool works(int x){
    int p = 0;
    for (int i = 0; i < n; i++){
        if (a[i] <= p) {
            if (p - a[i] <= x)
                p = p;
            else
                return false;
        } else {
            if (m + p - a[i] <= x)
                p = p;
            else
                p = a[i];
        }
    }
    return true;
}

int main(){
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int lo = 0, hi = maxn, mid;
    while (lo < hi){
        mid = (lo + hi)/2;
        if (works(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    printf("%d\n", hi);
}
