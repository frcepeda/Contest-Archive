#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define fst first
#define snd second

const int maxn = 800010;
int TT, N;
vector<pair<int,int>> T;
map<int,int> dp;

int main(){
    scanf("%d", &TT);

    for (int t = 1; t <= TT; t++){
        dp.clear();
        T.clear();

        scanf("%d", &N);

        for (int i = 0; i < N; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            T.emplace_back(a, b);
        }
        
        sort(T.begin(), T.end());

        int ans = 0;
        for (auto e: T){
            int p, h;
            tie(p, h) = e;

            dp[p+h] = max(dp[p+h], dp[p] + h);
            dp[p] = max(dp[p], dp[p-h] + h);

            ans = max(ans, max(dp[p], dp[p+h]));
        }

        printf("Case #%d: %d\n", t, ans);
    }
}
