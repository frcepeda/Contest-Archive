#include <iostream>
#include <algorithm>

using namespace std;

string a, b;

const int mod = 1000000007;
const int PI = 314159 + 1;

int main(){
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	long long ans = 0;
	int ones = 0, two = 1;
	for (int i = 0; i < 500000; i++){
		bool aone = i < a.size() ? a[i] == '1' : false;
		ones += i < b.size() ? b[i] == '1' : 0;
		ones -= i-PI >= 0 and i-PI < b.size() ? b[i-PI] == '1' : 0;

		long long count = aone ? PI - ones : ones;

		ans = (ans + two * count) % mod;

		two = 2 * two % mod;
	}

	cout << ans << endl;
}
