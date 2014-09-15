#include <cstdio>

using namespace std;

int N, M, ans;

int main(void){
	scanf("%d %d", &N, &M);

	while (N--){
		int i, ok = 1, x;
		for (i = 0; i < M; i++){
			scanf("%d", &x);
			ok &= !!x;
		}
		ans += ok;
	}

	printf("%d\n", ans);
}
