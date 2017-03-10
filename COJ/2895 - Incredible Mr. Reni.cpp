#include <iostream>
#include <algorithm>

using namespace std;

#ifndef LOL
typedef __int128 ll;
#else
typedef long long ll;
#endif

ll A, B, P, ans, ac;

int main(){
	int i, j;
	long long a, b, p;

	while (cin >> a >> b >> p){
		A = a; B = b; P = p;
		ac = p;

		ans = 0;

		for (j = 1; ac <= B; ac *= P)
			ans = ans + (B/ac) - (A - 1)/ac;

		cout << oct << (long long)(ans) << endl;
	}
}
