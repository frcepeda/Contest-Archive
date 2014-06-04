// Accepted
#include <iostream>
#include <set>

#define MAXN 110

using namespace std;

int T, N;
string recording[MAXN];
string foxsay = "what does the fox say?";
string ans;
set<string> animals;

int main(){
	string temp;
	cin >> T;

	getline(cin, temp);
	while (T--){
		int i, j;
		animals.clear();
		ans = "";

		getline(cin, temp);

		for (N = i = j = 0; i <= temp.length(); j++){
			if (i+j == temp.length() || temp[i+j] == ' '){
				recording[N++] = temp.substr(i, j);
				i = i + j + 1;
				j = 0;
			}
		}

		while (getline(cin, temp), temp != foxsay){
			for (i = 0; temp[i] != ' '; i++);
			for (i++; temp[i] != ' '; i++);
			animals.insert(temp.substr(i+1, string::npos));
		}

		for (i = 0; i < N; i++)
			if (animals.find(recording[i]) == animals.end())
				ans += (ans != "" ? " " : "") + recording[i];

		cout << ans << endl;
	}
}
