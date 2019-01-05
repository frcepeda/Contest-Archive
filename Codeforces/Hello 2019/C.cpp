// Accepted
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxm = 500100;
int n, L[maxm], R[maxm];

int main(){
	scanf("%d", &n);

	static char s[maxm];

	for (int i = 0; i < n; i++){
		scanf("%s", s);

		int l = 0, r = 0, acc = 0;
		for (int j = 0; s[j] != '\0'; j++){
			if (s[j] == ')'){
				if (!acc)
					l++;
				else
					acc--;
			} else acc++;
		}

		r = acc;

		if (l == 0)
			R[r]++;
		else if (r == 0)
			L[l]++;
	}

	int ans = R[0] / 2;
	for (int i = 1; i < maxm; i++)
		ans += min(L[i], R[i]);

	printf("%d\n", ans);
}
