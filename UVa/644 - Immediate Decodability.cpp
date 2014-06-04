#include <iostream>
#include <algorithm>

using namespace std;

int N;
string s[9];

int main(){
	for (int S = 1; cin >> s[N++]; S++){
		while (cin >> s[N++], s[N-1] != "9");

		sort(s, s + N);

		bool immediate = true;
		for (int i = 0; immediate && i < N-2; i++)
			if (mismatch(s[i].begin(), s[i].end(), s[i+1].begin()).first == s[i].end())
				immediate = false;

		cout << "Set " << S << " is " << (immediate ? "" : "not ") << "immediately decodable\n";
		N = 0;
	}
}
