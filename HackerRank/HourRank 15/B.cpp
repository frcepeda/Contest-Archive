#include <cstdio>
#include <algorithm>

using namespace std;

int g, n, a[100100], m[100100];

int main(){
	scanf("%d", &g);

	while (g--){
		scanf("%d", &n);

		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			m[i] = a[i] > a[m[i-1]] ? i : m[i-1];
		}

		int steps = 0;
		for (int curr = n; curr; steps++, curr = m[curr]-1);

		printf("%s\n", steps % 2 ? "BOB" : "ANDY");
	}
}
