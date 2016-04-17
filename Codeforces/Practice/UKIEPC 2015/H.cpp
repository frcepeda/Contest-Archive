#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 2000100

#ifndef ONLINE_JUDGE
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

int N;
long long X[MAXN], H[MAXN];
int l[MAXN], r[MAXN];
int L[MAXN], R[MAXN];

int main(){
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf(LLD LLD, &X[i], &H[i]);
	
	X[0] = 0; X[N+1] = 1000000001LL;
	H[0] = H[1]; H[N+1] = H[N];

	l[0] = L[0] = 0;
	r[N+1] = R[N+1] = N+1;

	for (i = 1; i <= N; i++){
		H[0] = max(H[0], H[i]);

		l[i] = i-1;
		while (l[i] && H[l[i]] < H[i])
			l[i] = l[l[i]];

		L[i] = l[i];
		while (L[i] && (H[L[i]] - H[i]) * (X[L[i]] - X[L[L[i]]]) <
			(H[L[L[i]]] - H[L[i]]) * (X[i] - X[L[i]]))
			L[i] = L[L[i]];

		//printf("L %d %d\n", l[i], L[i]);
	}

	for (i = N; i > 0; i--){
		H[N+1] = max(H[N+1], H[i]);

		r[i] = i+1;
		while (r[i] != N+1 && H[r[i]] < H[i])
			r[i] = r[r[i]];

		R[i] = r[i];
		while (R[i] != N+1 && (H[R[R[i]]] - H[R[i]]) * (X[R[i]] - X[i]) >
		       (H[R[i]] - H[i]) * (X[R[R[i]]] - X[R[i]]))
			R[i] = R[R[i]];

		//printf("R %d %d\n", r[i], R[i]);
	}

	for (i = 1; i <= N; i++){
		H[0] = H[N+1] = H[i];

		double left = atan(((long double)(X[i] - X[L[i]]))/(H[i] - H[L[i]]));
		double right = atan(((long double)(X[i] - X[R[i]]))/(H[i] - H[R[i]]));

		printf("%.8lf\n", 12.0 / M_PI * (fabs(left) + fabs(right)));
	}
}
