#include <stdio.h>

int main(void){
	int t, n, i;

	scanf("%d", &t);

	while (t--){
		int s = 0;

		scanf("%d", &n);
		i = n;

		while (i--){
			int k;
			scanf("%d", &k);
			s += k;
		}

		printf("%d\n", s / n);
	}

	return 0;
}
