// Accepted
#include <stdio.h>

int H, U, D, F;

int main(void) {
	int i, d;
	
	while (scanf("%d %d %d %d", &H, &U, &D, &F), H){
		H *= 100;
		U *= 100;
		D *= 100;
		F = U*F/100;
		i = 0;
		for (d = 0; i >= 0 && i <= H; d++){
			i += U;
			if (i > H) break;
			i -= D;
			U -= F;
			if (U < 0) U = 0;
		}
		printf("%s on day %d\n", i < 0 ? "failure" : "success",
		                         d + (i>0) );
	}
	
	return 0;
}
