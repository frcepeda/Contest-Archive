// 80/80 points

#include <stdio.h>

int N, M, ans;

int min(int a, int b){
	return a < b ? a : b;;
}

int gcd(int a, int b){
	int c;
	while (b){
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int lcm(int a, int b){
	return a * b / gcd(a,b);
}

int f(int N, int M){
	if (N % M == 0)
		return 0;
	else if (N < M){
		if (M % N == 0) return M - N;
		int cuts = M / N;
		return min(N * cuts + f(N, M - N * cuts),
		           M - (N * M) / lcm(N,M));
	} else
		return min(f(M,N), M - (N * M) / lcm(N,M));
}

int main(void){
	int i;

	scanf("%d %d", &N, &M);

	printf("%d\n", f(N,M));

	return 0;
}
