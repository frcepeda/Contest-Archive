#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
char s[maxn];
int cnt[30], n;

bool works(){
	for (int i = 0; i < 26; i++)
		if (cnt[i] == n)
			return true;

	for (int i = 0; i < 26; i++)
		if (cnt[i] > 1)
			return true;

	return false;
}

int main(){
	scanf("%d %s", &n, s);

	for (int i = 0; i < n; i++)
		cnt[s[i] - 'a']++;

	printf("%s\n", works() ? "Yes" : "No");
}
