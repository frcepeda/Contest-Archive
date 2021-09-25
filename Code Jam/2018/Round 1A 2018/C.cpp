#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, W, H, P;

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %d", &N, &P);

		for (int i = 0; i < N; i++)
			scanf("%d %d", &W, &H);

		if (W < H) swap(W, H);

		int S = 4 * (W + H);

		int ans = S, lo = S, hi = S;

		for (int i = 0; i < N; i++){
			lo += 2 * H;
			hi += 2 * W;

			if (hi < P) ans = hi;
			else if (lo < P) ans = P;
		}

		printf("Case #%d: %d\n", t, ans);
	}
}
