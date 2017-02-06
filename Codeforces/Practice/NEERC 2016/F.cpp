#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

const int L = 32, U = 126;
bool u[256];
vector<pair<int,int>> notAlnumBlocks = {{33,47}, {58,64}, {91,96}, {123,126}};

#define fst first
#define snd second

string go(){
	for (const auto &w: notAlnumBlocks){
		if (!(u[w.snd+1] && u[w.snd+2] && u[w.snd+3]) &&
		    !(u[w.snd+1] && u[w.snd+2] && u[w.fst-1]) &&
		    !(u[w.snd+1] && u[w.fst-1] && u[w.fst-2])
		)
			for (int i = w.fst; i <= w.snd; i++)
				u[i] = false;
	}

	ostringstream ss;

	int p = L;
	for (int i = L; i <= U; i++){
		if (!u[i]) p = i+1;
		else if (!u[i+1]) {
			if (i - p + 1 <= 2){
				for (int k = p; k <= i; k++)
					ss << char(k);
			} else {
				ss << char(p) << '-' << char(i);
			}
		}
	}

	return ss.str();
}

int main(){
	string s;

	getline(cin, s);

	for (int i = L; i <= U; i++)
		u[i] = !isalnum(i);
	u[' '] = false;
	for (auto c: s)
		u[c] = true;

	string a = go();
	cerr << a << endl;

	for (int i = L; i <= U; i++)
		u[i] = true;
	for (auto c: s)
		u[c] = false;

	string b = "^" + go();
	if (b == "^") b = "^!";
	cerr << b << endl;

	string ans;

	if (a.size() < b.size() || (a.size() == b.size() && a < b))
		ans = a;
	else
		ans = b;

	cout << "\%[" << ans << "]\n";
}
