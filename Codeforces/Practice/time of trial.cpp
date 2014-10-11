#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100100
#define fst first
#define snd second

int n;
pair<int,int> s[MAXN];

int main(void){
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &s[i].fst);
	for (i = 0; i < n; i++)
		scanf("%d", &s[i].snd);

	sort(s, s + n);

	long long sum = 0;

	for (i = 0; i < n; i++){
		sum += s[i].snd;
		if (sum >= s[i].fst) break;
	}

	printf("%s\n", i < n ? "Redemption" : "Dire victory");
}
