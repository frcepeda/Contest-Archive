#include <cstdio>
#include <algorithm>

using namespace std;

int m, n, p[15];

int main(){
	scanf("%d %d", &m, &n);

	p[1] = 1;

	while (n--){
		int a, b;
		scanf("%d %d", &a, &b);
		swap(p[a], p[b]);
	}

	for (int i = 1; i <= m; i++)
		if (p[i])
			printf("%d\n", i);
}
