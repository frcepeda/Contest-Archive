// Accepted
#include <stdio.h>

int main(void){
	int t;

	scanf("%d", &t);

	while (t--){
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < b)
			printf("<\n");
		else if (a > b)
			printf(">\n");
		else
			printf("=\n");
	}

	return 0;
}
