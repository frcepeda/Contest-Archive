#include <stdio.h>

int count[10];

int main(){
	int i;

	while (scanf("%d", &i) != EOF){
		while (i){
			count[i%10]++;
			i /= 10;
		}
	}

	for (i = 0; i <= 9; i++)
		printf("%d-%ds\n", count[i], i);

	return 0;
}

