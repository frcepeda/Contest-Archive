#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 5010;
int n, a[maxn], b[maxn], p[maxn], q[maxn];
bool v[maxn];

int query(int x){
	int i;
	for (i = 1; x || v[i]; i++)
		if (x && !v[i])
			x--;
	return i;
}

int main(){
	while (scanf("%d", &a[++n]) != EOF);
	n--;

	for (int i = n; i > 0; i--){
		p[i] = query(a[i]);
		v[p[i]] = true;
	}

	for (int i = 1; i <= n; i++)
		q[p[i]] = i;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (q[j] > q[i])
				b[i]++;

	for (int i = 1; i <= n; i++)
		printf("%d%c", q[i], i < n ? ' ' : '\n');
}
