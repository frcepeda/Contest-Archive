#include <cstdio>

using namespace std;

#define MAXA 100

unsigned long long a[MAXA] = {1,1,5};

int main() {
	int t, n, i;
	
	for (i = 3; i < MAXA; i++)
		a[i] = a[i-1] + 4 * a[i-2] + 2 * a[i-3];
	
	scanf("%d", &t);
	
	while (t--){
		scanf("%d", &n);
		printf("%llu\n", a[n]);
	}
}