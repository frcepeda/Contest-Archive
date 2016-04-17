#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

bool f(int x){
	int two = x / 2;
	int three = x / 3;
	int six = x / 6;
	int a = n - (two - six);
	int b = m - (three - six);
	if (a < 0) a = 0;
	if (b < 0) b = 0;
	return a + b <= six;
}

int main(){
	scanf("%d %d", &n, &m);

	int lo = 0, hi = 10000000, mid;

	while (lo < hi){
		mid = (lo + hi)/2;
		if (f(mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%d\n", hi);
}
