#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

#define mp make_pair

int T;
string s;

int solve(string s){
	queue<pair<string,int>> q;
	set<string> v;

	q.push(mp(s,0));
	v.insert(s);

	while (true){
		int d;
		tie(s,d) = q.front(); q.pop();

		if (all_of(s.begin(),
		           s.end(),
		           [](char c){ return c == '+'; }))
			return d;

		for (int i = 1; i <= s.length(); i++){
			string t = s;
			reverse(t.begin(), t.begin() + i);
			for (int j = 0; j < i; j++)
				t[j] = t[j] == '+' ? '-' : '+';
			if (v.find(t) != v.end()) continue;
			v.insert(t);
			q.push(mp(t, d+1));
		}
	}
}

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		cin >> s;
		printf("Case #%d: %d\n", t, solve(s));
	}
}
