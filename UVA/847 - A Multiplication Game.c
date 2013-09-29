// Accepted
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void){
	unsigned int N;

	while (scanf("%d", &N) != EOF){
		bool wins = true;

		while (N != 1){
			N = ceil((double)N/(wins ? 9 : 2));
			wins ^= true;
		}

		printf("%s wins.\n", wins ? "Ollie" : "Stan");
	}

	return 0;
}
