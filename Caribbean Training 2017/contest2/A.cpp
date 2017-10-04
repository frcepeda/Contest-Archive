#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200100;
int n;
long long m[maxn];
int p[maxn];

int main(){
	scanf("%d", &n);

	long long ans = 0;

	for (int i = 1; i <= n; i++){
		int t, mm;
		scanf("%d %d", &t, &mm);
		if (mm){
			m[i] = m[t] + mm;
			p[i] = t;
		} else {
			p[i] = p[p[t]];
			m[i] = m[p[t]];
		}
		ans += m[i];
	}

	printf("%lld\n", ans);
}
