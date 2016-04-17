#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 3000010

int N;
bool isTriangular[MAXN];

int main(){
	/*
	int m = 0;
	for (int i = 1; i < MAXN; i++){
		int acc = 0;
		dp[i] = 1<<30;
		for (int j = 1; (acc += j) <= i; j++)
			dp[i] = min(dp[i], 1 + dp[i - acc]);
		m = max(m, dp[i]);
	}
	
	printf("%d\n", m);
	*/

	for (int i = 0, j = 0; (j += i) < MAXN; i++)
		isTriangular[j] = true;

	while (scanf("%d", &N) == 1){
		if (isTriangular[N]){
			printf("1\n");
			continue;
		}
		
		int i, j;
		for (i = 0, j = 0; (j += i) <= N; i++)
			if (isTriangular[N-j])
				break;

		if (N-j >= 0)
			printf("2\n");
		else
			printf("3\n");
	}
}
