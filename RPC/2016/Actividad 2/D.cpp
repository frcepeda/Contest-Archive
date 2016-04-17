#include <iostream>
#include <cstring>
#include <string>
#include <bitset>

using namespace std;

#define MAXF 1010

int T, F;
string me, food[MAXF];

bitset<MAXF> f(string s){
	bitset<MAXF> r;
	r.flip();

	for (int i = 0; i < F; i++)
		for (int j = 0; j < s.length(); j++)
			r[i] = r[i] && (strchr(food[i].c_str(), s[j]) != NULL);

	return r;
}

int main(){
	cin >> T;

	while (T--){
		bitset<256> used;

		cin >> me >> F;

		for (int i = 0; i < F; i++){
			cin >> food[i];
			for (int j = 0; j < food[i].length(); j++)
				used[food[i][j]] = true;
		}

		bitset<MAXF> target = f(me);
		char c;
		for (c = 'A'; c <= 'Z'; c++)
			if (used[c] && target == f(string(1,c)))
				break;

		if (c <= 'Z')
			cout << c << endl;
		else
			cout << "No Solution" << endl;
	}
}
