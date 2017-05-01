#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
int T, K;

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";

		cin >> s >> K;

		int ans = 0;

		for (int i = 0; i+K <= s.size(); i++)
			if (s[i] == '-'){
				ans++;
				for (int j = 0; j < K; j++)
					s[i+j] = s[i+j] == '+' ? '-' : '+';
			}

		if (all_of(s.begin(), s.end(), [](char c){ return c == '+'; }))
			cout << ans << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}
}
