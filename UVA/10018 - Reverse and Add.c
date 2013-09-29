// Accepted
#include <stdio.h>
#include <stdbool.h>

unsigned int reverse(unsigned int x){
	unsigned int r = 0;
	for (; x; x /= 10)
		r = (r * 10) + x % 10;
	return r;
}

bool isPalindrome(unsigned int x){
	return x == reverse(x);
}

int main(void){
	unsigned int n, cnt, N;

	scanf("%d", &N);

	while (N--){
		scanf("%u", &n);

		for (cnt = 0; !isPalindrome(n); cnt++)
			n += reverse(n);

		printf("%u %u\n", cnt, n);
	}

	return 0;
}
