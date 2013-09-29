// Accepted
#include <stdio.h>

int main(void){
	int T, t;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("Case %d: ", t);
		if (a < b && a < c)
			printf("%d\n", b < c ? b : c);
		else if (b < a && b < c)
			printf("%d\n", a < c ? a : c);
		else
			printf("%d\n", a < b ? a : b);
	}

	return 0;
}
