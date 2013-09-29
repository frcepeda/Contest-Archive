// 100 points
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

#define mp make_pair
#define lb lower_bound
typedef pair<double,double> pdd;

bool sortBySecond(const pdd &a, const pdd &b){
	return a.second < b.second;
}

#define MAXN 50010

set<pdd, typeof(&sortBySecond)> curr(&sortBySecond);
pdd points[MAXN];
int n;

double dist(pdd a, pdd b){
#define sq(a) ((a)*(a))
	return sqrt(sq(a.first-b.first) + sq(a.second-b.second));
}

int main(){
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%lf %lf", &points[i].first, &points[i].second);

	sort(points, points+n);

	int last = 0;
	double m = dist(points[0], points[1]);
	for (i = 0; i < n; i++){
		while (last < i && points[i].first - points[last].first > m)
			curr.erase(points[last++]);

		set<pdd>::iterator it = curr.lb(mp(0,points[i].second-m));
		while (it != curr.end() && it->second - points[i].second <= m){
			m = min(m, dist(*it, points[i]));
			it++;
		}

		curr.insert(points[i]);
	}

	printf("%.3lf\n", m);
}
