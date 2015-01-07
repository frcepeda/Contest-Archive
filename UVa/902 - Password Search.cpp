#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
string str;
map<string,int> m;

int main(){
	while (cin >> N >> str){
		int i, j = 0;
		string ans;

		m.clear();

		for (i = N; i <= str.length(); i++)
			m[str.substr(i-N, N)]++;

		for (auto it = m.begin(); it != m.end(); it++)
			if (it->second > j){
				j = it->second;
				ans = it->first;
			}

		cout << ans << "\n";
	}
}
