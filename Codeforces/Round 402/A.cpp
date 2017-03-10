#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200200;
char s[maxn], t[maxn];
int a[maxn], b[maxn], n, m;

bool works(int x){
	int j = 0;

	for (int i = 0; i < n && j < m; i++)
		if (x < b[i] && s[i] == t[j])
			j++;

	return j == m;
}

int main(){
	scanf("%s %s", s, t);
	n = strlen(s);
	m = strlen(t);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		b[a[i]-1] = i;

	int lo = 0, hi = n, mid;

	while (lo <= hi){
		mid = (lo + hi) / 2;
		if (works(mid))
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	printf("%d\n", lo);
}
