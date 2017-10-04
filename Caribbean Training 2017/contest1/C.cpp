#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 150100;
int n, m, c, x[maxn], d[maxn], p[maxn];
double t[4*maxn], a[maxn], s[maxn];

void build(int x = 0, int l = 0, int r = n-2){
	if (l == r){
		t[x] = a[l];
		return;
	}

	build(2*x+1, l, (l+r)/2);
	build(2*x+2, (l+r)/2+1, r);
	t[x] = max(t[2*x+1], t[2*x+2]);
}

double query(int a, int b, int x = 0, int l = 0, int r = n-2){
	if (b < l || r < a) return -1e30;

	if (a <= l && r <= b)
		return t[x];

	return max(query(a, b, 2*x+1, l, (l+r)/2),
	       query(a, b, 2*x+2, (l+r)/2+1, r));
}

int main(){
	scanf("%d %d %d", &n, &m, &c);

	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	for (int i = 0; i < n-1; i++)
		scanf("%d", &p[i]);

	for (int i = 0; i < n-1; i++)
		d[i] = x[i+1] - x[i];

	for (int i = 0; i < n-1; i++){
		a[i] = double(d[i]) / 2 - double(p[i]) / 100 * c;
		s[i+1] = a[i] + s[i];
	}

	build();

	double ans = 0;
	while (m--){
		int i, j;
		scanf("%d %d", &i, &j);
		ans += max(query(i-1, j-2), s[j-1] - s[i-1]);
	}

	printf("%.7lf\n", ans);
}
