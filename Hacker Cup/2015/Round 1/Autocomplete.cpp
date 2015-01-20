#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int T, N;
set<string> dict;

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		int ans = 0;
		
		dict.clear();
		cin >> N;

		for (int i = 0; i < N; i++){
			string s;
			cin >> s;

			int lo = 1, hi = s.size(), mid;

			dict.insert(s);

			while (lo < hi){
				mid = (lo + hi) / 2;
				string t = s.substr(0,mid);
				set<string>::iterator r = dict.lower_bound(t);
				r++;
				if (r == dict.end() || mismatch(t.begin(), t.end(), (*r).begin()).first != t.end())
					hi = mid;
				else
					lo = mid + 1;
			}

			ans += hi;
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
}
