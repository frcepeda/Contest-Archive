#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define MAXN 100010

map<int,int> thingy;
int lastThingy;

set<int> open;

struct plank {
	int start, end, height;
};

bool operator < (const plank &a, const plank &b){
	// sort in reverse!
	if (a.height != b.height)
		return a.height > b.height;
	if ((a.end - a.start) != (b.end - b.start))
		return (a.end - a.start) > (b.end - b.start);
	else return a.start > b.start;
}

int N, answer;
plank planks[MAXN];
int points[MAXN*3], pCount, maxP;

bool tree[MAXN*6];
bool willUse[MAXN];

#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

bool occupied(int node, int start, int end, int a, int b){
	if (a <= start && end <= b)
		return tree[node];
	else if (!(start <= b && a <= end) || tree[node])
		return true;
	else
		return occupied(childA(node), start, (start+end)/2, a, b) &&
		       occupied(childB(node), (start+end)/2+1, end, a, b);
}

void update(int node, int start, int end, int a, int b){
	if (a <= start && end <= b) {
		tree[node] = true;
		return;
	} else if (!(start <= b && a <= end) || tree[node]){
		return;
	} else {
		update(childA(node), start, (start+end)/2, a, b);
		update(childB(node), (start+end)/2+1, end, a, b);
	}
}

struct triple {
	int first, third;
	bool second;
};

bool operator < (const triple &a, const triple &b){
	return a.first < b.first;
}

triple events[MAXN*2];
int eCount;

int main(void){
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d %d %d", &planks[i].start, &planks[i].end, &planks[i].height);
		planks[i].end += planks[i].start - 1;
		points[pCount++] = planks[i].start;
		points[pCount++] = planks[i].end;
		points[pCount++] = planks[i].end + 1;
	}

	sort(points, points + pCount);

	for (i = 0; i < pCount; i++){
		if (thingy.find(points[i]) == thingy.end()){
			maxP = lastThingy;
			thingy[points[i]] = lastThingy++;
		}
	}

	for (i = 0; i < N; i++){
		planks[i].start = thingy[planks[i].start];
		planks[i].end = thingy[planks[i].end];
	}

	sort(planks, planks + N);

	for (i = 0; i < N;){
		bool firsttime = true;
		eCount = 0;

		while (i < N && (firsttime || planks[i].height == planks[i-1].height)){
			if (firsttime || !(planks[i-1].start <= planks[i].start && planks[i].end <= planks[i-1].end)){
				events[eCount].second = true;
				events[eCount].third = i;
				events[eCount++].first = planks[i].start;

				events[eCount].second = false;
				events[eCount].third = i;
				events[eCount++].first = planks[i].end + 1;
			}

			firsttime = false;
			i++;
		}

		sort(events, events + eCount);

		for (int e = 0; e < eCount;){
			bool firsttime = true;

			while (e < eCount && (firsttime || events[e].first == events[e-1].first)){
				if (events[e].second)
					open.insert(events[e].third);
				else
					open.erase(events[e].third);

				firsttime = false;
				e++;
			}

			if (open.size() == 1)
				willUse[*open.begin()] = true;
		}
	}

	for (i = 0; i < N; i++){
		if (willUse[i] && !occupied(0, 0, maxP, planks[i].start, planks[i].end)){
			update(0, 0, maxP, planks[i].start, planks[i].end);
			answer++;
		}
	}

	printf("%d\n", answer);

	return 0;
}
