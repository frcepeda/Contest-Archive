// Accepted
#include <iostream>

using namespace std;

#define fst first
#define snd second

int T;
string map[10];

typedef pair<int,int> pii;
pii movs[4] = {pii(1,1), pii(1,-1), pii(-1,1), pii(-1,-1)};

#define valid(x) ((x) >= 0 && (x) < 10)

int dfs(int r, int c){
	int ret = 0;

	for (int i = 0; i < 4; i++){
		int r1 = r + movs[i].fst;
		int c1 = c + movs[i].snd;
		int r2 = r1 + movs[i].fst;
		int c2 = c1 + movs[i].snd;

		if (valid(r1) && valid(r2) && valid(c1) && valid(c2) && map[r1][c1] == 'B' && map[r2][c2] == '#'){
			map[r1][c1] = '#';
			ret = max(ret, dfs(r2, c2) + 1);
			map[r1][c1] = 'B';
		}
	}

	return ret;
}

int main(){
	cin >> T;

	getline(cin, map[0]);

	while (T--){
		int i, j, ans = 0;

		getline(cin, map[0]);
		for (i = 0; i < 10; i++)
			getline(cin, map[i]);

		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++)
				if (map[i][j] == 'W'){
					map[i][j] = '#';
					ans = max(ans, dfs(i,j));
					map[i][j] = 'W';
				}

		cout << ans << endl;
	}
}
