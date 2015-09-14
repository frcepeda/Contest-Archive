#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define MAXR 105
#define MAXC 105

bool known[MAXR][MAXC];
int col[MAXC], row[MAXR];
string var[MAXR][MAXC];
map<string, int> varVal;

int R, C;

int findRow(){
	int i, j;

	for (i = 0; i < R; i++){
		string tmp = "";

		for (j = 0; j < C; j++){
			if (known[i][j]) continue;
			else if (tmp == "") tmp = var[i][j];
			else if (var[i][j] != tmp) break;
		}

		if (j == C && tmp != "") return i;
	}

	return -1;
}

int findCol(){
	int i, j;

	for (j = 0; j < C; j++){
		string tmp = "";

		for (i = 0; i < R; i++){
			if (known[i][j]) continue;
			else if (tmp == "") tmp = var[i][j];
			else if (var[i][j] != tmp) break;
		}

		if (i == R && tmp != "") return j;
	}

	return -1;
}

int main(){
	while (cin >> R >> C){
		int i, j;

		varVal.clear();

		for (i = 0; i < R; i++){
			for (j = 0; j < C; j++){
				cin >> var[i][j];
				known[i][j] = false;
			}
			cin >> row[i];
		}

		for (i = 0; i < C; i++)
			cin >> col[i];

		while (true){
			int x, c = 0, acc = 0, val;
			string VAR = "";

			if ((x = findRow()) != -1){
				for (j = 0; j < C; j++){
					if (known[x][j])
						acc += varVal[var[x][j]];
					else {
						c++;
						if (VAR == "") VAR = var[x][j];
					}
				}
				val = (row[x] - acc) / c;
			} else if ((x = findCol()) != -1){
				for (i = 0; i < R; i++){
					if (known[i][x])
						acc += varVal[var[i][x]];
					else {
						c++;
						if (VAR == "") VAR = var[i][x];
					}
				}
				val = (col[x] - acc) / c;
			} else break;

			varVal[VAR] = val;

			for (i = 0; i < R; i++)
				for (j = 0; j < C; j++)
					if (var[i][j] == VAR)
						known[i][j] = true;
		}

		for (auto x = varVal.begin(); x != varVal.end(); x++)
			cout << x->first << " " << x->second << "\n";
	}
}
