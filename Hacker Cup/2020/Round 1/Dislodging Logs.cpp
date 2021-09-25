#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000100;
int T, N, M, K, S;
int P[maxn], Q[maxn];
long long AP, BP, CP, DP;
long long AQ, BQ, CQ, DQ;

bool canDo(long long ql, long long qr, long long pos, long long t){
    t -= (qr - ql + 1) * ((long long) S);
    t -= ((long long) Q[qr]) - Q[ql] + min(abs(pos - Q[qr]), abs(pos - Q[ql]));
    return t >= 0;
}

bool works(long long x){
    int nextQ = 0;

    for (int i = 0; i < N && nextQ < M; i++){
        int QQ = nextQ;

        while (QQ < M && canDo(nextQ, QQ, P[i], x))
            QQ++;
        
        nextQ = QQ;
    }

    return nextQ == M;
}

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d %d %d %d", &N, &M, &K, &S);

        for (int i = 0; i < K; i++)
            scanf("%d", &P[i]);
        scanf("%lld %lld %lld %lld", &AP, &BP, &CP, &DP);
        for (int i = K; i < N; i++)
            P[i] = (AP * P[i-2] + BP * P[i-1] + CP) % DP + 1;

        for (int i = 0; i < K; i++)
            scanf("%d", &Q[i]);
        scanf("%lld %lld %lld %lld", &AQ, &BQ, &CQ, &DQ);
        for (int i = K; i < M; i++)
            Q[i] = (AQ * Q[i-2] + BQ * Q[i-1] + CQ) % DQ + 1;

        sort(P, P+N);
        sort(Q, Q+M);

        long long lo = 0, hi = 1LL<<62, mid;

        while (lo < hi){
            mid = (lo + hi) / 2;
            if (works(mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        printf("Case #%d: %lld\n", t, hi);
    }
}
