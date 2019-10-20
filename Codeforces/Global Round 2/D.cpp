#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 100100;
int n, q;
ll s[maxn], d[maxn], acc[maxn];

ll query(ull c){
    ull ans = n * c;

    int x = upper_bound(d, d + n-1, c) - d;
    x--;

    if (x < 0) return ans;

    return ans - ((x+1)*c - acc[x]);
}

int main(){
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%lld", &s[i]);
    
    sort(s, s + n);

    for (int i = 0; i < n-1; i++)
        d[i] = s[i+1] - s[i];

    sort(d, d + n-1);
    
    acc[0] = d[0];
    for (int i = 1; i < n-1; i++)
        acc[i] = acc[i-1] + d[i];

    scanf("%d", &q);

    while (q--){
        ll l, r;
        scanf("%lld %lld", &l, &r);
        printf("%lld%c", query(r - l + 1), q ? ' ' : '\n');
    }
}
