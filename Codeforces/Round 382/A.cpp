#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxk = 100;
ll n, f[maxk];

int main(){
	cin >> n;

	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i < maxk; i++)
		f[i] = f[i-1] + f[i-2];

	int i;
	for (i = 1; f[i] <= n; i++);

	cout << i-1 << endl;
}
