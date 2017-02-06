#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

int cnt[256];
string o = "Blbsr", d = "ua";

int main(){
	char c;
	while (isalpha(c = getchar()))
		cnt[c]++;

	int ans = 1<<30;
	for (auto z: o)
		ans = min(ans, cnt[z]);
	for (auto z: d)
		ans = min(ans, cnt[z]/2);

	printf("%d\n", ans);
}
