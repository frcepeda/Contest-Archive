#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;
int T, N, W[maxn];

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			scanf("%d", &W[i]);

		sort(W, W + N);

		int l = 0, r = N-1, ans = 0;

		while (l <= r){
			int w = W[r];

			if (w*(r - l + 1) < 50)
				break;

			for (int soFar = W[r--]; soFar < 50; l++)
				soFar += w;
			
			ans++;
		}

		printf("Case #%d: %d\n", t, ans);
	}
}
