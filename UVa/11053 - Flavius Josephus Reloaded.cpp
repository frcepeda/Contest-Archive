#include <cstdio>

using namespace std;

typedef unsigned long long ull;

int N, a, b;

int f(ull x){
	return (a*((x*x)%N) + b) % N;
}

int main() {
	while (scanf("%d %d %d", &N, &a, &b) == 3){
		int t = f(0), h = f(f(0)), c = 1;
		
		while (t != h){
			t = f(t);
			h = f(f(h));
		}
		
		for (h = f(h); h != t; c++)
			h = f(h);
		
		printf("%d\n", N - c);
	}
}