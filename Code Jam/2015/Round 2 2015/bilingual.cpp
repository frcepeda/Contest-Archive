#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int T, N;
map<string,int> m;
vector<int> w[22];
set<int> f, e;

typedef set<int>::iterator it_;
int my_set_intersection(it_ a, it_ as, it_ b, it_ bs){
	int r = 0;

	while (a != as && b != bs){
		if (*a < *b)
			a++;
		else if (*a > *b)
			b++;
		else {
			r++; a++; b++;
		}
	}

	return r;
}

int check(int x){
	e.clear();
	f.clear();

	for (int i = 0; i < N; i++){
		if (x & (1<<i))
			e.insert(w[i].begin(), w[i].end());
		else
			f.insert(w[i].begin(), w[i].end());
	}

	return my_set_intersection(e.begin(), e.end(), f.begin(), f.end());
}

int main(){
	string s, x;
	cin >> T;

	for (int t = 1; t <= T; t++){
		cin >> N;

		getline(cin, s);
		m.clear();

		for (int i = 0; i < N; i++){
			w[i].clear();
			getline(cin, s);
			int l = 0, j;
			for (j = 0; j <= s.length(); j++)
				if (j == s.length() || s[j] == ' '){
					x = s.substr(l, j-l);
					l = j+1;
					if (m.find(x) == m.end())
						m[x] = m.size();
					w[i].push_back(m[x]);
				}
			sort(w[i].begin(), w[i].end());
		}

		int ans = 100000;

		for (int i = 0; i < (1<<(N-2)); i++){
			int j = (i << 2) + 1;
			ans = min(ans, check(j));
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}
}
