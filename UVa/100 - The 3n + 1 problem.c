// Accepted
#include <stdio.h>

#define MAXNUM 3000000
#define MAXJ 1000000

int cLength[MAXNUM] = {0,1};

int collatz(unsigned int i){
	if (i < MAXNUM){
		if (cLength[i])
			return cLength[i];
		else if (i % 2 == 0)
			return cLength[i] = 1 + collatz(i/2);
		else
			return cLength[i] = 1 + collatz(3*i+1);
	} else {
		if (i % 2 == 0)
			return 1 + collatz(i/2);
		else
			return 1 + collatz(3*i+1);
	}
}

int main(void){
	int i, j;

	for (i = 1; i < MAXJ; i++)
		collatz(i);

	while (scanf("%d %d", &i, &j) != EOF){
		int k, m = 0;

		for (k = i; k <= j; k++)
			if (cLength[k] > m)
				m = cLength[k];

		for (k = j; k <= i; k++)
			if (cLength[k] > m)
				m = cLength[k];

		printf("%d %d %d\n", i, j, m);
	}

	return 0;
}
