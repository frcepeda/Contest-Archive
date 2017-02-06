#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int T;
ll N, M, K;

int f(int w, int h){
	if (w < 3 + 2*K) return -1;
	if (h < K + 1) return -1;

	w = 2 + 2*K;
	h = h-K;

	int z = min(w, h);

	return (z + K-1) / K + 1;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%lld %lld %lld", &N, &M, &K);

		int l = f(N, M);
		int r = f(M, N);

		int ans = l == -1 ? r : r == -1 ? l : min(l, r);

		printf("Case #%d: %d\n", t, ans);
	}
}
