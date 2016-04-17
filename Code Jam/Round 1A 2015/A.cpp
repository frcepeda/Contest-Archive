#include <cstdio>
#include <algorithm>

using namespace std;

int T, N;
int m[10010];

int one(){
	int i, r = 0;
	for (i = 1; i < N; i++)
		r += max(0, m[i-1] - m[i]);
	return r;
}

int two(){
	int i, rate = 0, r = 0;

	for (i = 1; i < N; i++)
		rate = max(rate, max(0, m[i-1] - m[i]));

	for (i = 1; i < N; i++)
		r += min(rate, m[i-1]);

	return r;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			scanf("%d", &m[i]);

		printf("Case #%d: %d %d\n", t, one(), two());
	}
}
