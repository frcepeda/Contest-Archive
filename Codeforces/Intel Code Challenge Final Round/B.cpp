#include <iostream>
#include <algorithm>

using namespace std;

int n, m, x[22][22];

bool works2(int a, int b, int *x){
	for (int i = 0; i < m; i++)
		for (int j = i; j < m; j++){
			swap(x[i], x[j]);
			swap(x[a], x[b]);
			if (is_sorted(x, x + m))
				return true;
			swap(x[a], x[b]);
			swap(x[i], x[j]);

			swap(x[a], x[b]);
			swap(x[i], x[j]);
			if (is_sorted(x, x + m))
				return true;
			swap(x[i], x[j]);
			swap(x[a], x[b]);
		}

	return false;
}

bool works(int a, int b){
	int t[22];

	for (int i = 0; i < n; i++){
		copy(x[i], x[i] + m, t);
		if (!works2(a, b, t)) return false;
	}

	return true;
}

bool go(){
	for (int i = 0; i < m; i++)
		for (int j = i; j < m; j++)
			if (works(i,j))
				return true;
	return false;
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> x[i][j];

	cout << (go() ? "YES" : "NO") << endl;
}
