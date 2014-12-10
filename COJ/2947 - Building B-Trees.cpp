#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXH 20
#define MAXL 20100

int tests, L, T;
vector<int> tree[MAXH];
int cnt[MAXH];
int nums[MAXL];

int main(){
    scanf("%d", &tests);

    for (int t = 1; t <= tests; t++){
        scanf("%d %d", &T, &L);

        printf("Case #%d:\n", t);
        for (int i = 0; i < MAXH; i++){
            tree[i].clear();
            cnt[i] = 0;
        }

        for (int i = 0; i < L; i++)
            scanf("%d", &nums[i]);

        sort(nums, nums + L);

        int curr = 0, h = 0;
        for (int i = 0; i < L; i++){
            for (curr = 0; cnt[curr] == T-1; curr++) cnt[curr] = 0;
            h = max(curr, h);
            cnt[curr]++;
            tree[curr].push_back(nums[i]);
        }

        if (tree[h].size() != T-1) goto ded;

        for (int i = h-1; i >= 0; i--)
            if (tree[i].size() != tree[i+1].size() * T)
                goto ded;

        for (int i = h; i >= 0; i--){
            for (int j = 0; j < tree[i].size(); j++){
                printf("%d%c", tree[i][j], (j % (T-1) != T-2) ? ' ' : ';');
                if (j % (T-1) == T-2)
                    putchar(j != tree[i].size()-1 ? ' ' : '\n');
            }
        }

        continue;

ded:
        printf("INVALID\n");
    }
}
