#include <cstdio>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second
#define MAXN 1010

int n, m, best;
typedef pair<int,int> pii;
typedef pair<pii,int> seg;
seg vert[MAXN], hor[MAXN];

int intersection(seg v, seg h){
	if (h.fst.fst > v.fst.fst || h.fst.fst + h.snd < v.fst.fst)
		return 0;
	if (v.fst.snd > h.fst.snd || v.fst.snd + v.snd < h.fst.snd)
		return 0;

	return min(
			min(
				h.fst.snd - v.fst.snd,
				v.fst.snd + v.snd - h.fst.snd
			   ),
			min(
				v.fst.fst - h.fst.fst,
				h.fst.fst + h.snd - v.fst.fst
			   )
		  );
}

int main(){
	int i, j;

	scanf("%d %d", &n, &m);
	
	for (i = 0; i < n; i++)
		scanf("%d %d %d", &vert[i].fst.fst, &vert[i].fst.snd, &vert[i].snd);

	for (i = 0; i < m; i++)
		scanf("%d %d %d", &hor[i].fst.fst, &hor[i].fst.snd, &hor[i].snd);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			best = max(best, intersection(vert[i], hor[j]));

	printf("%d\n", best);
}
