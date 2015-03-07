#include <cstdio>
#include <algorithm>

using namespace std;

long long a, b, n;
int T;

int main(){
	long long low, high, mid;
	int count;
	scanf("%d", &T);
	while(T--){
		scanf("%lld %lld %lld", &n, &a, &b);
		n = 1LL << n;
		low = 1;
		high = n;
		for (count = 1; low <= high; count++){
			mid = (high + low)/2;
			if (mid < min(a,b))
				low = mid + 1;
			else if (mid > min(a,b))
				high = mid - 1;
			else
				break;
		}
		printf("%d\n", count);
	}
}
