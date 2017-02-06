#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll a, b, c, d;

ll sq(ll x){
	ll r;
	for (r = 0; r*(r-1)/2 < x; r++);
	return r;
}

int main(){
	cin >> a >> b >> c >> d;

	ll na = sq(a);
	ll nd = sq(d);

	if (b + c > 0){
		if (!na) na++;
		if (!nd) nd++;
	}

	if (a + b + c + d == 0){
		cout << "1" << endl;
		return 0;
	}

	if (na*(na-1)/2 != a || nd*(nd-1)/2 != d || na*nd != b + c){
		cout << "Impossible" << endl;
		return 0;
	}

	for (; nd && c >= na; nd--, c -= na)
		cout << '1';

	for (; na && c < na; na--)
		cout << '0';

	if (nd--) cout << '1';

	for (; na > 0; na--)
		cout << '0';

	for (; nd > 0; nd--)
		cout << '1';

	cout << endl;
}
