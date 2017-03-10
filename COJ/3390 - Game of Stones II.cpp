#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000010

int N, P[MAXN];

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &P[i]);

	sort(P, P+N);

	int x = P[0] - P[0] % (N+1), i;
	for (i = 0; i < N; i++)
		if (P[i] - x < i + 1)
			break;

	printf("%c\n", i >= N ? 'N' : 'S');
}
