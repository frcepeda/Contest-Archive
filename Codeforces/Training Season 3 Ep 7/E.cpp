#include <cstdio>
#include <algorithm>

using namespace std;

int T, n, w[50], h[50];

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &w[i]);

		for (int i = 0; i < n; i++)
			scanf("%d", &h[i]);

		sort(w+1, w+n);
		sort(h, h + n, greater<int>());

		int b = w[0] * h[0], i;

		for (i = 1; i < n; i++)
			if (b <= w[i] * h[i])
				break;

		printf("%s\n", i < n ? "NO" : "YES");
	}
}
