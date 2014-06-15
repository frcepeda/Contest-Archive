// Accepted
#include <stdio.h>
#include <strings.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 101000

int T, N;
bool used[MAXN];

int main(void){
	int i, t, a;

	scanf("%d", &T);

	while (T--){
		bool first = true;

		scanf("%d", &N);

		memset(used, 0, MAXN);

		for (i = 0; i < N; i++){
			scanf("%d", &a);
			assert(a < MAXN);
			if (!used[a]){
				printf("%s%d", first ? "" : " ", a);
				used[a] = true;
				first = false;
			}
		}

		printf("\n");
	}

	return 0;
}
