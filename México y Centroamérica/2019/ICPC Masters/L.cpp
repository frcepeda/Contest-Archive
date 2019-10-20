#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, T, L;
char s[100010];
vector<bool> used;

bool enumerate(int acc, int p){
    if (p == 0){
        if (used[acc]) return false;
        printf("%d %0*d\n", L, L, acc);
        return true;
    }

    for (int i = 0; i < 10; i++)
        if (enumerate(acc + p*i, p/10))
            return true;
    
    return false;
}

void solve(){
    int tot = 1;

    for (L = 1;; L++){
        tot *= 10;
        fill(used.begin(), used.begin() + tot, false);

        int acc = 0;
        for (int i = 0; i < N; i++){
            acc = (10*acc + s[i] - '0') % tot;
            if (i >= L-1) used[acc] = true;
        }

        if (enumerate(0, tot/10)) return;
    }
}

int main(){
    used.resize(1000100);

    scanf("%d", &T);

    while (T--){
        scanf("%d %s", &N, s);
        solve();
    }
}
