#include <iostream>
#include <map>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

map<string,int> dict;
int n, q;
string s, m;
pair<int, string> b;

void check(const string &x){
	auto it = dict.find(x);
	//cout << x << endl;
	if (it != dict.end())
		b = min(b, mp(it->snd, it->fst));
}

void match(){
	int i;
	char c;
	
	b = mp(n+1, "");
	
	for (int i = 0; i <= s.length(); i++){
		auto l = s.substr(0, i), r = s.substr(i, 30);
		if (i < s.length())
			check(l + r.substr(1));
		for (c = 'a'; c <= 'z'; c++)
			check(l + c + r);
	}
	
	for (int i = 0; i < s.length(); i++){
		char t = s[i];
		for (c = 'a'; c <= 'z'; c++){
			s[i] = c;
			check(s);
		}
		s[i] = t;
	}
	
	for (int i = 1; i < s.length(); i++){
		swap(s[i], s[i-1]);
		check(s);
		swap(s[i], s[i-1]);
	}
}

int main() {
	int i;
	
	cin >> n;
	
	for (i = 0; i < n; i++){
		cin >> s;
		dict[s] = i;
	}
	
	cin >> q;
	
	while (q--){
		cin >> s;
		
		if (dict.find(s) != dict.end())
			cout << s << " is correct\n";
		else if (match(), b.fst < n)
			cout << s << " is a misspelling of " << b.snd << "\n";
		else
			cout << s << " is unknown\n";
	}
}