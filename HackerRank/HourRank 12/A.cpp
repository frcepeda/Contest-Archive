#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main(){
	string s;
	cin >> s;
	ll n, ans = 0;
	cin >> n;

	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'a'){
			ans += n/s.size() + (i < n % s.size());
		}
	}

	cout << ans << endl;
}
