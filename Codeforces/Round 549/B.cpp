#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 20;//200100;
int n, m, q;
int p[maxn], ip[maxn], a[maxn];
int R[maxn], L[maxn], last[maxn];
int stmin[4*maxn], stmax[4*maxn];

void build(int x, int l, int r){
    if (l == r){
        stmin[x] = stmax[x] = a[l];
        return;
    }

    build (2*x+1, l, (l+r)/2);
    build (2*x+2, (l+r)/2+1, r);
    stmin[x] = min(stmin[2*x+1], stmin[2*x+2]);
    stmax[x] = max(stmax[2*x+1], stmax[2*x+2]);
}

int firstleft(int x, int l, int r, int i, int k){
    if (i <= l){ // contained
        if (l == r) return a[l] <= k ? l : -1;
        if (
    } else if (i <= (l+r)/2) { // split
        int y = firstleft(2*x+1, l, r, i, k);
        if (y != -1) return y;
    }
    return firstleft(2*x+2, (l+r)/2+1, r, i, k); // right
}

bool query(int l, int r){
    return false;
}

int main(){
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i < n; i++){
        scanf("%d", &p[i]);
        ip[p[i]] = i;
    }
    
    for (int i = 0; i < m; i++){
        scanf("%d", &a[i]);
        a[i] = ip[a[i]];
    }

    fill(last, last+n, -1);
    for (int i = 0; i < m; i++){
        if (a[i]){
            if (last[a[i]-1] != -1)
                L[i] = L[last[a[i]-1]];
            else L[i] = -1;
        } else L[i] = i;
        last[a[i]] = i;
    }

    fill(last, last+n, -1);
    for (int i = m-1; i >= 0; i--){
        if (a[i] < n-1){
            if (last[a[i]+1] != -1)
                R[i] = R[last[a[i]+1]];
            else R[i] = m;
        } else R[i] = i;
        last[a[i]] = i;
    }

    build(0, 0, m-1);

    while (q--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%c", query(l, r) ? '1' : '0');
    }

    putchar('\n');
}
