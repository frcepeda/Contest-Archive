#include <cstdio>
#include <algorithm>

using namespace std;

int T, N;

int main(){
	scanf("%d", &T);

	while (T--){
		int c[5] = {0};
		scanf("%d", &N);

		for (int i = 0; i < N; i++){
			int z;
			scanf("%d", &z);
			c[z]++;
		}

		int ans = 0;
		for (int i = 4; i >= 1; i--){
			while (c[i]){
				int r = 4 - i;
				c[i]--; ans++;
				for (int j = i; j >= 1; j--)
					while (r >= j && c[j]){
						r -= j;
						c[j]--;
					}
			}
		}

		printf("%d\n", ans);
	}
}
