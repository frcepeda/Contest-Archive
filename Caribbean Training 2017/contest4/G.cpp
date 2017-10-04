#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 55;
int A, B, N;

const int maxa = maxn, maxb = maxn;
vector<int> adj[maxn], adjA[maxa], adjB[maxb];
int pairA[maxa], pairB[maxb];
const int NIL = maxn-1;
bool yesno[maxn];

set<int> ans;

namespace matching {
	const int INF = 1<<29;

	int queue[maxa];
	int qs, qe;

	int dist[maxa];

	bool bfs(){
		qs = qe = 0;
		
		for (int i = 0; i < A; i++){
			if (ans.find(i) == ans.end() && pairA[i] == NIL){
				dist[i] = 0;
				queue[qe++] = i;
			} else dist[i] = INF;
		}

		dist[NIL] = INF;

		while (qs < qe){
			int curr = queue[qs++];
			if (dist[curr] < dist[NIL])
				for (auto i: adjA[curr])
					if (ans.find(i) == ans.end() && dist[pairB[i]] == INF){
						dist[pairB[i]] = dist[curr] + 1;
						queue[qe++] = pairB[i];
					}
		}

		return dist[NIL] < INF;
	}

	bool dfs(int x){
		if (x == NIL) return true;

		for (auto i: adjA[x])
			if (ans.find(i) == ans.end() && dist[pairB[i]] == dist[x] + 1 && dfs(pairB[i])){
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
				if (ans.find(i) == ans.end() && pairA[i] == NIL && dfs(i))
					size++;

		return size;
	}

}

#define mp make_pair
#define fst first
#define snd second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string tmp;
	getline(cin, tmp);
	istringstream ss(tmp);
	ss >> N;

	for (int i = 0; i < N; i++){
		getline(cin, tmp);
		istringstream ss(tmp);

		string vv;
		ss >> vv;

		yesno[i] = vv == "Y";

		int x;
		while (ss >> x){
			adj[i].push_back(x-1);
			adj[x-1].push_back(i);
		}
	}

	A = B = N;
	for (int i = 0; i < N; i++){
		adj[i].erase(
			remove_if(
				adj[i].begin(),
				adj[i].end(),
				[=](const int &x){ return yesno[i] == yesno[x]; }
			),
			adj[i].end()
		);

		if (yesno[i])
			adjB[i] = adj[i];
		else
			adjA[i] = adj[i];
	}

	for (int I = 0; I < N; I++){
		int M = matching::matching();

		ans.insert(I);

		if (matching::matching() != M-1)
			ans.erase(I);
	}

	cout << ans.size() << endl;
	for (auto w: ans)
		cout << w+1 << endl;
}
