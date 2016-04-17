#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 100100
#define fst first
#define snd second

typedef pair<int,int> pii;

int k, n;
pair<int,int> t[MAXN];

bool cmp(const pii &a, const pii &b){
	return a.snd < b.snd || (a.snd == b.snd && a.fst > b.fst);
}

int main(){
	int i, ans = 0;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
		scanf("%d %d", &t[i].fst, &t[i].snd);
	
	sort(t, t + n, cmp);

	map<int,int> a;
	a[0] = k;
	for (i = 0; i < n; i++){
		auto z = a.upper_bound(t[i].fst);
		if (z != a.begin()){
			z--;
			z->snd--;
			if (z->snd == 0)
				a.erase(z);
			a[t[i].snd]++;
			ans++;
		}
	}

	printf("%d\n", ans);
}
