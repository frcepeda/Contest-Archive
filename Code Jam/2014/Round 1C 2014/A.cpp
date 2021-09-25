#include <cstdio>
#include <algorithm>

using namespace std;

int T;
long long P, Q, g;

int main(){
	int t;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int ans = 40;

		printf("Case #%d: ", t);

		scanf("%lld/%lld", &P, &Q);
		g = __gcd(P,Q);
		P /= g;
		Q /= g;

		if ((1L<<40) % Q != 0){
			printf("impossible\n");
			continue;
		}

		P *= (1LL<<40) / Q;

		for (ans = 40; P > 1; ans--)
			P /= 2;

		printf("%d\n", ans);
	}
}
