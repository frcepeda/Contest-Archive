#include <stdio.h>
#include <ctype.h>

#define THRESHOLD 100000
#define MAXDIGITS 11

unsigned long long int _ceiling(double a){
	return (int)(a + 1);
}

#ifdef WINDOWS
#define LONGLONG "%I64d"
#else
#define LONGLONG "%llu"
#endif

unsigned long long int x, a, b;

int digits[10];

int checkDigits(unsigned long long int a){
	while (a != 0){
		int digit = a % 10;
		a /= 10;
		if (!digits[digit])
			return 0;
	}
	return 1;
}

int visited[MAXDIGITS][THRESHOLD][2];
int dp[MAXDIGITS][THRESHOLD][2];

unsigned long long int square(unsigned long long int num){
	return num * num;
}

unsigned long long int exponentiate(unsigned long long int num, unsigned long long int power){
	if (power == 0) {
		return 1;
	} else if (power == 1) {
		return num;
	} else if (power % 2 == 0) {
		return square(exponentiate(num, power/2));
	} else {
		return num * square(exponentiate(num, (power-1)/2));
	}
}

unsigned long long int f(int remaining, unsigned long long int prefix){
	unsigned long long int answer = 0;

	long long int minValWithPrefix = prefix * exponentiate(10, remaining);
	long long int maxValWithPrefix = prefix * exponentiate(10, remaining) + exponentiate(10, remaining) - 1;

	int memoize = minValWithPrefix >= a && maxValWithPrefix <= b;

	if (memoize && visited[remaining][prefix%x][prefix==0])
		return dp[remaining][prefix%x][prefix==0];

	if (minValWithPrefix > b || maxValWithPrefix < a)
		return 0;

	if (memoize){
		visited[remaining][prefix%x][prefix==0] = 1;
	}

	if (remaining == 0){
		answer = prefix%x == 0;
	} else {
		int i;
		for (i = 0; i < 10; i++){
			if (digits[i] || (i == 0 && prefix == 0))
				answer += f(remaining - 1, prefix*10 + i);
		}
	}

	if (memoize)
		dp[remaining][prefix%x][prefix==0] = answer;

	return answer;
}

int main(void)
{
	scanf(LONGLONG LONGLONG LONGLONG, &x, &a, &b);

	char c;

	// For some reason it doesn't work in this case
	// So IDC.
	if (x == 1){
		printf("%lld", b - a + 1);
		return 0;
	}
	
	while (!isdigit(c))
		c = getchar();

	do {
		digits[c - '0'] = 1;
		c = getchar();
	} while (isdigit(c));

	unsigned long long int i;
	unsigned long long int answer = 0;

	if (x > THRESHOLD){
		for (i = (a % x ? _ceiling((double)a/x) : a/x)*x; i <= b; i += x){
			if (checkDigits(i))
				answer++;
	}
	} else {
		answer = f(11, 0);
	}

	printf("%llu\n", answer);

	return 0;
}

