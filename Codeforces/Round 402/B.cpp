#include <iostream>
#include <string>
#include <map>

using namespace std;

struct expr {
	string name;
	bool constant;
	string op, left, right;
};

const int maxn = 5010;
expr e[maxn];
int n, m;

inline bool isnum(string &x){
	return x[0] == '0' || x[0] == '1';
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		string tmp;
		cin >> e[i].name;
		cin >> tmp;
		cin >> tmp;

		if (isnum(tmp)){
			e[i].constant = true;
			e[i].op = tmp;
		} else {
			e[i].left = tmp;
			cin >> e[i].op >> e[i].right;
		}
	}

	string lo, hi;
	map<string, bool> v[2];

	for (int j = 0; j < m; j++){
		int s[2] = {0};

		for (int i = 0; i < n; i++){
			for (int x = 0; x <= 1; x++){
				if (e[i].constant){
					v[x][e[i].name] = e[i].op[j] == '1';
				} else {
					bool l, r, y;

					if (e[i].left == "?")
						l = x;
					else
						l = v[x][e[i].left];

					if (e[i].right == "?")
						r = x;
					else
						r = v[x][e[i].right];

					if (e[i].op == "AND")
						y = l && r;
					else if (e[i].op == "XOR")
						y = l ^ r;
					else
						y = l || r;

					v[x][e[i].name] = y;
					s[x] += y;
				}
			}
		}

		hi += s[1] > s[0] ? '1' : '0';
		lo += s[1] < s[0] ? '1' : '0';
	}

	cout << lo << endl << hi << endl;
}
