#include <stdio.h>

int N, i, j;

int main(void){
	while (scanf("%d %d %d", &N, &i, &j) != EOF){
		int r;

		i--, j--;
		i /= 2;
		j /= 2;

		for (r = 1; i != j; r++){
			i /= 2;
			j /= 2;
		}

		printf("%d\n", r);
	}

	return 0;
}
