// Wrong Answer
#include <stdio.h>

int main(void){
	printf("PERFECTION OUTPUT\n");
	int n;
	while (scanf("%d", &n), n){
		int sum = 1, i;

		for (i = 2; i*i <= n; i++){
			if (n % i == 0){
				sum += i;
				if (n/i != i)
					sum += n/i;
			}
		}

		printf("%5d  %s\n", n, sum < n ? "DEFICIENT" : sum > n ? "ABUNDANT" : "PERFECT");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
