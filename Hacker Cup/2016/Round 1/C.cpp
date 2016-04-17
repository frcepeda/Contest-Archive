#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

#define MAXN 100100

int T;
ll N, A, B, C[MAXN], S[MAXN];

ld f(ll L, ll R){
	ld acc = 0;

	for (int i = 1; i <= N; i++){
		auto l = max(L, S[i-1]);
		auto r = min(R, S[i]);

		if (l >= r) continue;

		auto a = ld(l - S[i-1]);
		auto b = ld(r - S[i-1]);

		acc += (a+b)/2 * (b-a)/(B-A);
	}

	return acc;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%lld %lld %lld", &N, &A, &B);

		for (int i = 1; i <= N; i++){
			scanf("%lld", &C[i]);
			S[i] = C[i] + S[i-1];
		}

		ld ans = 0;

		auto a = A + (((-A) % S[N]) + S[N]) % S[N];
		auto b = B - (B % S[N]);

		if (a <= b){
			auto l = f(S[N] - (a - A), S[N]);
			auto m = f(0, S[N]) * ((b - a) / S[N]);
			auto r = f(0, B - b);

			ans = l + m + r;
		} else {
			ans = f(A % S[N], B % S[N]);
		}


		printf("Case #%d: %.10Lf\n", t, ans);
	}
}
