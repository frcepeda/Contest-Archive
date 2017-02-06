#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[200];

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a[x]++;
	}

	int ans = 0;

	for (int i = 0; i < 100; i++)
		ans = max(ans, a[i] + a[i+1]);

	printf("%d\n", ans);
}
