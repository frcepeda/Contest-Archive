#include <stdio.h>

#define MAXN 10010

int T, N;
int h[MAXN], b[MAXN];

int main(void){
	scanf("%d\n", &T);

	while (T--){
		int i = 0, ans = 0;
		char c;

		for (N = 1; (c = getchar()) != '\n'; N++){
			if (c == '_')
				h[N] = i;
			else if (c == '/')
				h[N] = ++i;
			else
				h[N] = --i;

			for (b[N] = N-1; b[N] && h[b[N]] < h[N]; b[N] = b[b[N]]);
		}

		N--;
		while (N){
			if (h[N] <= h[b[N]]){
				for (i = N-1; i > b[N]; i--)
					ans += h[N] - h[i];
				N = b[N];
			} else N--;
		}

		printf("%d\n", ans);
	}

	return 0;
}
