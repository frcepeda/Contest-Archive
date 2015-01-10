#include <cstdio>

using namespace std;

int i, d, k;
int c[30];

long long eval(long long n){
	long long r = 0;
	int j;
	
	for (j = i; j >= 0; j--)
		r = n * r + c[j];
		
	return r;
}

int main() {
	int C, j;
	
	scanf("%d", &C);
	
	while (C--){
		scanf("%d", &i);
		
		for (j = 0; j <= i; j++)
			scanf("%d", &c[j]);
			
		scanf("%d %d", &d, &k);
		
		long long lo = 0, mid, hi = 5000;
		
		while (lo < hi){
			mid = (lo + hi)/2;
			if (mid * (mid+1) * d / 2 >= k)
				hi = mid;
			else
				lo = mid + 1;
		}
		
		printf("%lld\n", eval(hi));
	}
}