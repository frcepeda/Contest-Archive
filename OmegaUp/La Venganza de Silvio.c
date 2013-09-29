// 100/100 points
#include <stdio.h>
#include <ctype.h>

unsigned long long int N, mod;
int len;

int main(void){
	char c;
	unsigned long long int ans = 1;
	int i;

	scanf("%llu %llu\n", &N, &mod);

	while (isdigit(c = getchar())){
		ans = (ans * ans) % mod;
		if (c == '1')
			ans = (ans * N) % mod;
	}

	printf("%llu\n", ans);

	return 0;
}
