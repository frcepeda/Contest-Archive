#include <stdio.h>

#define MAXN 7010

int a[MAXN], N, ans;

int main(void){
	int i, j, k;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < N; i++){
		j = i+1; k = i+2;
		for (; j < N && k < N; j++){
			for (; k < N && a[k] - a[j] < a[j] - a[i]; k++);
			if (k < N && a[k] - a[j] == a[j] - a[i]) ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
