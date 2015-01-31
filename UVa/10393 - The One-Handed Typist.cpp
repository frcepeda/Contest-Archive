#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
string s;
set<string> out;
int F, N;

#define K ('z' - 'a' + 1)
long long keys[] = {
	(1ll<<('q' - 'a')) | (1ll<<('a' - 'a')) | (1ll<<('z' - 'a')),
	(1ll<<('w' - 'a')) | (1ll<<('s' - 'a')) | (1ll<<('x' - 'a')),
	(1ll<<('e' - 'a')) | (1ll<<('d' - 'a')) | (1ll<<('c' - 'a')),
	(1ll<<('r' - 'a')) | (1ll<<('f' - 'a')) | (1ll<<('v' - 'a')) | (1ll<<('t' - 'a')) | (1ll<<('g' - 'a')) | (1ll<<('b' - 'a')),
	0,
	0,
	(1ll<<('y' - 'a')) | (1ll<<('h' - 'a')) | (1ll<<('n' - 'a')) | (1ll<<('u' - 'a')) | (1ll<<('j' - 'a')) | (1ll<<('m' - 'a')),
	(1ll<<('i' - 'a')) | (1ll<<('k' - 'a')),
	(1ll<<('o' - 'a')) | (1ll<<('l' - 'a')),
	(1ll<<('p' - 'a'))
};

int main() {
	while (cin >> F >> N){
		int best = 0;
		out.clear();
		long long pos = (1LL<<K) - 1;
		
		while (F--){
			int x;
			cin >> x;
			pos &= ~keys[x-1];
		}
		
		while (N--){
			cin >> s;
			if (s.length() >= best &&
			    all_of(s.begin(), s.end(), [pos](char c){ return pos & (1LL<<(c - 'a')); })){
			    if (s.length() > best){
			    	out.clear();
			    	best = s.length();
			    }
				out.insert(s);
			}
		}
		
		cout << out.size() << endl;
		for_each(out.begin(), out.end(), [](const string &s){ cout << s << endl; });
	}
}