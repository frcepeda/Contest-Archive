#include <iostream>
#include <queue>

using namespace std;

string s;

int main(){
	int T;
	
	cin >> T;

	for (int t = 1; t <= T; t++){
		cin >> s;
		string out;

		for (int i = 0; i < s.length(); i++){
			string l = out + s[i];
			string r = s[i] + out;
			out = max(l, r);
		}

		cout << "Case #" << t << ": " << out << endl;
	}
}
