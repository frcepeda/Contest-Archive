#include <stdio.h>
#include <stdbool.h>

#define LIM 10000000
#define fsLIM LIM/2

bool isPalindrome(unsigned long long int n){
	int i = 0, len = 0;
	int digits[15];

	for (len = 0; n; len++, n /= 10)
		digits[len] = n % 10;

	for (i = 0; i < len/2; i++)
		if (digits[i] != digits[len-i-1])
			return false;

	return true;
}

int T, n;
unsigned long long int A, B, fsNums[fsLIM];

int search(unsigned long long int x){
	int lo = 0, hi = n, mid;
	while (lo < hi){
		mid = (lo + hi) / 2;
		if (fsNums[mid] >= x)
			hi = mid;
		else
			lo = mid + 1;
	}
	return hi;
}

int main(void){
	int i, t;

	for (i = 1; i <= LIM; i++)
		if (isPalindrome(i) && isPalindrome(((unsigned long long int)i) * i))
			fsNums[n++] = ((unsigned long long int)i) * i;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%lld %lld", &A, &B);
		printf("Case #%d: %d\n", t, search(B) - search(A) + (fsNums[search(B)] == B));
	}

	return 0;
}
