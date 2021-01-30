#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int maxn = 11;
int N, D;
int p[maxn][2];
ll adj[maxn][maxn];

int dist(int x, int y) {
    int a = p[x][0] - p[y][0];
    int b = p[x][1] - p[y][1];
    return a*a + b*b;
}

//https://www.tutorialspoint.com/cplusplus-program-to-compute-determinant-of-a-matrix

ll determinant(ll matrix[maxn][maxn], int n) {
   ll det = 0;
   ll submatrix[maxn][maxn];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + ((x % 2 ? -1 : 1) * matrix[0][x] * determinant( submatrix, n - 1 ) % mod) % mod;
      }
   }
   return det % mod;
}

int main(){
    while (scanf("%d %d", &N, &D), N != 0) {
        for (int i = 0; i < N; i++){
            scanf("%d %d", &p[i][0], &p[i][1]);
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                adj[i][j] = dist(i,j) <= D*D;
            }
        }

        for (int i = 0; i < N; i++){
            adj[i][i] = 0;
            for (int j = 0; j < N; j++){
                if (j == i) continue;
                adj[i][i] += adj[i][j];
            }
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (i == j) continue;
                adj[i][j] *= -1;
            }
        }

        auto tmp = (determinant(adj, N-1) % mod + mod) % mod;

        printf("%lld\n", tmp);
    }
}
