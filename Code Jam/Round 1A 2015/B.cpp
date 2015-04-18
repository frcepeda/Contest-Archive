#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, B, M[1010];

long long f(long long t){
	long long r = 0;

	for (int i = 0; i < B; i++)
		r += (t + M[i] - 1) / M[i];

	return r;
}

int barber(int N){
	long long lo = 0, hi = (1LL<<45), mid;

	while (lo < hi){
		mid = (lo + hi) / 2;

		if (f(mid) >= N)
			hi = mid;
		else
			lo = mid + 1;
	}

	long long t = hi - 1, c = f(t);

	for (int i = 0; i < B; i++)
		if (t % M[i] == 0){
			c++;
			if (c == N)
				return i;
		}
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %d", &B, &N);

		for (int i = 0; i < B; i++)
			scanf("%d", &M[i]);

		printf("Case #%d: %d\n", t, barber(N) + 1);
	}
}
