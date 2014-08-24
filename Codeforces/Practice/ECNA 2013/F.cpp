#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define MAXN 220
#define mp make_pair
#define fst first
#define snd second

map<string,int> employees;
map<int,string> print;
vector<pair<string,string> > out;
int order[MAXN], osize;
bool conn[MAXN][MAXN];
bool edge[MAXN][MAXN];
bool vis[MAXN];

int n, m;

void toposort(int i){
	if (vis[i]) return;
	vis[i] = true;
	for (int k = 1; k <= n; k++)
		if (edge[i][k])
			toposort(k);
	order[osize++] = i;
}

int main(){
	int t = 0;
	while ((cin >> m), t++, m){
		int i, j, k;

		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXN; j++)
				edge[i][j] = conn[i][j] = false;

		n = 0;
		osize = 0;
		employees.clear();
		print.clear();
		out.clear();
		fill(vis, vis + MAXN, false);

		while (m--){
			string a, b;
			cin >> a >> b;

			if (employees[a] == 0){
				employees[a] = n + 1;
				print[n+1] = a;
				n++;
			}

			if (employees[b] == 0){
				employees[b] = n + 1;
				print[n+1] = b;
				n++;
			}

			edge[employees[a]][employees[b]] = true;
		}

		n = employees.size();

		for (i = 1; i <= n; i++)
			toposort(i);

		for (i = 0; i < n; i++){
			//cout << print[order[i]] << "\n";

			for (j = 0; j < i; j++)
				conn[order[i]][order[j]] = edge[order[i]][order[j]];

			for (j = i-1; j >= 0; j--)
				for (k = j+1; k < i; k++)
					if (conn[order[i]][order[k]] && conn[order[k]][order[j]]){
						conn[order[i]][order[j]] = true;
						if (edge[order[i]][order[j]])
							out.push_back(mp(print[order[i]], print[order[j]]));
						break;
					}
		}

		sort(out.begin(), out.end());
		cout << "Case " << t << ": " << out.size();
		for (i = 0; i < out.size(); i++)
			cout << ' ' << out[i].fst << ',' << out[i].snd;
		cout << '\n';
	}
}
