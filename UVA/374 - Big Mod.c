// Accepted
#include <stdio.h>

int main(void){
	int B, P, M;

	while (scanf("%d %d %d", &B, &P, &M) != EOF){
		int ans = 1;

		B %= M;
		for (; P; P /= 2){
			if (P % 2)
				ans = (ans * B) % M;
			B = (B * B) % M;
		}

		printf("%d\n", ans);
	}

	return 0;
}
