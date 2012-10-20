#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define memlim 2000000

long long int A, B;
long long int answer;
unsigned int mem[memlim];
bool visited[memlim];

unsigned int strength(long long int n){
	if (n == 2)
		return 1;
	if (n < memlim && visited[n])
		return mem[n];
	int i, ans;
	if (n < memlim)
		visited[n] = true;
	for (i = 2; i < n; i++){
		if (n % i){
			ans = strength(i)+1;
			break;
		}
	}
	if (n < memlim)
		mem[n] = ans;
	return ans;
}

int main(void){
	int i;

	scanf("%lld %lld", &A, &B);

	for (i = A; i <= B; i++)
		answer += strength(i);

	printf("%lld\n", answer);

	return 0;
}
