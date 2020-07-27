#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 55;
int T, N;
bool m[maxn][maxn];
char I[maxn], O[maxn];

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d", &N);

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                m[i][j] = i == j;
        
        scanf("%s", I+1);
        scanf("%s", O+1);

        for (int j = 1; j < N; j++){
            m[j][j+1] = O[j] == 'Y' && I[j+1] == 'Y';
            m[j+1][j] = I[j] == 'Y' && O[j+1] == 'Y';
        }

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    m[i][j] |= m[i][k] & m[k][j];

        printf("Case #%d:\n", t);
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++)
                printf("%c", m[i][j] ? 'Y' : 'N');
            printf("\n");
        }
    }
}
