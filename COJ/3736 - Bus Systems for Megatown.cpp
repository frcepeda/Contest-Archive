#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int T, P, N, cnt[maxn];

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d %d", &P, &N);

		fill(cnt, cnt + 1 + P);

		while (N--){
			int a, b;
			scanf("%d %d", &a, &b);
			cnt[a]++; cnt[b]++;
		}

		printf("%s\n", any_of(cnt+1, cnt+1+P, [](int x){ return x <= 1; }) ? "YES" : "NO");
	}
}
