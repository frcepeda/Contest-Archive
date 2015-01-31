#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAXN 100100
#define mp make_pair
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> pt;

int N;
pt p[MAXN];
vector<pii> out;

bool collinear(const pii &a, const pii &b){
	//printf("%d, %d\t%d, %d\t%d\n", a.fst, a.snd, b.fst, b.snd, (long long) a.fst * b.snd - (long long) a.snd * b.fst == 0);
	return a.fst * b.snd - a.snd * b.fst == 0;
}

bool sameDir(const pii &a, const pii &b){
	return a.snd * b.fst == b.snd * a.fst;
}

bool cmp(const pt &a, const pt &b){
	return atan2(a.fst.snd, a.fst.fst) < atan2(b.fst.snd, b.fst.fst);
}

bool cmp2(const pt &a, const pt &b){
	return llabs(a.fst.fst) + llabs(a.fst.snd) < llabs(b.fst.fst) + llabs(b.fst.snd);
}

int main(){
	for (int t = 1; scanf("%d", &N), N; t++){
		int i, j;
		
		out.clear();
		
		for (i = 0; i < N; i++){
			scanf("%lld %lld %d", &p[i].fst.fst, &p[i].fst.snd, &p[i].snd);
			//printf("%d %d %.10lf\n", p[i].fst.fst, p[i].fst.snd, atan2(p[i].fst.snd, p[i].fst.fst));
		}
			
		sort(p, p + N, cmp);
		
		int l = 0;
		for (i = 1; i <= N; i++){
			if (i == N || !sameDir(p[i].fst, p[i-1].fst)){
				sort(p + l, p + i, cmp2);
				int b = -1;
				for (j = l; j < i; j++){
					if (p[j].snd <= b)
						out.push_back(p[j].fst);
					b = max(b, p[j].snd);
				}
				l = i;
			}
		}
		
		printf("Data set %d:\n", t);
		if (out.size() == 0)
			printf("All the lights are visible.\n");
		else {
			printf("Some lights are not visible:\n");
			sort(out.begin(), out.end());
			for (i = 0; i < out.size(); i++)
				printf("x = %lld, y = %lld%c\n", out[i].fst, out[i].snd, i+1 < out.size() ? ';' : '.');
		}
	}
}