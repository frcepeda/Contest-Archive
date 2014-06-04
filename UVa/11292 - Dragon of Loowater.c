// Accepted
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 20010

int dragon[MAXN];
int knight[MAXN];
int n, m;

int main() {
	int i, j;
	
	while (scanf("%d %d", &n, &m), n){
		for (i = 0; i < n; i++)
			scanf("%d", &dragon[i]);
		for (i = 0; i < m; i++)
			scanf("%d", &knight[i]);
			
		sort(dragon, dragon+n);
		sort(knight, knight+m);
		
		int cost = 0;
		for (i = j = 0; i < n && j < m; i++){
			for (; j < m && knight[j] < dragon[i]; j++);
			cost += knight[j++];
		}
		
		if (i == n)
			printf("%d\n", cost);
		else
			printf("Loowater is doomed!\n");
	}
	
	return 0;
}
