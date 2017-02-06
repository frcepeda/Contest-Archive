#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long double ld;

int T;

int main(){
	cin >> T;

	cout << setprecision(9) << fixed;

	while (T--){
		string n, top;

		cin >> n;
		top = n;
		sort(top.rbegin(), top.rend());

		if (n == top){
			cout << 0.0 << endl;
			continue;
		}

		long long K = 1;
		for (int i = 1; i <= n.size(); i++)
			K *= i;

		ld d = ld(1) / K;
		ld dp = d;

		prev_permutation(top.begin(), top.end());

		while (n != top){
			prev_permutation(top.begin(), top.end());
			dp = dp * (d + 1);
		}

		cout << dp << endl;
	}
}
