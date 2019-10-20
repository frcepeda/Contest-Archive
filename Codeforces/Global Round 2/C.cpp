#include <cstdio>

using namespace std;

const int maxn = 505;
int n, m;
int a[maxn][maxn], b[maxn][maxn];
int r[maxn], c[maxn];

bool works(){
    for (int i = 0; i < n; i++)
        if (r[i] % 2)
            return false;

    for (int j = 0; j < m; j++)
        if (c[j] % 2)
            return false;
    
    return true;
}

int main(){
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != b[i][j])
                r[i]++, c[j]++;
    
    printf("%s\n", works() ? "Yes" : "No");
}
