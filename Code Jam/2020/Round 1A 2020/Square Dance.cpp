#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 110;
int T, R, C;
int S[maxn][maxn];
ll ans;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int neighbor(int r, int c, int dir){
    while (true){
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (nr < 0 || nr >= R) break;
        if (nc < 0 || nc >= C) break;

        if (S[nr][nc])
            return S[nr][nc];
        
        r = nr;
        c = nc;
    }

    return 0;
}

bool round(){
    int tmp[maxn][maxn];

    bool died = false;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            tmp[i][j] = S[i][j];

            if (!S[i][j]) continue;

            ans += S[i][j];

            int ncount = 0, nsum = 0;
            for (int k = 0; k < 4; k++){
                int tmp = neighbor(i, j, k);
                if (!tmp) continue;
                ncount++;
                nsum += tmp;
            }

            if (S[i][j] * ncount < nsum){
                died = true;
                tmp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < R; i++)
        copy(tmp[i], tmp[i]+C, S[i]);

    return died;
}

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        ans = 0;

        scanf("%d %d", &R, &C);

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                scanf("%d", &S[i][j]);

        while (round());

        printf("Case #%d: %lld\n", t, ans);
    }
}