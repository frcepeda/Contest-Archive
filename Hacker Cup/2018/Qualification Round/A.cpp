#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T, K, N;
long long V;

int main(){
	cin >> T;

	vector<string> v;

	for (int t = 1; t <= T; t++){
		cout << "Case #" << t << ":";

		cin >> N >> K >> V;

		v.clear();
		v.resize(N);

		for (int i = 0; i < N; i++)
			cin >> v[i];

		vector<pair<int,string>> vv;

		for (int i = 0; i < K; i++){
			int j = (K*(V-1)+i) % N;
			vv.emplace_back(j, v[j]);
		}

		sort(vv.begin(), vv.end());

		for (int i = 0; i < K; i++)
			cout << ' ' << vv[i].second;

		cout << "\n";
	}
}
