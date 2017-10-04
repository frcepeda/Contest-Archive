#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 550;
int A, B;

const int maxa = maxn, maxb = maxn;
vector<int> adjA[maxa], adjB[maxb];
int pairA[maxa], pairB[maxb];
const int NIL = maxn-1;

namespace matching {
	const int INF = 1<<29;

	int queue[maxa];
	int qs, qe;

	int dist[maxa];

	bool bfs(){
		qs = qe = 0;
		
		for (int i = 0; i < A; i++){
			if (pairA[i] == NIL){
				dist[i] = 0;
				queue[qe++] = i;
			} else dist[i] = INF;
		}

		dist[NIL] = INF;

		while (qs < qe){
			int curr = queue[qs++];
			if (dist[curr] < dist[NIL])
				for (auto i: adjA[curr])
					if (dist[pairB[i]] == INF){
						dist[pairB[i]] = dist[curr] + 1;
						queue[qe++] = pairB[i];
					}
		}

		return dist[NIL] < INF;
	}

	bool dfs(int x){
		if (x == NIL) return true;

		for (auto i: adjA[x])
			if (dist[pairB[i]] == dist[x] + 1 && dfs(pairB[i])){
				pairB[i] = x;
				pairA[x] = i;
				return true;
			}

		dist[x] = INF;
		return false;
	}

	int matching(){
		int size = 0;

		fill(pairA, pairA + maxa, NIL);
		fill(pairB, pairB + maxb, NIL);
		while (bfs())
			for (int i = 0; i < A; i++)
				if (pairA[i] == NIL && dfs(i))
					size++;

		return size;
	}

}

#define mp make_pair
#define fst first
#define snd second

int I, V, v[maxn];

bool augmentingPath(int b){
	if (v[b] == V) return false;
	v[b] = V;

	for (auto j: adjB[b]){
		if (j == I) continue;
		if (pairA[j] == NIL) return true;
		if (augmentingPath(pairA[j])) return true;
	}

	return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string tmp;
	getline(cin, tmp);
	istringstream ss(tmp);
	ss >> A >> B;

	for (int i = 0; i < A; i++){
		int x;
		getline(cin, tmp);
		istringstream ss(tmp);
		while (ss >> x){
			adjA[i].push_back(x-1);
			adjB[x-1].push_back(i);
		}
	}

	//fprintf(stderr, "max matching: %d\n", matching::matching());
	matching::matching();

	bool first = true;
	for (I = 0; I < A; I++){
		V++;
		if (pairA[I] == NIL) continue;

		int old = pairA[I];
		pairA[I] = NIL;
		pairB[old] = NIL;

		if (!augmentingPath(old)){
			cout << (first ? "" : " ") << I+1;
			first = false;
		}

		pairA[I] = old;
		pairB[old] = I;
	}

	cout << '\n';
}
