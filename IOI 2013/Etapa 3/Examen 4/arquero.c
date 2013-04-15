#include <stdio.h>
#include <math.h>
#include <stdbool.h>

unsigned long long int N, answer;

int _cos[6] = {2,1,-1,-2,-1,1};
int _sin[6] = {0,1,1,0,-1,-1};

unsigned long long int square(unsigned long long int a){
	return a * a;
}

bool fits(int i, int j){
	int x = i * 3;
	int y = j * 2 + (i % 2);
	int k;

	for (k = 0; k < 6; k++)
		if (square(x + _cos[k]) + 3 * square(y + _sin[k]) > 4*N*N)
			return false;

	return true;
}

int _bsearch(int column){
	int hi = 10000000, lo = 0, mid;

	while (lo < hi){
		int mid = (hi + lo) / 2;
		if (!fits(column, mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	if (column % 2 == 0)
		hi = (hi - 1) * 2 + 1;
	else
		hi *= 2;

	if (column > 0)
		hi *= 2;

	return hi;
}

int main(void){
	int i;

	scanf("%lld", &N);

	for (i = 0; fits(i,0); i++)
		answer += _bsearch(i);

	printf("%lld\n", answer);

	return 0;
}
