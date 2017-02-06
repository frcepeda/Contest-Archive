#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class AlphabetOrderDiv1 {
	bool adj[26][26];
	int v[26];

	bool dfs(int x){
		if (v[x] == 2) return false;
		if (v[x] == 1) return true;

		v[x] = 2;

		for (int i = 0; i < 26; i++){
			if (!adj[x][i]) continue;
			if (!dfs(i)) return false;
		}

		v[x] = 1;
		return true;
	}

public:
	string isOrdered(vector<string> s){
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < 26; j++)
				adj[i][j] = false;
			v[i] = 0;
		}

		for (int i = 0; i < s.size(); i++){
			for (int j = 0; j < s[i].size(); j++){
				for (int k = j+1; k < s[i].size(); k++)
					if (s[i][j] != s[i][k])
						adj[s[i][j]-'a'][s[i][k]-'a'] = true;
			}
		}

		bool works = true;

		for (int i = 0; i < 26; i++)
			works &= dfs(i);

		return works ? "Possible" : "Impossible";
	}
};

#ifdef LOCAL
int main(){
	AlphabetOrderDiv1 a;
	printf("%s\n", a.isOrdered({"single","round","match"}).c_str());
}
#endif
