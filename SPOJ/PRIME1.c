#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAXRANGE 100100

bool notPrime[MAXRANGE];

int main(void){
	int t, m, n, i, j, lim;

	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &m, &n);

		lim = sqrt(n) + 1;

		for (i = 0; i < MAXRANGE; i++)
			notPrime[i] = false;

		for (i = m % 2; i <= n-m; i += 2)
			notPrime[i] = true;

		if (m <= 1)
			notPrime[1-m] = true;

		if (m <= 2)
			notPrime[2-m] = false;

		for (i = 3; i <= lim; i += 2)
			for (j = (m/i)*i; j <= n; j += i)
				if (m <= j && j != i)
					notPrime[j-m] = true;

		for (i = 0; i <= n-m; i++)
			if (!notPrime[i])
				printf("%d\n", i+m);

		if (t)
			printf("\n");
	}

	return 0;
}
