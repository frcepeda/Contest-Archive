// Accepted
// Two words are anagrams iff they are the same when sorted (removing spaces).

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int T;
string str;
vector<pair<string,string>> v, o;

string strip(string x){
	sort(x.begin(), x.end());
	for (int i = 0; i < x.length(); i++)
		if (x[i] != ' ')
			return x.substr(i);
}

int main(){
	cin >> T;
	getline(cin, str);
	getline(cin, str);

	bool first = true;

	while (T--){
		if (!first) cout << endl;
		else first = false;

		v.clear();
		o.clear();

		while (getline(cin, str), (str != "" && !cin.fail()))
			v.push_back(make_pair(strip(str), str));

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++)
			for (int j = i+1; j < v.size() && v[i].first == v[j].first; j++)
				o.push_back(make_pair(v[i].second, v[j].second));

		sort(o.begin(), o.end());

		for (int i = 0; i < o.size(); i++)
			cout << o[i].first << " = " << o[i].second << endl;
	}
}
