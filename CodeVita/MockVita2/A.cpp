#include <cstdio>
#include <algorithm>

using namespace std;

int N;

long long f(long long n){
	return 2*n * (4*n - 1);
}

int main(){
	scanf("%d", &N);

	int k = 1;

	for (int i = 1; i <= N; i++){
		/*
		for (int j = i; j < N; j++)
			putchar(' ');
		*/
		for (int j = 0; j < i; j++, k++)
			printf("%05lld%c", f(k), j+1 < i ? ' ' : '\n');
	}
}
