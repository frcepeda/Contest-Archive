#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int N;
map<ll,int> m;

int main(){
	cin >> N;

	while (N--){
		char t[10];
		ll x;

		cin >> t >> x;

		ll z = 0;
		for (int i = 0; i < 18; i++){
			z = (z * 2) + (x % 2);
			x /= 10;
		}

		if (t[0] == '+'){
			m[z]++;
		} else if (t[0] == '-'){
			m[z]--;
		} else {
			cout << m[z] << endl;
		}
	}
}
