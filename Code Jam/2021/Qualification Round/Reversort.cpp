#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int T, N;
vector<int> v;

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d", &N);

        v.clear();

        for (int i = 0; i < N; i++){
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }

        int ans = 0;
        for (int i = 0; i < N-1; i++){
            int x = find(v.begin(), v.end(), i+1) - (v.begin() + i) + 1;
            reverse(v.begin()+i, v.begin()+i+x);
            ans += x;
        }

        printf("Case #%d: %d\n", t, ans);
    }
}
