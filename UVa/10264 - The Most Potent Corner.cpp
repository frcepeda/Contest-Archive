#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int A[1<<15];
int P[1<<15];

int main() {
	while (scanf("%d", &N) != EOF){
		int i, j, ans = 0;
		
		for (i = 0; i < (1<<N); i++)
			scanf("%d", &A[i]);
		
		for (i = 0; i < (1<<N); i++)
			for (j = P[i] = 0; j < N; j++)
				P[i] += A[i ^ (1<<j)];
		
		for (i = 0; i < (1<<N); i++)
			for (j = 0; j < N; j++)
				ans = max(ans, P[i] + P[i ^ (1<<j)]);
		
		printf("%d\n", ans);
	}
}