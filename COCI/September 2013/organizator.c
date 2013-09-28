// 140/140 points

#include <stdio.h>

#define MAXARR 2001000
#define MAXF 2000

int N;
int factors[MAXF], mult[MAXF], fCount;
int count[MAXARR];

void factorize(int x){
	int i;
	fCount = 0;
	if (x % 2 == 0){
		factors[0] = 2;
		for (mult[0] = 0; x % 2 == 0; x /= 2)
			mult[0]++;
		fCount = 1;
	}
	for (i = 3; x != 1 && i < 1500; i += 2){
		if (x % i == 0){
			factors[fCount] = i;
			for (mult[fCount] = 0; x % i == 0; x /= i)
				mult[fCount]++;
			fCount++;
		}
	}
	if (x != 1){
		factors[fCount] = x;
		mult[fCount] = 1;
		fCount++;
	}
}

void getDivisors(int p, int acc){
	int i;
	if (p == fCount){
		count[acc]++;
		return;
	}

	getDivisors(p+1, acc);
	for (i = 0; i < mult[p]; i++){
		acc *= factors[p];
		getDivisors(p+1, acc);
	}
}

int main(void){
	int i;

	scanf("%d", &N);

	while (N--){
		int a;
		scanf("%d", &a);
		factorize(a);
		getDivisors(0, 1);
	}

	long long best = 0;
	for (i = 0; i < MAXARR; i++)
		if (count[i] > 1 && (long long) count[i] * i > best)
			best = (long long) count[i] * i;

	printf("%lld\n", best);

	return 0;
}
