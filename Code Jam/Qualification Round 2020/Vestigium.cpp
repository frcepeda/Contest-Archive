#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 110;
int T, N, M[maxn][maxn];
bool used[maxn];

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &M[i][j]);
        
        int trace = 0, rows = 0, cols = 0;

        for (int i = 0; i < N; i++)
            trace += M[i][i];
        
        for (int i = 0; i < N; i++){
            fill(used, used + N, false);

            for (int j = 0; j < N; j++)
                used[M[i][j]-1] = true;
            
            if (!all_of(used, used+N, [](bool x){ return x; }))
                rows++;
        }

        for (int j = 0; j < N; j++){
            fill(used, used + N, false);

            for (int i = 0; i < N; i++)
                used[M[i][j]-1] = true;
            
            if (!all_of(used, used+N, [](bool x){ return x; }))
                cols++;
        }

        printf("Case #%d: %d %d %d\n", t, trace, rows, cols);
    }
}