#include <cstdio>
#include <cstring>

using namespace std;

char s[100010], t[100010];
int n, m;
int b[500];

int main(){
	long long ans = 0;

#ifdef ONLINE_JUDGE
	freopen("concatenation.in", "r", stdin);
	freopen("concatenation.out", "w", stdout);
#endif

	scanf("%s %s", s, t);
	n = strlen(s);
	m = strlen(t);

	for (int i = 0; i < m; i++)
		b[t[i]]++;

	for (int i = 1; i <= n; i++){
		ans += m - b[s[i]];
		if (s[i] == t[m-1]) ans++;
		//printf("* %d\n", m - b[s[i]]);
	}

#ifdef ONLINE_JUDGE
	printf("%I64d\n", ans);
#else
	printf("%lld\n", ans);
#endif
}
