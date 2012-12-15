#include <stdio.h>
#include <stdbool.h>

char c[2] = {'X', '.'};
int R, C, A, B;

int main(void){
	int i, j, a, b;

	scanf("%d %d", &R, &C);
	scanf("%d %d", &A, &B);

	for (i = 0; i < R; i++){
		for (a = 0; a < A; a++){
			for (j = 0; j < C; j++){
				for (b = 0; b < B; b++){
					putchar(c[(i+j)%2]);
				}
			}
			putchar('\n');
		}
	}

	return 0;
}
