#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, even[2], odd[2];

int main(){
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if (x % 2) odd[0]++; else even[0]++;
    }

    for (int i = 0; i < m; i++){
        int x;
        scanf("%d", &x);
        if (x % 2) odd[1]++; else even[1]++;
    }

    printf("%d\n", min(even[0], odd[1]) + min(even[1], odd[0]));
}
