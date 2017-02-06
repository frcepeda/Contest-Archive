#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>

using namespace std;

int n, m;
set<string> l, r;
vector<string> v;

int main(){
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		l.insert(tmp);
	}

	for (int i = 0; i < m; i++){
		string tmp;
		cin >> tmp;
		r.insert(tmp);
	}

	set_intersection(l.begin(), l.end(),
		r.begin(), r.end(),
		back_inserter(v));

	int L = l.size();
	int R = r.size();
	int M = v.size();

	L += M % 2;

	bool win = L > R;

	cout << (win ? "YES" : "NO") << endl;
}
