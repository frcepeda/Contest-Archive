// 50/50 points
#include <stdio.h>
#include <string.h>

#define MAXN 105
#define MAXL 20

int N;
char str[MAXN][MAXL];

int main(void){
	int i, j, k;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%s", str[i]);

	for (i = 0; i < N; i++){
		char tmp[MAXL];
		k = strlen(str[i]);

		for (j = 0; j < k; j++)
			tmp[j] = str[i][k-j-1];
		tmp[k] = '\0';

		for (j = 0; j < N; j++)
			if (strcmp(tmp, str[j]) == 0)
				break;

		if (j < N) break;
	}

	j = strlen(str[i]);

	printf("%d %c\n", j, str[i][j/2]);

	return 0;
}
