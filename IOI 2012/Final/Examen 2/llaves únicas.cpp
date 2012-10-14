#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cassert>

#define MAXN 1000005
#define MAXQ 1000005

using namespace std;

bool paircmp(pair<int, int> a, pair<int, int> b){
	int distA = a.second - a.first;
	int distB = b.second - b.first;
	return distA < distB;
}

int N, Q;

int keys[MAXN];
int nextID;

vector <int> sameKey[MAXN];
vector <int>::iterator vectit;

bool findCollision(int start, int end){
	int i;

	for (i = start; i < end; i++){
		vectit = lower_bound(sameKey[keys[i]].begin(), sameKey[keys[i]].end(), i+1);
		if (vectit != sameKey[keys[i]].end() && *vectit <= end)
			return true;
	}

	return false;
}

void read(){
	auto map <int, int> newIDs;
	auto map <int, int>::iterator mapit;

	for (int i = 0; i < N; i++){
		int newKey, id;
		scanf("%d", &newKey);

		mapit = newIDs.find(newKey);

		if (mapit == newIDs.end()){
			id = nextID++;
			newIDs[newKey] = id;
		} else {
			id = mapit->second;
		}

		keys[i] = id;
		sameKey[id].push_back(i);
	}
}

int main(){
	int i;

	scanf("%d", &N);

	read();

	scanf("%d", &Q);

	for (i = 0; i < Q; i++){
		int first, second;
		scanf("%d %d", &first, &second);
		printf("%d\n", findCollision(first, second));
	}

	return 0;
}
