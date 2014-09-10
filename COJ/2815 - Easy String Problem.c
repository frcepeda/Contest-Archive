// Accepted
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 510

int n, m;
char str[MAXN], pat[MAXN];

int main(void){
	int T, i, j, k;

	scanf("%d", &T);

	while (T--){
		bool del[MAXN] = {false};
		bool didsomething = true;
		int ans = 0;

		scanf("%s %s", str, pat);
		n = strlen(str);
		m = strlen(pat);

		while (didsomething){
			didsomething = false;

			for (i = 0; i < n; i++){
				for (j = k = 0; k < m && i + j < n; j++)
					if (!del[i+j]){
						if (str[i+j] == pat[k])
							k++;
						else break;
					}
				if (k == m){
					for (j = 0; k > 0; j++)
						if (!del[i+j]){
							del[i+j] = true;
							k--;
						}
					ans++;
					didsomething = true;
					break;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
