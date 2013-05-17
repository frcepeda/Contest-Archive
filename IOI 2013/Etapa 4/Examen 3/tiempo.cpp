#include <stdio.h>
#include <stdlib.h>
#include <queue>

#define MAXN 110

using namespace std;

typedef pair< int,pair<int,int> > piii;

pair<int, int> points[MAXN];
long long int best;
long long int N, d;
int extra[MAXN];
int counter = 70000000;

int abs(int a){
	return a < 0 ? -a : a;
}

void search(int node, int remaining, long long int spent, int visited){
	int i;

counter--;
if (!counter){
printf("%d\n", best);
exit(0);
}

	if (spent > best)
		return;

	if (node == N-1){
		best = min(best, spent);
		return;
	}

	remaining += extra[node];

	for (i = N-1; i >= 0; i--){
		if (!((1<<i) & visited)){
			int willSpend = d * (abs(points[node].first - points[i].first) + abs(points[node].second - points[i].second));
			if (willSpend <= remaining)
				search(i, remaining - willSpend, spent, visited | (1<<i));
			else
				search(i, 0, spent + willSpend - remaining, visited | (1<<i));
		}
	}
}

int main(){
	int i;

	scanf("%d %d", &N, &d);

	for (i = 1; i < N-1; i++)
		scanf("%d", &extra[i]);

	for (i = 0; i < N; i++)
		scanf("%d %d", &points[i].first, &points[i].second);

	best = d * (abs(points[0].first - points[N-1].first) + abs(points[0].second - points[N-1].second)); 
	search(0,0,0,1);
	printf("%lld\n", best);

	return 0;
}
