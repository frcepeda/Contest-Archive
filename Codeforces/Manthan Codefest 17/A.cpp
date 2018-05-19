#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n;
set<string> p;

int main(){
	cin >> n;

	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		cout << (p.find(s) == p.end() ? "NO" : "YES") << "\n";
		p.insert(s);
	}
}
