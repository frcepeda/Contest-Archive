#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 45
#define MAXC (1<<21)

int N, T;
long long s[MAXN];
long long A[MAXC], B[MAXC];
int Ac, Bc;

int main(){
	while (scanf("%d %d", &N, &T) != EOF){
		int i;

		for (i = 0; i < N; i++)
			scanf("%lld", &s[i]);

		A[0] = B[0] = 0;
		Ac = N/2; Bc = N - Ac;

		for (i = 0; i < Ac; i++)
			A[1<<i] = s[i];
		for (i = 1; i < (1<<Ac); i++)
			A[i] = A[i^(i&-i)] + A[i&-i];

		for (i = 0; i < Bc; i++)
			B[1<<i] = s[i+Ac];
		for (i = 1; i < (1<<Bc); i++)
			B[i] = B[i^(i&-i)] + B[i&-i];

		sort(A, A + (1<<Ac));
		sort(B, B + (1<<Bc));

		long long ans = 0;

		int l = (1<<Bc) - 1, r = (1<<Bc) - 1;
		for (int i = 0; i < (1<<Ac); i++){
			while (l >= 0 && A[i] + B[l] >= T) l--;
			while (r >= 0 && A[i] + B[r] > T) r--;
			if (r >= 0 && A[i] + B[r] == T){
				//printf("%lld\t%lld\n", A[i], B[r]);
				ans += r - l;
			}
		}

		printf("%lld\n", ans - (T == 0));
	}
}
