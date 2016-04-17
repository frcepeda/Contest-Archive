#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back

vector<vector<int>> x[10];

int main(){
	x[1].pb(vector<int>());
	x[1].begin()->pb(1);

	for (int z = 2; z <= 8; z++){
		bool l = true;

		for (auto &w : x[z-1]){
			if (l) {
				auto t = vector<int>(w);
				t.pb(z);
				x[z].pb(t);

				for (int i = t.size()-2; i >= 0; i--){
					swap(t[i], t[i+1]);
					x[z].pb(t);
				}
			} else {
				auto t = vector<int>();
				t.pb(z);
				for (auto &y: w)
					t.pb(y);
				x[z].pb(t);

				for (int i = 1; i < t.size(); i++){
					swap(t[i], t[i-1]);
					x[z].pb(t);
				}
			}

			l = !l;
		}
	}

	int n;
	scanf("%d", &n);

	for (auto &w : x[n])
		for (int i = 0; i < w.size(); i++)
			printf("%d%c", w[i], i < w.size()-1 ? ' ' : '\n');
}
