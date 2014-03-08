// 120/120 points
#include <algorithm>
#include <cstdio>

#define MAXN 300100

using namespace std;

#define fst first
#define snd second
#define mp make_pair

typedef pair<int,int> pii;
typedef pair<int,bool> pib;

int N, ans;
pii circle[MAXN];
#define circ(e) (e.snd ? circle[e.fst].fst : circle[e.fst].snd)
#define comp(e) (e.snd ? circle[e.fst].snd : circle[e.fst].fst)

bool split[MAXN];

pib e[MAXN*2];
pii stack[MAXN];
int sti;
#define push(a) stack[sti++] = (a)
#define pop() (stack[--sti])
#define peek() stack[sti-1]
#define stackIsEmpty (!sti)

struct cmp {
	bool operator () (const pib &a, const pib &b) const {
		if (circ(a) != circ(b))
			return circ(a) < circ(b);
		if (a.snd != b.snd)
			return b.snd;
		return comp(b) < comp(a);
	}
};

int main(){
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		int x, r;
		scanf("%d %d", &x, &r);
		circle[i].fst = x-r;
		circle[i].snd = x+r;
		e[i].fst = i;
		e[i].snd = true;
		e[i+N].fst = i;
		e[i+N].snd = false;
		split[i] = true;
	}

	N *= 2;

	sort(e, e+N, cmp());

	for (i = 0; i < N; i++){
		if (!stackIsEmpty && i && peek().snd != circ(e[i]))
			split[peek().fst] = false;

		if (e[i].snd){
			push(mp(e[i].fst, circ(e[i])));
		} else {
			ans += split[e[i].fst] ? 2 : 1;
			pop();
			peek().snd = circ(e[i]);
		}
	}

	printf("%d\n", ans + 1);
}
