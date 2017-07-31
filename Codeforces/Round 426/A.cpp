#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll a, b;

vector<ll> cubes;

bool iscube(ll x){
	ll c = round(cbrt((long double)x));

	return c*c*c == x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> a >> b;

		bool works;

		ll aa = a*a;
		ll bb = b*b;

		works = aa % b == 0 && bb % a == 0 && iscube(aa / b) && iscube(bb / a);

		cout << (works ? "Yes" : "No") << "\n";
	}
}
