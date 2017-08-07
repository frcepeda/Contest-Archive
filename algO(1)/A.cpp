#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, K, S;

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d %d %d", &N, &K, &S);

		int best = 0;

		for (int i = 0; i <= K; i++){
			int l = S / (N + i);
			best = max(best, S - l * (N + i));
		}

		printf("%d\n", best);
	}
}
