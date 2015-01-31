#include <cstdio>
#include <algorithm>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

typedef pair<int,int> pii;
int T;
pii a, b, c, d, e, f;

int main() {
	bool first = true;
	scanf("%d", &T);
	
	while (T--){
		if (!first) putchar('\n');
		first = false;
		
		scanf("%d %d %d %d", &a.fst, &a.snd, &b.fst, &b.snd);
		scanf("%d %d %d %d", &c.fst, &c.snd, &d.fst, &d.snd);
		
		e = mp(max(a.fst, c.fst), max(a.snd, c.snd));
		f = mp(min(b.fst, d.fst), min(b.snd, d.snd));
		
		if (e.fst >= f.fst || e.snd >= f.snd)
			printf("No Overlap\n");
		else
			printf("%d %d %d %d\n", e.fst, e.snd, f.fst, f.snd);
	}
}