#include <cstdio>

typedef long long ll;

int T, K, C;

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		printf("Case #%d:", t);

		scanf("%d %d %*d", &K, &C);

		ll d = 1;
		for (int i = 0; i < C-1; i++)
			d *= K;

		for (ll z = 1; z <= K*d; z += d)
			printf(" %lld", z);

		printf("\n");
	}
}
