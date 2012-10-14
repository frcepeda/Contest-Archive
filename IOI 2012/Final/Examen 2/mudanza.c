#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int weights[MAXN], containers[MAXN];

int main(void){
	int n,m,i,j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
		scanf("%d", &weights[i]);
	
	for (i = 0; i < m; i++)
		scanf("%d", &containers[i]);

	j = 0;
	for (i = 0; i < n; i++){
		if (j == m) break;
		if (containers[j] < weights[i])
			containers[j] -= weights[i];
		else
			j++, i--;
	}


	printf("%d\n", i + (i & 1 ? 1 : 0));

	return 0;
}