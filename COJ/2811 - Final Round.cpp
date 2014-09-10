// Accepted
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

int T;
map<string, vector<pair<int, string> > > winners;
vector<pair<string,string> > out;

int main(){
	int t;
	string str;

	getline(cin, str);
	sscanf(str.c_str(), "%d", &T);

	for (t = 1; t <= T; t++){
		string last = "";

		winners.clear();
		out.clear();

		while (getline(cin, str), true){
			if (str == "" || str == last) break;
			last = str;

			int i, j, score;
			string name, carreer;

			for (i = str.length()-1; i >= 0; i--)
				if (str[i] != ' ')
					break;

			str = str.substr(0, i+1);

			for (i = str.length()-1; i >= 0; i--)
				if (str[i] == ' ')
					break;

			sscanf(str.substr(i+1).c_str(), "%d", &score);

			for (j = i-1; j >= 0; j--)
				if (str[j] == ' ')
					break;

			carreer = str.substr(j+1, i-j-1);
			name = str.substr(0, j);

			/*
			cout << str << endl;
			cout << name << '*' << endl;
			cout << carreer << '*' << endl;
			cout << score << '*' << endl;
			*/

			if (winners.find(carreer) == winners.end()){
				vector<pair<int,string> > v;
				winners[carreer] = v;
			}

			winners[carreer].push_back(mp(score, name));
		}

		for (map<string, vector<pair<int, string> > >::iterator it = winners.begin(); it != winners.end(); it++){
			sort(it->snd.begin(), it->snd.end());
			for (vector<pair<int, string> >::reverse_iterator w = it->snd.rbegin(); w != it->snd.rend(); w++)
				if (w == it->snd.rbegin() || (w-1)->fst == w->fst){
					out.push_back(mp(w->snd, it->fst));
				} else break;
		}

		sort(out.begin(), out.end());

		cout << "List " << t << endl;

		for (vector<pair<string, string> >::iterator it = out.begin(); it != out.end(); it++)
			cout << it->fst << " " << it->snd << endl;
	}
}
