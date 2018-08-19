#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 150100;
int n;
int a[maxn][2];

bool works(int x){
	for (int i = 0; i < n; i++)
		if (a[i][0] % x && a[i][1] % x)
			return false;
	return true;
}

int go(int x){
	for (ll i = 2; i*i <= x; i++)
		if (x % i == 0){
			if (works(i))
				return i;
			while (x % i == 0)
				x /= i;
		}

	return x > 1 && works(x) ? x : -1;
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i][0], &a[i][1]);

	printf("%d\n", max(go(a[0][0]), go(a[0][1])));
}
