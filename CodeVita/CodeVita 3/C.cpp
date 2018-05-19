#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

const int maxn = 26;
bool adj[maxn][maxn];

int main(){
	string tmp;

	char c;

	cin >> N;
	cin >> c;
	cin >> K;

	getline(cin, tmp);

	for (int i = 0; i < K; i++){
		vector<int> v;

		getline(cin, tmp);

		for (unsigned j = 0; j < tmp.size(); j++)
			if (isalpha(tmp[j]))
				v.push_back(tmp[j] - 'A');

		for (unsigned j = 0; j+1 < v.size(); j++)
			adj[v[j]][v[j+1]] = true;
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				adj[i][j] |= adj[i][k] && adj[k][j];

	vector<int> ans;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (i != j && !adj[i][j] && !adj[j][i]){
				ans.push_back(i);
				break;
			}

	if (ans.size() == 0)
		cout << "N/A" << endl;
	else {
		for (unsigned i = 0; i < ans.size(); i++)
			cout << char(ans[i] + 'A') << (i+1 < ans.size() ? ',' : '\n');
	}
}
