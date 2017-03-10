#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1010
int C, N;
unsigned long long F[MAXN];

int main(){
	scanf("%d", &C);

	F[0] = 1;
	for (int i = 1; i < MAXN; i++)
		F[i] = F[i-1] + (i-1)*(i-2)*(i-3)/6 + i-1;

	while (C--){
		scanf("%d", &N);
		printf("%llu\n", F[N]);
	}
}
