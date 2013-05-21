#include <stdio.h>

int main(void){
	int acc = 0, i, n;

	for (i = 0; i < 10; i++){
		scanf("%d", &n);

		if (acc + n <= 100 || 100 - acc >= acc + n - 100)
			acc += n;
		else
			break;
	}

	printf("%d\n", acc);
	
	return 0;
}
