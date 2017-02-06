#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int n, m, q;
int a[maxn], b[maxn];
bool ad[maxn], bd[maxn];
vector<int> ddd[maxn];
int d[maxn];

void ddds(int *s, int *e, bool r[maxn]){
	for (; s != e; s++)
		for (auto z: ddd[*s])
			r[z] = true;
}

void go(int x){
	if (!ddd[x].empty()) return;

	int k = 0, y = x, a = d[x];
	for (; y % a == 0; k++)
		y /= a;

	go(y);
	ddd[x] = ddd[y];
	for (auto w: ddd[y])
		for (int i = 0, z = 1; i < k; i++){
			z *= a;
			ddd[x].push_back(z * w);
		}
}

int main(){
	d[0] = d[1] = 1;
	for (int i = 2; i < maxn; i += 2)
		d[i] = 2;

	for (int i = 3; i*i < maxn; i += 2)
		if (!d[i]){
			d[i] = i;
			for (int j = i*i; j < maxn; j += i)
				d[j] = d[j] ? min(d[j], i) : i;
		}

	for (int i = 3; i < maxn; i += 2)
		if (!d[i])
			d[i] = i;

	ddd[1].push_back(1);
	for (int i = 2; i < maxn; i++)
		go(i);

	scanf("%d %d", &n, &m);
	scanf("%d", &q);


	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	while (q--){
		int x, y, z, w;
		scanf("%d %d %d %d", &x, &y, &z, &w);
		ddds(a + x, a + z + 1, ad);
		ddds(b + y, b + w + 1, bd);
		int ans = 0;
		for (int i = 0; i < maxn; i++){
			if (ad[i] && bd[i])
				ans++;
			ad[i] = bd[i] = false;
		}
		printf("%d\n", ans);
	}
}
