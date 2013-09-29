// 100/100 points
#include <stdio.h>
#include <ctype.h>

#define MAXN 1000

int bucket[MAXN];
int N;

int main(void){
	int i, tmp;
	char c;

	scanf("%*c%*c%d ", &N);
	
	for (i = 0; isalpha(c = getchar()); i = (i+1) % N)
		bucket[i] += toupper(c) - 'A' + 1;

	tmp = 1;
	for (i = 0; i < N; i++)
		tmp = (tmp * (bucket[i] % 10 + 1)) % 10;

	printf("%d-", tmp % 10 + 1);

	for (i = 0; i < N; i++)
		bucket[i] = 0;

	scanf(" %*c%*c%d ", &N);
	
	for (i = 0; isalpha(c = getchar()); i = (i+1) % N)
		bucket[i] += toupper(c) - 'A' + 1;

	tmp = 1;
	for (i = 0; i < N; i++)
		tmp = (tmp * (bucket[i] % 10 + 1)) % 10;

	printf("%c\n", 'A' + tmp % 10);

	return 0;
}
