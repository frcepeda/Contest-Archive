#include <stdio.h>

#define MAXA 250

int a[MAXA];
int n, sum, zeros;
int up, down;

int abs(int a){
	return a >= 0 ? a : -a;
}

int absCmp(const int *a, const int *b){
	return abs(*a) - abs(*b);
}

int main(void){
	int i;

	scanf("%d", &n);

	for (i = 0; i < 2*n-1; i++){
		scanf("%d", &a[i]);
		sum += a[i];
		if (a[i] == 0) zeros++;
	}

	qsort(a, 2*n-1, sizeof(a[0]), absCmp);

	while (up < 2*n-1 && down >= 0){
		int rem = n;
		int new = sum;
		up = 0, down = 2*n-2;

		for (; down >= 0 && rem; down--){
			if (a[down] < 0){
				new -= 2*a[down];
				a[down] *= -1;
				rem--;
			}
		}

		for (; up < 2*n-1 && rem; up++){
			if (a[up] > 0){
				new -= 2*a[up];
				a[up] *= -1;
				rem--;
			}
		}

		if (rem - zeros <= 0 && new > sum){
			sum = new;
		} else break;
	}

	printf("%d\n", sum);

	return 0;
}
