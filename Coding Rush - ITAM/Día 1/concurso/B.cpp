#include <stdio.h>

int main(){
	int acc = 0, n;

	do {
		scanf("%d", &n);
		if (n % 2 == 0)
			acc += n;
	} while (n != 0);

	printf("%d\n", acc);

	return 0;
}
