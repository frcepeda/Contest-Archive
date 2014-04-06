#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 100100

long long int n, k;
int a[MAXN];

int main(){
	int i, j;

	scanf("%I64d %I64d", &n, &k);
	k--;

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a+n);

	for (i = j = 0; i < n; i = j){
		for (; j < n && a[i] == a[j]; j++);

		if (n * (j - i) <= k)
			k -= n * (j - i);
		else {
			printf("%d %d\n", a[i], a[k / (j - i)]);
			break;
		}
	}
}
