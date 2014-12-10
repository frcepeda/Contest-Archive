#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int T[1010];
int ans = 0;

int main(){
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &T[i]);

	sort(T, T + N);

	for (i = j = 0; i < N/2; i++)
		j += min(T[2*i+1] - T[2*i], 24 - T[2*i+1] + T[2*i]);
	ans = j;

	j = min(T[N-1] - T[0], 24 - T[N-1] + T[0]);
	for (i = 1; i < N/2; i++)
		j += min(T[2*i] - T[2*i-1], 24 - T[2*i] + T[2*i-1]);
	ans = min(j, ans);

	printf("%d\n", ans);
}
