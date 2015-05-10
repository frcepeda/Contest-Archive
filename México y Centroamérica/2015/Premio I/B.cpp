#include <cstdio>

#define MAXN 100010

long long N;
int T;

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%lld", &N);

		long long X = N * (N+1) / 2;

		for (int i = 1; i < N; i++){
			int x;
			scanf("%d", &x);
			X -= x;
		}

		printf("%lld\n", X);
	}
}
