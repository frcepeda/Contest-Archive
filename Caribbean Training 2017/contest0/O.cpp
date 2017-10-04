#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10100;
int n;

#define fst first
#define snd second

typedef long long lld;
pair<lld,bool> e[maxn];

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%lld %lld", &e[i].fst, &e[i+n].fst);
		if (e[i].fst > e[i+n].fst)
			swap(e[i], e[i+n]);
		e[i+n].snd = true;
	}
	
	n *= 2;

	sort(e, e + n);

	int cnt = 0;
	long long ans = 0;

	for (int i = 0; i < n-1; i++){
		if (!e[i].snd) cnt++;
		else cnt--;

		if (e[i+1].fst != e[i].fst && cnt)
			ans += e[i+1].fst - e[i].fst;
	}

	printf("%lld\n", ans);
}
