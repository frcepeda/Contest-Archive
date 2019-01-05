#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int n, r, a[maxn], v[maxn];

int main(){
	scanf("%d %d", &n, &r);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int ans = 0;
	for (int i = 0; i < n; i++){
		int j;
		for (j = n-1; j >= 0; j--)
			if (v[j] && abs(j - i) < r)
				break;

		if (j >= 0) continue;

		for (j = n-1; j >= 0; j--)
			if (a[j] && abs(j - i) < r)
				break;

		if (j < 0){
			ans = -1;
			break;
		}

		v[j] = true;
		ans++;
	}

	printf("%d\n", ans);
}
