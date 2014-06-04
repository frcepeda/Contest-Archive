// Accepted
#include <stdio.h>

int main(void){
	int K, N, M, X, Y;

	while (scanf("%d", &K), K){
		scanf("%d %d", &N, &M);

		while (K--){
			scanf("%d %d", &X, &Y);
			X -= N;
			Y -= M;

			if (X == 0 || Y == 0)
				printf("divisa\n");
			else if (X > 0 && Y > 0)
				printf("NE\n");
			else if (X < 0 && Y > 0)
				printf("NO\n");
			else if (X < 0 && Y < 0)
				printf("SO\n");
			else
				printf("SE\n");
		}
	}

	return 0;
}
