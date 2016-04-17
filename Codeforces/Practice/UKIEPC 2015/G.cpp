#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

char dp[1010][610][10];
int m, u, d;
string n[10];
int c[10];
int a[10];

int readf(int z){
	double w;
	cin >> w;
	return z * w;
}

bool f(int i, int j, int k){
	if (i < 0 || j < 0) return false;
	if (k == d) return i == 0 && j == 0;
	if (dp[i][j][k]) return dp[i][j][k] == 2;
	dp[i][j][k] = 1 + (f(i - c[k], j - a[k], k) || f(i, j, k+1));
	return dp[i][j][k] == 2;
}

int main(){
	int i;

	m = readf(100);
	u = readf(30);
	cin >> d;

	for (i = 0; i < d; i++){
		string z;
		cin >> n[i] >> a[i] >> z;
		if (z == "1/1")
			a[i] *= 30;
		else if (z == "1/2")
			a[i] *= 15;
		else
			a[i] *= 10;
		c[i] = readf(100);
	}

	if (!f(m, u, 0))
		cout << "IMPOSSIBLE\n";
	else {
		for (int k = 0; k < d; k++){
			int acc;

			for (acc = 0; f(m - c[k], u - a[k], k); acc++){
				m -= c[k];
				u -= a[k];
			}

			if (acc)
				cout << n[k] << " " << acc << '\n';
		}

		assert(m == 0 && u == 0);
	}
}
