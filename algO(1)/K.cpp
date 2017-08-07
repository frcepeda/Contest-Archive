#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 1000100;

int T, N;
string s;

int v[maxn];
set<int> a;
vector<int> now, then;

int main(){
	cin >> T;

	while (T--){
		cin >> s;
		N = s.size();

		a.clear();
		fill(v, v+N, 2*N);

		for (int i = 0; i < N; i++)
			a.insert(i);

		then.clear();

		for (int i = 0; i+1 < N; i++){
			if (s[i] != s[i+1]){
				if (v[i] != 1){
					then.push_back(i);
					v[i] = 1;
				}

				if (v[i+1] != 1){
					then.push_back(i+1);
					v[i+1] = 1;
				}
			}
		}

		int turn = 1;
		while (!then.empty()){
			turn++;

			now = move(then);
			then.clear();

			for (auto x: now){
				auto it = a.find(x);

				if (it == a.end()) continue;

				if (it != a.begin() && next(it) != a.end()){
					int p = *prev(it);
					int q = *next(it);

					if (v[p] >= turn && v[q] >= turn && s[p] != s[q]){
						v[p] = v[q] = turn;
						then.push_back(p);
						then.push_back(q);
					}
				}

				a.erase(it);
			}
		}

		cout << turn-1 << endl;
		cerr << "Remaining: " << T << endl;
	}
}
