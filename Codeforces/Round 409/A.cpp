#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 100100;
int n, p;
int a[maxn], b[maxn];
ll total;

bool works(double x){
	double r = x;

	for (int i = 0; i < n; i++){
		double y = (x * a[i] - b[i]) / p;
		if (y <= 0) continue;
		if (y > r) return false;
		r -= y;
	}

	return true;
}

int main(){
	scanf("%d %d", &n, &p);

	for (int i = 0; i < n; i++){
		scanf("%d %d", &a[i], &b[i]);
		total += a[i];
	}

	if (total <= p){
		printf("-1\n");
		return 0;
	}

	double lo = 0, hi = 1e50, mid;

	for (int i = 0; i < 200; i++){
		mid = (lo + hi)/2;
		if (works(mid))
			lo = mid;
		else
			hi = mid;
	}

	printf("%.8lf\n", hi);
}
