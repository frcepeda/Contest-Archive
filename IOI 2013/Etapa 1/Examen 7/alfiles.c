#include <stdio.h>
#include <stdbool.h>

#define MAXN 8

#define diag1(r,c) ((r)+(c))
#define diag2(r,c) diag1(N-1-r,c)

int N, K;
int answer;
bool inUse1[MAXN*2], inUse2[MAXN*2];

void tryBishops(int num, int count){
	if (count == K){
		answer++;
		return;
	} else if (num >= N*N){
		return;
	} else if (!inUse1[diag1(num/N, num%N)] && !inUse2[diag2(num/N, num%N)]){
		inUse1[diag1(num/N, num%N)] = inUse2[diag2(num/N, num%N)] = true;
		tryBishops(num+1, count+1);
		inUse1[diag1(num/N, num%N)] = inUse2[diag2(num/N, num%N)] = false;
	}
	tryBishops(num+1, count);
}

int main(void){
	scanf("%d %d", &N, &K);
	tryBishops(0, 0);
	printf("%d\n", answer);
	return 0;
}
