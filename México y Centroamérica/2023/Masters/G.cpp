#include <cstdio>
#include <algorithm>
#include <set>

int x;
std::set<int> ans;

int main() {
    scanf("%d", &x);

    for (int d = 1; d <= x; d++) {
        if (x % d) continue;
        if (d <= x/d) continue;
        if ((d + x/d) % 2) continue;
        ans.insert((d + x/d)/2);
    }

    printf("%lu", ans.size());
    bool first = true;
    for (auto w: ans) {
        printf("%c%d", first ? '\n' : ' ', w);
        first = false;
    }
    printf("\n");
}