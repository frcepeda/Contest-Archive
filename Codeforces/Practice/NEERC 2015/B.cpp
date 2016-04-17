#include <cstdio>
#include <algorithm>

using namespace std;

int b, w;
int r, c;

int main(){
	int i;

#ifdef ONLINE_JUDGE
	freopen("black.in", "r", stdin);
	freopen("black.out", "w", stdout);
#endif

	scanf("%d %d", &b, &w);

	printf("2 %d\n", 2*max(b,w));

	for (i = 0; i < 2*max(b,w); i += 2)
		printf(b < w ? ".@" : "@.");
	putchar('\n');

	for (i = 0; i < 2*min(b,w); i += 2)
		printf(b < w ? ".@" : "@.");
	for (; i < 2*max(b,w); i++)
		putchar(b < w ? '@' : '.');
	putchar('\n');
	
}
