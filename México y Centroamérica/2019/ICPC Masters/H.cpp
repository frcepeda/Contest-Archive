#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000100;
int N, Q;
long long A[maxn];

int main(){
    scanf("%d %d", &N, &Q);

    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    sort(A, A+N);

    while (Q--){
        long long S;
        scanf("%lld", &S);

        long long ans = 0;

        for (int i = 0, j = N-1; i < N; i++){
            for (; j >= 0 && A[i] + A[j] > S; j--);
            ans += max(j - i, 0);
        }

        printf("%lld\n", ans);
    }
}
