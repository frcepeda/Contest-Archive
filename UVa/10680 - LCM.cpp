#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000010

int P[MAXN];
char Z[MAXN] = {0, 1};

int power(int n, int e){
	int r = 1;
	
	for (; e; e /= 2){
		if (e % 2)
			r = (r * n) % 10;
		n = (n * n) % 10;
	}
	
	return r;
}

int main() {
	int two = 0, five = 0, p = 1, N;
	
	for (int i = 2; i < MAXN; i++){
		int j = i, a, b;
		
		for (b = 0; j % 2 == 0; j /= 2)
			b++;
		P[2] = max(P[2], b);
		
		for (a = 3; a*a <= j; a += 2){
			for (b = 0; j % a == 0; j /= a)
				b++;
			
			if (a != 5 && b > P[a])
				p = p * power(a, b - P[a]) % 10;
			
			P[a] = max(b, P[a]);
		}
		
		if (j != 5 && !P[j])
			p = p * j % 10;
		
		if (!P[j])
			P[j] = 1;
		
		j = min(P[2], P[5]);
		
		Z[i] = p * power(2, P[2] - j) * power(5, P[5] - j) % 10;
	}
	
	while (scanf("%d", &N), N)
		printf("%d\n", (int)Z[N]);
}
