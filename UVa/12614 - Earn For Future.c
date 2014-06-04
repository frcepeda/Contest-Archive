#include <stdio.h>

int T, N;

int main(void){
	int t;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int ans = 0, a;
		scanf("%d", &N);

		while (N--){
			scanf("%d", &a);
			if (a > ans)
				ans = a;
		}

		printf("Case %d: %d\n", t, ans);
	}

	return 0;
}
