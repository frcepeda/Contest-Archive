#include <cstdio>
#include <algorithm>

using namespace std;

int v[15], n;

int main(){
	int s = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		s += v[i];
	}

	int i;
	for (i = 0; i < n; i++){
		int g = 0;
		for (int j = 0; j < n; j++)
			if (j != i)
				g = max(g, v[j]);
		if (g > v[i]) continue;
		if (100*v[i] >= 45*s) break;
		if (100*v[i] < 40*s) continue;
		if (100*(v[i] - g) >= 10*s) break;
	}

	printf("%d\n", 1 + int(i >= n));
}
