#include <iostream>
#include <algorithm>

using namespace std;

int T, d;
string str, tmp, ans;

string decrypt(string &s, int d){
	string x = s;
	for (int i = 0; i < x.length(); i++)
		if (x[i] != ' ')
			x[i] = (x[i] - 'A' + d) % 26 + 'A';
	return x;
}

bool works(string &s){
	int c[26] = {0};
	for (int i = 0; i < s.length(); i++)
		if (s[i] != ' ')
			c[s[i] - 'A']++;
	for (int i = 0; i < 26; i++)
		if (c[i] > c['E' - 'A'])
			return false;
	return true;
}

int main(){
	cin >> T;
	getline(cin, str);

	while (T--){
		bool found = false;
		getline(cin, str);

		for (int i = 0; i <= 25; i++){
			tmp = decrypt(str, i);
			if (works(tmp)){
				if (!found){
					found = true;
					ans = tmp;
					d = (26 - i) % 26;
				} else {
					d = -1;
					break;
				}
			}
		}

		if (d < 0)
			cout << "NOT POSSIBLE\n";
		else
			cout << d << ' ' << ans << endl;
	}
}
