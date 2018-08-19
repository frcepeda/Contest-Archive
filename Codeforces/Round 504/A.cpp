#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	string t, s;
	
	cin >> n >> m;
	cin >> s >> t;

	bool ans = false;

	if (s.find('*') == string::npos){
		ans = s == t;
	} else if (s.size() - 1 <= t.size()) {
		int L, R;

		ans = true;

		for (L = 0; s[L] != '*'; L++)
			if (s[L] != t[L]){
				ans = false;
				break;
			}

		for (R = 0; s[s.size() - R - 1] != '*'; R++)
			if (s[s.size() - R - 1] != t[t.size() - R - 1]){
				ans = false;
				break;
			}
	}

	cout << (ans ? "YES" : "NO") << endl;
}
