#include <cstdio>
#include <cmath>

using namespace std;

int n, k, t;

int main(){
	scanf("%d %d", &n, &k);
	t = 4*60 - k;

	int i;
	for (i = 0; 5*i*(i+1)/2 <= t && i <= n; i++);

	printf("%d\n", i-1);
}
