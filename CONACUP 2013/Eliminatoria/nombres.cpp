#include <cstdio>
#include <cstring>
#include <algorithm>

#define LEN 100
#define MAXN 500010
#define MAXSTO (MAXN*LEN)

#define fst first
#define snd second

using namespace std;

int N, Q;

struct name {
	char *name, *last;
	int id;
};

struct cmpNameID{
	bool operator()(const name &a, const name &b){
		int c = strcmp(a.name, b.name);
		if (c < 0)
			return true;
		else if (c > 0)
			return false;
		return a.id < b.id;
	}
};

struct cmpLastID{
	bool operator()(const name &a, const name &b){
		int c = strcmp(a.last, b.last);
		if (c < 0)
			return true;
		else if (c > 0)
			return false;
		return a.id < b.id;
	}
};

struct cmpName{
	bool operator()(const name &a, const name &b){
		return strcmp(a.name, b.name) < 0;
	}
};

struct cmpLast{
	bool operator()(const name &a, const name &b){
		return strcmp(a.last, b.last) < 0;
	}
};

char _sto[MAXSTO];
char *sto = _sto;

char *getString(){
	char *ret = sto;
	scanf("%s", sto);
	for (; *sto != '\0'; sto++);
	sto++;
	return ret;
}

name byName[MAXN], byLast[MAXN];

int main(){
	int i;

	scanf("%d %d", &N, &Q);

	for (i = 0; i < N; i++){
		scanf("%d", &byName[i].id);
		byName[i].name = getString();
		byName[i].last = getString();
		byLast[i] = byName[i];
	}

	sort(byName, byName+N, cmpNameID());
	sort(byLast, byLast+N, cmpLastID());

	char _n[LEN], _l[LEN];
	name q;
	q.name = _n;
	q.last = _l;
	while (Q--){
		bool didSomething = false;

		scanf("%s %s", q.name, q.last);

		if (q.last[0] == '*'){
			pair <name*,name*> r = equal_range(byName, byName+N, q, cmpName());

			if (r.fst < r.snd) didSomething = true;

			for (; r.fst < r.snd; r.fst++)
				printf("%d ", r.fst->id);
		} else if (q.name[0] == '*'){
			pair <name*,name*> r = equal_range(byLast, byLast+N, q, cmpLast());

			if (r.fst < r.snd) didSomething = true;

			for (; r.fst < r.snd; r.fst++)
				printf("%d ", r.fst->id);
		} else {
			pair <name*,name*> a = equal_range(byName, byName+N, q, cmpName());
			pair <name*,name*> b = equal_range(byLast, byLast+N, q, cmpLast());

			while (a.fst < a.snd && b.fst < b.snd){
				if (a.fst->id == b.fst->id){
					printf("%d ", a.fst->id);
					didSomething = true;
					a.fst++; b.fst++;
				} else if (a.fst->id < b.fst->id)
					a.fst++;
				else
					b.fst++;
			}
		}

		if (!didSomething)
			printf("-1");

		printf("\n");
	}
}
