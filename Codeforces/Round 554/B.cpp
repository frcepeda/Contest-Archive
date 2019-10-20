#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int x, ops;
    vector<int> nums;

    scanf("%d", &x);

    for (ops = 0; ((x+1)&-(x+1)) != x+1; ops++){
        if (ops % 2) x++;
        else {
            int j;
            for (j = 19; x & (1<<j); j--);
            nums.push_back(j+1);
            j = (1<<(j+1)) - 1;
            x ^= j;
        }
    }

    printf("%d\n", ops);
    for (auto x: nums)
        printf("%d\n", x);
}
