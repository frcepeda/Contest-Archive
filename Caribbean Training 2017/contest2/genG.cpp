#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
	int n, m;

	scanf("%d %d", &n, &m);
	printf("%d %d\n", n, m);

	for (int i = 0; i < m; i++){
		int l = rand()%n+1;
		int r = rand()%n+1;
		int k = rand()%(n + 1 - max(l,r)) + 1;
		printf("%d %d %d\n", k, l, r);
	}
}
