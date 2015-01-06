#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, A[110];

bool done(){
	char c;
	bool sawEOL = false;
	
	do {
		c = getchar();
		if (c == '\n') sawEOL = true;
	} while (c != EOF && !isdigit(c));
	
	ungetc(c, stdin);
	
	return c == EOF || sawEOL;
}

int main() {
	scanf("%d\n", &N);
	
	while (N--){
		int i, j, ans = 0;
		char c;
		
		for (M = 0; !done(); M++)
			scanf("%d", &A[M]);
		
		for (i = 0; i < M; i++)
			for (j = i+1; j < M; j++)
				ans = max(ans, __gcd(A[i], A[j]));
				
		printf("%d\n", ans);
	}
}