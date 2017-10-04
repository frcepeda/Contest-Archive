#include <cstdio>
#include <algorithm>

using namespace std;

int n, x[50100], y[50100];

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);

	x[n] = x[0];
	y[n] = y[0];

	int ans = 0;

	for (int i = 0; i < n; i++)
		ans += x[i] * y[i+1] - y[i] * x[i+1];

	printf("%.4lf\n", double(ans)/2);
}
