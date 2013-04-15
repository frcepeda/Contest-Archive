#include <stdio.h>
#include <strings.h>
#include <ctype.h>

#define BASE 101
#define MAXN 5000010

unsigned long long int base[MAXN];
unsigned long long int hash[2][MAXN];
char str[MAXN];
int degree[MAXN];
int N, answer;

int main(void){
	int i;

	fgets(str, MAXN, stdin);

	for (N = 0; isalnum(str[N]); N++)
		str[N] -= '0';

	base[0] = 1;
	for (i = 1; i <= N; i++)
		base[i] = base[i-1] * BASE;

	hash[0][0] = hash[1][0] = str[0];
	for (i = 1; i < N; i++){
		hash[0][i] = hash[0][i-1] * BASE + str[i];
		hash[1][i] = hash[1][i-1] + str[i] * base[i];
	}

	answer = degree[0] = 1;
	for (i = 1; i < N; i++){
		if (hash[0][i] == hash[1][i]){
			degree[i] = degree[(i+1)/2 - 1] + 1;
			answer += degree[i];
		}
	}

	printf("%d\n", answer);

	return 0;
}
