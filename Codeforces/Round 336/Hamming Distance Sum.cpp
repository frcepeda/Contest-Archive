#include <iostream>
#include <algorithm>

using namespace std;

string s, t;
int acc[200100];

int main(){
	long long ans = 0;

	cin >> s >> t;

	for (int i = 0; i < t.size(); i++)
		acc[i+1] = t[i] + acc[i] - '0';

	for (int i = 0; i < s.size(); i++){
		int w = acc[t.size() - s.size() + i + 1] - acc[i];
		ans += s[i] == '0' ? w : t.size() - s.size() + 1 - w;
	}

	cout << ans << '\n';
}
