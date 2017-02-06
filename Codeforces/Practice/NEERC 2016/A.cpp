#include <cstdio>
#include <algorithm>
#include <stack>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

const int maxn = 100100;
int n, a[2*maxn], l[2*maxn], r[2*maxn];

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i+n] = a[i];
	}

	stack<int> s;

	for (int i = 0; i < 2*n; i++){
		while (!s.empty() && a[s.top()] >= a[i])
			s.pop();
		l[i] = s.empty() ? -1 : s.top();
		s.push(i);
	}

	while (!s.empty()) s.pop();

	for (int i = 2*n-1; i >= 0; i--){
		while (!s.empty() && a[s.top()] >= a[i])
			s.pop();
		r[i] = s.empty() ? -1 : s.top();
		s.push(i);
	}

	pair<int, pair<int, pair<int,int>>> ans = mp(1<<30, mp(0, mp(0,0)));

	for (int i = 0; i < 2*n; i++)
		if (r[i] >= 0 && l[i] >= 0)
			ans = min(ans, mp(r[i] - l[i] + 1, mp(l[i], mp(i, r[i]))));

	ans.snd.fst %= n;
	ans.snd.fst++;
	ans.snd.snd.fst %= n;
	ans.snd.snd.fst++;
	ans.snd.snd.snd %= n;
	ans.snd.snd.snd++;

	printf("%d %d %d\n", ans.snd.fst, ans.snd.snd.fst, ans.snd.snd.snd);
}
