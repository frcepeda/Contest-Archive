// 12/15 points
#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
    #define openFiles() freopen("sabotage.in", "r", stdin); freopen("sabotage.out", "w", stdout)
#else
    #define openFiles()
#endif

// USACO upload macros

#define MAXN 100100

int max(int a, int b){ return a > b ? a : b; }
double min(double a, double b){ return a < b ? a : b; }

int N, M[MAXN];
int P[MAXN];

int main(void){
    int i, k;

    openFiles();

    scanf("%d", &N);

    for (i = 1; i <= N; i++)
        scanf("%d", &M[i]);

    for (i = 1; i <= N; i++)
        P[i] = P[i-1] + M[i];

    double ans = (M[1] + M[N]) / 2.0L;

    for (k = 1; k < N-2; k++){
        int j = 0;
        for (i = k+1; i < N; i++)
            j = max(j, P[i] - P[i-k]);
        ans = min(ans, (P[N] - j) / (double)(N-k));
    }

    printf("%.03lf\n", ans);

    return 0;
}
