#include <cstdio>
#include <algorithm>

using namespace std;

int n, s;
pair<int,int> p[1100];

#define fst first
#define snd second

int main(){
	int ans = 0, i;

	scanf("%d %d", &n, &s);

	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i].fst, &p[i].snd);

	sort(p, p + n, greater<pair<int,int>>());

	for (i = 0; i < n; i++){
		ans = max(ans + s - p[i].fst, p[i].snd);
		s = p[i].fst;
	}

	printf("%d\n", ans + s);
}
