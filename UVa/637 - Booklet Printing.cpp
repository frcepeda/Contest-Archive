// Accepted
// Fill the pages with the pattern from the example.

#include <cstdio>

int n, P;
int p[100][2];

int main(){
	int i, j;

	while (scanf("%d", &n), n){
		printf("Printing order for %d pages:\n", n);
		P = ((n + 3)/4) * 2;

		for (i = j = 1; i <= P && j <= n; i++, j++)
			p[i][j%2] = j;

		for (; i <= P; i++, j++)
			p[i][j%2] = 0;

		for (i = P; j <= n; i--, j++)
			p[i][j%2] = j;

		for (; i > 0; i--, j++)
			p[i][j%2] = 0;

		for (i = 1; i <= P; i++)
			if (p[i][0] || p[i][1]){
				printf("Sheet %d, %s: ", (i+1)/2, i%2 ? "front" : "back ");

				if (p[i][0])
					printf("%d, ", p[i][0]);
				else
					printf("Blank, ");

				if (p[i][1])
					printf("%d\n", p[i][1]);
				else
					printf("Blank\n");
			}
	}
}
