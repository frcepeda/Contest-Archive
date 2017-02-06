#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 300100;
int n, q, nn = 1, l = 1;
bool v[MAXN];
int p[MAXN], s[MAXN];

int main(){
	scanf("%d %d", &n, &q);

	int unread = 0;
	while (q--){
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == 1){
			p[nn] = s[b];
			s[b] = nn++;
			unread++;
		} else if (a == 2){
			for (int c = s[b]; c && !v[c]; unread--, c = p[c])
				v[c] = true;
		} else {
			for (int i = min(l, b); i <= b; i++)
				if (!v[i]){
					unread--;
					v[i] = true;
				}
			l = max(l, b);
		}

		printf("%d\n", unread);
	}
}
