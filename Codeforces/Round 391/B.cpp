#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int d[maxn], cnt[maxn];

int n;

int main(){
	d[0] = d[1] = 1;

	for (int i = 2; i < maxn; i += 2)
		d[i] = 2;

	for (int i = 3; i < maxn; i += 2)
		if (d[i] == 0)
			for (int j = i; j < maxn; j += i)
				d[j] = d[j] == 0 ? i : min(d[j], i);

	scanf("%d", &n);

	while (n--){
		int s, last = 0;
		scanf("%d", &s);

		while (s != 1){
			if (d[s] != last)
				cnt[d[s]]++;
			last = d[s];
			s /= d[s];
		}
	}

	int ans = 1;

	for (int i = 2; i < maxn; i++)
		ans = max(ans, cnt[i]);

	printf("%d\n", ans);
}
