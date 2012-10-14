#include <stdio.h>

int prime(int n){
	int i;
	for (i = 2; i < n; i++)
		if (!(n%i))
			return 0;
	return 1;
}

int main(){
	int n;

	while (scanf("%d", &n) != EOF){
		if (n == 1)
			printf("Unidad");
		else if (prime(n)) 
			printf("Primo");
		else
			printf("Compuesto");
		printf("\n");
	}

	return 0;
}

