// Accepted
#include <stdio.h>

int main(void){
	int a, b, t;

	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &a, &b);
		
		if (b % a != 0)
			printf("-1\n");
		else
			printf("%d %d\n", a, b);
	}

	return 0;
}
