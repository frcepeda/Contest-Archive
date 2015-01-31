// Accepted

/*
Sort the bags. Then, bag i' < i will fit in bag i if a[i'] is different from a[i].
Process the bags in order. At any point, if a bag can be nested, do so, taking
care that no bag goes into a bag of the same size. This minimizes the total amount
of nested bags. Now, to minimize the amount of nested bags in a single bag, if
there is a tie when nesting a bag, choose the sequence with the least amount of
bags. This is accomplished with a priority queue and a temporary storage to
put aside the bags with the same size.
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 10100
#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> pii;

int n;
int a[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> q;
queue<pii> t;
int p[MAXN];

void print(int x){
	if (x == 0) return;
	printf("%d%c", a[x], p[x] ? ' ' : '\n');
	print(p[x]);
}

int main() {
	bool first = true;
	
	while (scanf("%d", &n), n){
		int i, j;
		
		if (!first) putchar('\n');
		else first = false;
		
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		
		sort(a+1, a+1 + n);
		
		for (i = 1; i <= n; i++){
			if (a[i] != a[i-1])
				while (!t.empty())
					q.push(t.front()), t.pop();
			
			if (!q.empty()){
				auto x = q.top(); q.pop();
				p[i] = x.snd;
				t.push(mp(x.fst + 1, i));
			} else {
				p[i] = 0;
				t.push(mp(1, i));
			}
		}
		
		while (!t.empty())
			q.push(t.front()), t.pop();
		
		printf("%d\n", q.size());
		
		while (!q.empty()){
			print(q.top().snd);
			q.pop();
		}
	}
}