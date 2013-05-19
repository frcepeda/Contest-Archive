#include <stdio.h>

int plus, minus;
int n, m, l, r;

int main(void){
	int i;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++){
		scanf("%d", &l);
		if (l == 1)
			plus++;
		else
			minus++;
	}

	for (i = 0; i < m; i++){
		scanf("%d %d", &l, &r);
		int d = r - l + 1;
		if (d % 2 == 1 || plus - d/2 < 0 || minus - d/2 < 0)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}
