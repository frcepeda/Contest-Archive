#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int go(const string &t){
	int curr = 1, best = 1;

	for (int i = 0; i+1 < t.size(); i++){
		if (t[i] != t[i+1]){
			curr++;
		} else {
			best = max(curr, best);
			curr = 1;
		}
	}

	return max(curr, best);
}

int main(){
	cin >> s;

	int two = min((int)s.size(), go(s + s));

	reverse(s.begin(), s.end());

	int one = min((int)s.size(), go(s + s));

	cout << max(one, two) << endl;
}
