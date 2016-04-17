#include <cstdio>
#include <algorithm>

using namespace std;

int n, x;
long long a[100010];

int main(){
	int i;
	long long acc = (1LL<<60);

	scanf("%d %d", &n, &x);
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	
	acc = *min_element(a, a + n);

	for (i = 0; i < n; i++)
		a[i] -= acc;

	acc *= n;

	for (i = x-1; a[i]; i = (i-1+n)%n)
		a[i]--, acc++;
	a[i] = acc;

	for (i = 0; i < n; i++)
		printf("%lld%c", a[i], i < n-1 ? ' ' : '\n');
}
