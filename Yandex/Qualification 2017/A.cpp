#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200100;
int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		b[a[i]] = i;
	}

	int ans = 0;

	b[0] = n+1;

	for (int i = 1; i <= n; i++)
		if (b[a[i]-1] > i)
			ans++;

	printf("%d\n", ans);
}
