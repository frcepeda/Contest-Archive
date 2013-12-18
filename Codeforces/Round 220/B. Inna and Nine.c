#include <stdio.h>
#include <strings.h>

#define MAXN 100010
#define isOdd(x) ((x) % 2)

unsigned long long int ans = 1;
int N;
char num[MAXN];

int main(void){
	int i, j = 0;

	scanf("%s", num);
	N = strlen(num);

	for (i = 0; i < N; i++)
		num[i] -= '0';

	for (i = 1; i < N; i++){
		if (num[i] + num[i-1] != 9){
			if (isOdd(i-j))
				ans *= (i-j+1)/2;
			j = i;
		}
	}

	if (isOdd(i-j))
		ans *= (i-j+1)/2;

	printf("%llu\n", ans);

	return 0;
}
