#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cctype>
#include <set>
#include <map>
#include <vector>

#define fst first
#define snd second
#define mp make_pair

using namespace std;

map<string, map<string, int>> w;
map<string, int> o;
vector<pair<string, int>> ans;

bool cmp(pair<string, int> &a, pair<string, int> &b){
	return a.snd > b.snd || (a.snd == b.snd && a.fst < b.fst);
}

int main(){
	char cc = 0;
	string s;
	string n;

	cin >> noskipws >> s;

	while (cin >> noskipws >> cc){
		cin >> noskipws >> s;
		if (cc == '\n')
			n = s;
		else
			w[n][s]++;
	}

	for (auto &z : w.begin()->snd)
		o[z.fst] = 0;

	for (auto &m : w){
		/*
		cout << "***" << m.first << '\n';
		for (auto &z : m.snd)
			cout << z.fst << " " << z.snd << '\n';
		cout << "***" << "b" << '\n';
		for (auto &z : o)
			cout << z.fst << " " << z.snd << '\n';
		*/

		auto l = m.snd.begin(), le = m.snd.end();
		auto r = o.begin();

		while (r != o.end()){
			while (l != le && l->fst < r->fst) l++;

			if (l != le && l->fst == r->fst){
				r->snd += l->snd;
				l++;
				r++;
			} else {
				r = o.erase(r);
			}
		}
	}

	if (o.size() == 0)
		cout << "ALL CLEAR\n";
	else {
		ans = vector<pair<string,int>>(o.begin(), o.end());
		sort(ans.begin(), ans.end(), cmp);
		for (auto &z : ans)
			cout << z.fst << "\n";
	}
}
